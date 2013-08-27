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
} state_t;

void  server_main();
void  client_main(int parallel, state_t *state);

void  initialize(iter_t iterations, void* cookie);
void  loop_transfer(iter_t iterations, void *cookie);
void  cleanup(iter_t iterations, void* cookie);

int main(int ac, char **av)
{
    int parallel = 1;
    int warmup = LONGER;
    int repetitions = -1;
    int shutdown = 0;
    state_t state;
    char buf[256];
    char  *usage = "-s\n OR [-P <parallelism>] [-W <warmup>] [-N <repetitions>]\n";
    int c;


    /* Rest is client argument processing */
    while (( c = getopt(ac, av, "sm:M:P:W:N:")) != EOF) {
        switch(c) {
        case 's': /* Server */
            if (fork() == 0) {
                server_main();
            }
            exit(0);
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



    benchmp(initialize, loop_transfer, cleanup,
            0, parallel, warmup, repetitions, &state);
    snprintf(buf,sizeof(buf),"binder latency");
    micro(buf, get_n());

    return(0);
}

void
initialize(iter_t iterations, void *cookie)
{
    state_t *state = (state_t *) cookie;

    if (iterations) return;

    sp<IBinder> bp = defaultServiceManager()->getService(String16("server_lfeng"));
    state->proxy=IServerlfeng::asInterface(bp);
}

void
loop_transfer(iter_t iterations, void *cookie)
{
    state_t *state = (state_t *) cookie;

    while (iterations-- > 0) {
        state->proxy->add(1,2);
        //assert(3 == state->proxy->add(1,2));
    }
}

void
cleanup(iter_t iterations, void* cookie)
{
    state_t *state = (state_t *) cookie;

    if (iterations) return;
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
