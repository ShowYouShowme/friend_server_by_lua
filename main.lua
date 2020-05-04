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

    return 1024
end