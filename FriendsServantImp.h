#ifndef _FriendsServantImp_H_
#define _FriendsServantImp_H_

#include "servant/Application.h"
#include "FriendsServant.h"

/**
 *
 *
 */
class FriendsServantImp : public Friends::FriendsServant
{
public:
    /**
     *
     */
    virtual ~FriendsServantImp() {}

    /**
     *
     */
    virtual void initialize();

    /**
     *
     */
    virtual void destroy();

    /**
     *
     */
    virtual int test(tars::TarsCurrentPtr current) { return 0;};
};
/////////////////////////////////////////////////////
#endif
