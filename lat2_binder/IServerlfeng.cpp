#include <stdint.h>
#include <sys/types.h>

#include <binder/Parcel.h>
#include <binder/IMemory.h>

#include <utils/Errors.h>  // for status_t

#include "IServerlfeng.h"

namespace android
{

enum {
    ECHO = IBinder::FIRST_CALL_TRANSACTION,
    ADD =  IBinder::FIRST_CALL_TRANSACTION + 1,
};
class BpServerlfeng : public BpInterface<IServerlfeng>
{
public:
    BpServerlfeng(const sp<IBinder>& impl)
        : BpInterface<IServerlfeng>(impl) {
    }


    virtual const char* echo(char *buf,int len) {
        Parcel data,reply;

        //printf("data.data()=0x%x,data.dataSize()=%d,data.dataPosition()=%d,data.dataCapacity()=%d,writeInterfaceToken() %d\n",
        //  data.data(),	data.dataSize(),	data.dataPosition(),	data.dataCapacity(),
        //  (IServerlfeng::getInterfaceDescriptor()).size());

        data.writeInterfaceToken(IServerlfeng::getInterfaceDescriptor());

        // printf("writeCString(buf) %d\n",strlen(buf));
        data.writeCString(buf);

        //printf("writeInt32(len) %d\n",sizeof(len));
        data.writeInt32(len);
        //printf("begin transact----------\n");
        remote()->transact(ECHO, data, &reply);
        return reply.readCString();
    }

    //virtual int add(int a,int b,int s,int us,int childpid)
    virtual int add(int a,int b) {
        Parcel data, reply;
        data.writeInterfaceToken(IServerlfeng::getInterfaceDescriptor());
        data.writeInt32(a);
        data.writeInt32(b);
//        data.writeInt32(s);
//       data.writeInt32(us);
        //      data.writeInt32(childpid);

        remote()->transact(ADD, data, &reply);
        return reply.readInt32();
    }

};





IMPLEMENT_META_INTERFACE(Serverlfeng, "com.test.IServerlfeng");

// ----------------------------------------------------------------------

status_t BnServerlfeng::onTransact(
    uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags)
{
    switch(code) {
    case ECHO: {
        CHECK_INTERFACE(IServerlfeng, data, reply);
        char *buf=const_cast<char*>(data.readCString());
        int totalnbytes = data.readInt32();
        const char* ret=echo(buf,totalnbytes);
        reply->writeCString(ret);
        return NO_ERROR;
    }
    break;
    case ADD: {
        CHECK_INTERFACE(IServerlfeng, data, reply);

        int a = data.readInt32();
        int b = data.readInt32();
        //              int s=data.readInt32();
        //                int us = data.readInt32();
        //               int childpid = data.readInt32();
        //             int result = add(a,b,s,us,childpid);
        int result = add(a,b);

        reply->writeInt32(result);
        return NO_ERROR;
    }
    default:
        return BBinder::onTransact(code, data, reply, flags);
    }
}

}

