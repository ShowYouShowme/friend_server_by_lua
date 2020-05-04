json = require "json"
print("Hello from lua!")



info = json.decode('{"name":"nash", "age": 28}')
print(info["name"])


function AddFriend(uid, friend_uid)
    Log("log from lua!")

    local result = query("select * from tb_friend")
    Log("result : " .. result)
    return 1024
end