#ifndef __ISERVERLFENG_H__
#define __ISERVERLFENG_H__

#include <utils/Errors.h>  // for status_t
#include <utils/KeyedVector.h>
#include <utils/RefBase.h>
#include <utils/String8.h>
#include <binder/IInterface.h>
#include <binder/Parcel.h>


namespace android
{


class IServerlfeng: public IInterface
{
public:
    DECLARE_META_INTERFACE(Serverlfeng);

    virtual const char* echo(char *buf,int len) = 0;
    //virtual int add(int a,int b,int s,int us,int childpid) = 0;
    virtual int add(int a,int b) = 0;
};

// ----------------------------------------------------------------------------

class BnServerlfeng: public BnInterface<IServerlfeng>
{
public:
    virtual status_t    onTransact( uint32_t code,
                                    const Parcel& data,
                                    Parcel* reply,
                                    uint32_t flags = 0);
};

//---------Just for client test,or should put in cpp to hide-------
}; // namespace android

#endif // __ISERVERLFENG_H__

