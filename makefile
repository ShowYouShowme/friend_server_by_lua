
#-----------------------------------------------------------------------

APP       := XGame
TARGET    := FriendsServer
CONFIG    := 
STRIP_FLAG:= N
TARS2CPP_FLAG:= 

INCLUDE   += -I/usr/local/lua/include
LIB       += -L/usr/local/lua/lib -llua
LIB       += -ldl
LIB       += -L/usr/local/mysql/lib/mysql -lmysqlclient

#-----------------------------------------------------------------------

include /usr/local/tars/cpp/makefile/makefile.tars

#-----------------------------------------------------------------------


copy:
	cp -f ./FriendsServer /usr/local/app/tars/tarsnode/data/XGame.FriendsServer/bin/
	cp -f ./main.lua /usr/local/app/tars/tarsnode/data/XGame.FriendsServer/bin/
