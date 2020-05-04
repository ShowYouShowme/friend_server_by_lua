#ifndef _FriendsServantImp_H_
#define _FriendsServantImp_H_

#include "servant/Application.h"
#include "FriendsServant.h"
#include <util/tc_mysql.h>
#include "LogComm.h"
extern "C" 
{
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
}
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
    virtual tars::Int32 AddFriend(const Friends::AddFriendReq& req, Friends::AddFriendResp& resp, tars::TarsCurrentPtr current);
    virtual tars::Int32 DeleteFriend(const Friends::DeleteFriendReq& req, Friends::DeleteFriendResp& resp, tars::TarsCurrentPtr current);
    virtual tars::Int32 QueryFriends(const Friends::QueryFriendListReq &req,Friends::QueryFriendListResp &resp,tars::TarsCurrentPtr current);
    virtual tars::Int32 AgreeToAdd(const Friends::AgreeToAddReq & req,Friends::AgreeToAddResp &resp,tars::TarsCurrentPtr current);
    virtual tars::Int32 GetApplicantList(const Friends::QueryApplicantListReq & req,Friends::QueryApplicantListResp &resp,tars::TarsCurrentPtr current);

public:
    TC_Mysql m_mysqlObj; //mysql操作对象

    lua_State *m_pLua;
};

/////////////////////////////////////////////////////
#endif
