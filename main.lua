json = require "json"
print("Hello from lua!")



info = json.decode('{"name":"nash", "age": 28}')
print(info["name"])

function checkBeenFriend( uid, friend_uid )
    local result = query("select * from tb_friend where uid = " .. uid .. " and friend_uid = " .. friend_uid)
    Log("result : " .. result)

    local records = json.decode(result)
    if #records ~= 1 then
        Log(uid .. " and " .. friend_uid .. " are not friends")
        return false
    else
        local relationship = tonumber(records[1]["relationship"])
        if relationship == 3 then
            return true
        else
            return false
        end
    end
end

function CheckBeenApply(uid, friend_uid)
    local result = query("select * from tb_friend where uid = " .. uid .. " and friend_uid = " .. friend_uid)
    Log("result : " .. result)

    local records = json.decode(result)
    if #records ~=1 then
        return false
    else
        local relationship = tonumber(records[1]["relationship"])
        if relationship == 1 then
            return true
        else
            return false
        end
    end
end

-- 多次插入数据会报错
-- 错误信息: Commands out of sync; you can't run this command now
-- 原因
-- 1:未将MYSQL_RES所指对象释放，即在下次查询时要mysql_free_result();
-- 2:结果result集不为空，这个原因比较隐蔽
function InsertFriendEntry(uid, friend_uid, relationship)
    local sql = string.format("insert tb_friend (uid, friend_uid, relationship) values(%d,%d,%d)", uid, friend_uid,relationship)
    local result = insert(sql)
    Log("result : " .. result)
    return 0
end


function AddFriend(uid, friend_uid)
    if uid == friend_uid then
        Log("can not add yourself!")
        return -100
    end

    -- 检查是否为好友
    if checkBeenFriend(uid, friend_uid) == true then
        return 0
    end
    -- 这里应该返回两个值,一个是错误码,一个是返回值

    -- 检查是否已经申请
    local hasBeenApply = checkBeenFriend(uid, friend_uid)
    if(hasBeenApply == false) then
        local E_APPLICANT   = 0
        local E_BE_APPLIED  = 1
        InsertFriendEntry(uid, friend_uid, E_APPLICANT)
        InsertFriendEntry(friend_uid, uid, E_BE_APPLIED)
    end
    return 0
end

function UpdateFriendEntry(uid, friend_uid, relationship)
    local sql = string.format("update tb_friend set relationship = %d where uid = %d and friend_uid = %d", relationship, uid, friend_uid)
    local result = update(sql)
    Log("result : " .. result)
    return 0    
end

function DeleteFriend(uid, friend_uid)
    local E_DELETE = 4
    UpdateFriendEntry(uid, friend_uid, E_DELETE)
    UpdateFriendEntry(friend_uid, uid, E_DELETE)
    return 0
end