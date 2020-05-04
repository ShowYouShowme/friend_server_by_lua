#include "FriendsServantImp.h"
#include "servant/Application.h"

using namespace std;

//////////////////////////////////////////////////////
void FriendsServantImp::initialize()
{
    //initialize servant here:
    //...
}

//////////////////////////////////////////////////////
void FriendsServantImp::destroy()
{
    //destroy servant here:
    //...
}


tars::Int32 FriendsServantImp::AddFriend(const Friends::AddFriendReq& req, Friends::AddFriendResp& resp, tars::TarsCurrentPtr current)
{
    return 0;
}
tars::Int32 FriendsServantImp::DeleteFriend(const Friends::DeleteFriendReq& req, Friends::DeleteFriendResp& resp, tars::TarsCurrentPtr current)
{
    return 0;
}
tars::Int32 FriendsServantImp::QueryFriends(const Friends::QueryFriendListReq &req,Friends::QueryFriendListResp &resp,tars::TarsCurrentPtr current)
{
    return 0;
}
tars::Int32 FriendsServantImp::AgreeToAdd(const Friends::AgreeToAddReq & req,Friends::AgreeToAddResp &resp,tars::TarsCurrentPtr current)
{
    return 0;
}
tars::Int32 FriendsServantImp::GetApplicantList(const Friends::QueryApplicantListReq & req,Friends::QueryApplicantListResp &resp,tars::TarsCurrentPtr current)
{
    return 0;
}

