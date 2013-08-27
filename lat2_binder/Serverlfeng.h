#ifndef __SERVERLFENG_H__
#define __SERVERLFENG_H__

#include <utils/Log.h>
#include <utils/threads.h>
#include <utils/List.h>
#include <utils/Errors.h>
#include <utils/KeyedVector.h>
#include <utils/String8.h>
#include <utils/Vector.h>

#include "IServerlfeng.h"

namespace android
{
class Serverlfeng : public BnServerlfeng
{
public:
    Serverlfeng();
    virtual const char* echo(char *buf,int len);
    //virtual int add(int a,int b,int s,int us,int childpid) ;
    virtual int add(int a,int b);
    virtual ~Serverlfeng();
};//end class


};


#endif
