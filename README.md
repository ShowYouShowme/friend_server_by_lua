## 部署

***

1. **lua.tar.gz**是lua的开发库
2. 把**json.lua**放到路径*/usr/local/lib/lua/5.1*
3. *makefile*指令
   + copylua：copy lua代码并且重启服务，重启服务使用curl命令调用tars_web后台。如果只修改lua代码，可以构建此目标，省去编译c++的时间。
   + copyall：重编c++代码并且copy c++可执行文件和lua代码到bin目录