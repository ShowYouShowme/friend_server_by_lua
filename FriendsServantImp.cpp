#include "FriendsServantImp.h"
#include "servant/Application.h"

using namespace std;

//////////////////////////////////////////////////////

namespace{
    // 读取配置文件
	void readMysql(TC_Mysql& conn, const string& strSQL, vector<map<string, string>>& records)
	{
		//sql语句
		ROLLLOG_DEBUG << "sql: " << strSQL << endl;
		//查询数据
		TC_Mysql::MysqlData res = conn.queryRecord(strSQL);
		ROLLLOG_DEBUG << "Execute SQL: [" << strSQL << "], return " << res.size() << " records." << endl;
		//无数据
		if (res.size() <= 0)
		{
			ROLLLOG_WARN << " no data." << endl;
			return ;
		}
		records = res.data();
	}
}
void FriendsServantImp::initialize()
{
    //initialize servant here:
    //...
    try
	{		
		//for test
		map<string, string> mpParam;

		mpParam["dbhost"]  = "127.0.0.1";
		mpParam["dbuser"]  = "tars";
		mpParam["dbpass"]  = "tars2015";
		mpParam["dbname"]  = "hp_friend";
		mpParam["charset"] = "utf8";
		mpParam["dbport"]  = "3306";

		TC_DBConf dbConf;
		dbConf.loadFromMap(mpParam);

		//初始化数据库连接
		m_mysqlObj.init(dbConf);
	}
	catch (exception& e)
	{
		ROLLLOG_ERROR << "Catch exception: " << e.what() << endl;
	}

    // 加载lua脚本
    m_pLua = lua_open();
    luaopen_base(m_pLua);//打开基本库
    luaopen_table(m_pLua);
    luaL_openlibs(m_pLua);
    luaL_loadfile(m_pLua, (ServerConfig::BasePath + "main.lua").c_str());//载入文件
    int ret = lua_pcall(m_pLua, 
        0,//参数个数 
        0, //返回值个数
        0);//错误函数
    if(ret != 0){ 
        printf("lua_pcall failed %s\n", lua_tostring(m_pLua, -1));
    }
}

//////////////////////////////////////////////////////
void FriendsServantImp::destroy()
{
    //destroy servant here:
    //...
}

// 如何传参[int, number, string, bool 如何传入] 如何从lua获取返回值
tars::Int32 FriendsServantImp::AddFriend(const Friends::AddFriendReq& req, Friends::AddFriendResp& resp, tars::TarsCurrentPtr current)
{
    ROLLLOG_ERROR << "----top is " << lua_gettop(m_pLua) << endl;
    lua_getglobal(m_pLua, "AddFriend");
    lua_pushinteger(m_pLua, req.uid);
    lua_pushinteger(m_pLua,req.friend_uid);
    int ret = lua_pcall(m_pLua,
                   2,//参数个数
                   0,//返回值个数
                   0);//错误处理函数在栈中的位置
    ROLLLOG_DEBUG << "ret : " << ret << endl;
    ROLLLOG_ERROR << "++++top is " << lua_gettop(m_pLua) << endl;;//检查堆栈情况
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

