#include "FriendsServer.h"
#include "FriendsServantImp.h"

using namespace std;

FriendsServer g_app;

/////////////////////////////////////////////////////////////////
void
FriendsServer::initialize()
{
    //initialize application here:
    //...

    addServant<FriendsServantImp>(ServerConfig::Application + "." + ServerConfig::ServerName + ".FriendsServantObj");
}
/////////////////////////////////////////////////////////////////
void
FriendsServer::destroyApp()
{
    //destroy application here:
    //...
}
/////////////////////////////////////////////////////////////////
int
main(int argc, char* argv[])
{
    try
    {
        g_app.main(argc, argv);
        g_app.waitForShutdown();
    }
    catch (std::exception& e)
    {
        cerr << "std::exception:" << e.what() << std::endl;
    }
    catch (...)
    {
        cerr << "unknown exception." << std::endl;
    }
    return -1;
}
/////////////////////////////////////////////////////////////////
