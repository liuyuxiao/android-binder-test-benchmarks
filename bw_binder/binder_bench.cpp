char  *id = "$Id$\n";
#include "../lib/bench.h"

#include <binder/IPCThreadState.h>
#include <binder/ProcessState.h>
#include <binder/IServiceManager.h>
#include <utils/Log.h>

#include "Serverlfeng.h"
using namespace android;


typedef struct _state {
    sp<IServerlfeng> proxy;
    uint64  move;
    size_t  msize;
    char  *buf;
} state_t;

void  server_main();
void  client_main(int parallel, state_t *state);

void  initialize(iter_t iterations, void* cookie);
void  loop_transfer(iter_t iterations, void *cookie);
void  cleanup(iter_t iterations, void* cookie);

int
main(int ac, char **av)
{
    int parallel = 1;
    int warmup = LONGER;
    int repetitions = -1;
    int shutdown = 0;
    state_t state;
    char buf[256];
    char  *usage = "-s\n OR [-m <message size>] [-M <bytes to move>] [-P <parallelism>] [-W <warmup>] [-N <repetitions>]\n";
    int c;

    state.msize = 0;
    state.move = 0;

    /* Rest is client argument processing */
    while (( c = getopt(ac, av, "sm:M:P:W:N:")) != EOF) {
        switch(c) {
        case 's': /* Server */
            if (fork() == 0) {
                server_main();
            }
            exit(0);
            break;
        case 'm':
            state.msize = bytes(optarg);
            break;
        case 'M':
            state.move = bytes(optarg);
            break;
        case 'P':
            parallel = atoi(optarg);
            if (parallel <= 0) lmbench_usage(ac, av, usage);
            break;
        case 'W':
            warmup = atoi(optarg);
            break;
        case 'N':
            repetitions = atoi(optarg);
            break;
        default:
            lmbench_usage(ac, av, usage);
            break;
        }
    }

    if (optind != ac) {
        lmbench_usage(ac, av, usage);
    }


    if (state.msize == 0 && state.move == 0) {
        state.msize = state.move = XFERSIZE;
    } else if (state.msize == 0) {
        state.msize = state.move;
    } else if (state.move == 0) {
        state.move = state.msize;
    }

    /* make the number of bytes to move a multiple of the message size */
    if (state.move % state.msize) {
        state.move += state.msize - state.move % state.msize;
    }

    benchmp(initialize, loop_transfer, cleanup,
            0, parallel, warmup, repetitions, &state);

    sprintf(buf, "Binder (data len =%d): ",state.move);
    micro(buf, get_n());

    if (gettime() > 0) {
        mb(state.move * get_n() * parallel);
    }
    return(0);
}

void
initialize(iter_t iterations, void *cookie)
{
    state_t *state = (state_t *) cookie;

    if (iterations) return;

    state->buf = (char*)valloc(state->msize);
    if (!state->buf) {
        perror("valloc");
        exit(1);
    }
    touch(state->buf, state->msize);

    //state->sock = tcp_connect(state->server, TCP_DATA, SOCKOPT_READ|SOCKOPT_WRITE|SOCKOPT_REUSE);

    //sp<IServiceManager> sm =
    sp<IBinder> bp = defaultServiceManager()->getService(String16("server_lfeng"));
    state->proxy=IServerlfeng::asInterface(bp);
}

void
loop_transfer(iter_t iterations, void *cookie)
{
    state_t *state = (state_t *) cookie;

    while (iterations-- > 0) {
        //const char* reply =
        int total = state->move;
        while(total>0) {
            state->proxy->echo(state->buf,state->msize);
            total-=state->msize;
        }
        /*
        printf("strlen(reply)=%d\n",strlen(reply));
        printf("reply+len-5=%s\n", (reply+state->msize - 5) );
        */
    }
}

void
cleanup(iter_t iterations, void* cookie)
{
    state_t *state = (state_t *) cookie;

    if (iterations) return;
    if(state->buf)
        free(state->buf);
}

void
server_main()
{
    sp<ProcessState> proc(ProcessState::self());
    sp<IServiceManager> sm = defaultServiceManager();
    sm->addService(String16("server_lfeng"),new Serverlfeng());
    ProcessState::self()->startThreadPool();
    IPCThreadState::self()->joinThreadPool();
}
