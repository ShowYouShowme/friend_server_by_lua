json = require "json"
print("Hello from lua!")



info = json.decode('{"name":"nash", "age": 28}')
print(info["name"])


function AddFriend(uid, friend_uid)
    Log("log from lua!")

    query("select * from tb_friend")
    return 1024
end