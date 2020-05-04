#ifndef _FriendsServer_H_
#define _FriendsServer_H_

#include <iostream>
#include "servant/Application.h"

using namespace tars;

/**
 *
 **/
class FriendsServer : public Application
{
public:
    /**
     *
     **/
    virtual ~FriendsServer() {};

    /**
     *
     **/
    virtual void initialize();

    /**
     *
     **/
    virtual void destroyApp();
};

extern FriendsServer g_app;

////////////////////////////////////////////
#endif
