json = require "json"
print("Hello from lua!")



info = json.decode('{"name":"nash", "age": 28}')
print(info["name"])


function AddFriend(uid, friend_uid)
    print("uid : " .. uid)
    return 1024
end