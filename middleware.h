/********************************************************************************************************************************************
 *  Author: Diego G Esquivel & Eric D Smith
 *  CSCE306 Spring 2022 - Object Oriented Software Development
 *  Portfolio Project v.0.1: - middleware.h, <iostream>, <string>, <array>
 *  Code Summary: This code header file is the middleware. 
 * *****************************************************************************************************************************************/
#ifndef MIDDLEWARE_H
#define MIDDLEWARE_H
#include "CryptoBotDataObject.h"
#include "server.h"


class middleware {
    public:
        backend* theendofthismidware;
        server aserver;
        void setBackend(backend* abackend){
            theendofthismidware = abackend;
        }

        void requestRead(){
            //
            cout << aserver.run();
        }
        void processRequest(){

        }
        void start(){
            //starts server connection (server.h)
            requestRead();
        }
        void end(){

        }
};

#endif