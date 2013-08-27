#define LOG_NDEBUG 0  //打开调试

#define LOG_TAG "Serverlfeng"
#include <utils/Log.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <assert.h>

#include <string.h>

#include <cutils/atomic.h>
#include <cutils/properties.h> // for property_get

#include <utils/misc.h>

#include <android_runtime/ActivityManager.h>

#include <binder/IPCThreadState.h>
#include <binder/IServiceManager.h>
#include <binder/MemoryHeapBase.h>
#include <binder/MemoryBase.h>
#include <utils/Errors.h>  // for status_t
#include <utils/String8.h>
#include <utils/SystemClock.h>
#include <utils/Vector.h>
#include <cutils/properties.h>

#include "Serverlfeng.h"

namespace android
{

Serverlfeng::Serverlfeng()
{
    LOGD("Serverlfeng created!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
    printf("Serverlfeng created!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
}

const char* Serverlfeng::echo(char *buf,int len)
{
    //printf("Serverlfeng len=%fk!\n",len/1000.0);
    assert(len==strlen(buf)+1);
    /*
      double stop;
      struct timeval tv_stop;
      gettimeofday(&tv_stop,NULL);
      stop = tv_stop.tv_sec + tv_stop.tv_usec/1000000.0;
      return stop;
       */
    return buf;
}

//int Serverlfeng::add(int a,int b,int s,int us,int childpid)
int Serverlfeng::add(int a,int b)
{

    /*
      double clockus;
      struct timeval tv_stop;
      gettimeofday(&tv_stop,NULL);

      LOGD("Serverlfeng len=%d!!!!!!!!!!!!!!!!!!",len);
      printf("Serverlfeng len=%fk!!!!!!!!!!!!!!!!!!\n",len/1024.0);

      struct timeval tv_start;
      tv_start.tv_sec = (time_t)s;
      tv_start.tv_usec = (suseconds_t)us;
      //printf("tv_stop:%d.%d,tv_start:%d.%d\n",tv_stop.tv_sec,tv_stop.tv_usec,tv_start.tv_sec,tv_start.tv_usec);


      if( (tv_stop.tv_usec -= tv_start.tv_usec) < 0){
        --tv_stop.tv_sec;
        tv_stop.tv_usec +=1000000;
      }
      tv_stop.tv_sec -= tv_start.tv_sec;


      clockus = tv_stop.tv_sec * 1000000.0 + tv_stop.tv_usec;
      printf("clocks =%lfsec\n",clockus/1000000.0);
      printf("bandwidth: %.3f MB/sec\n",len / clockus);
      //buf[len-1]=0;
      //printf("strlen(buf)=%d,xx=%c\n",strlen(buf),buf[len-2]);
      //printf("value=%s\n",(char *)(buf+sizeof(struct timeval)));
      //kill(childpid,SIGTERM);
      */
    //printf("add...\n");
    return (a+b);
}

Serverlfeng::~Serverlfeng()
{
    LOGD("Serverlfeng destroy!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
    printf("Serverlfeng destroy!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
}

}
