json = require "json"
print("Hello from lua!")



info = json.decode('{"name":"nash", "age": 28}')
print(info["name"])


function AddFriend(uid, friend_uid)
    Log("log from lua!")

    -- 这里应该返回两个值,一个是错误码,一个是返回值
    local result = query("select * from tb_friend where uid = " .. uid .. " and friend_uid = " .. friend_uid)
    Log("result : " .. result)

    local records = json.decode(result)
    if #records ~= 1 then
        Log(uid .. " and " .. friend_uid .. " are not friends")
    else
        local relationship = records[1]["relationship"]
        local _uid = records[1]["uid"]
        local _friend_uid = records[1]["friend_uid"]
        Log("===> relationship : " .. relationship .. " uid : " .. _uid .. " friend_uid : " .. _friend_uid)
        if relationship == 1 then
            Log("++++=1")
        elseif relationship == "1" then
            Log("]]]]]]]]]")
        end
    end
    return 1024
end