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
#include "frontend.h"
#include "backend.h"


class middleware {
    public:
        frontend* thefrontofthismidware;
        backend* theendofthismidware;
        server aserver;
        void setBackend(backend* abackend){
            theendofthismidware = abackend;
        }
        void setFrontend(frontend* afrontend){
            thefrontofthismidware = afrontend;
        }

        void requestRead(){
            //
            string temp = aserver.run();
            cout << temp << endl << endl;
            processRequest(temp[0]);
        }
        void processRequest(char _request){
            //TODO
            switch ( _request ) {
                case '10' :
                    cout << "A request";
            }

        }
        void start(){
            //starts server connection (server.h)
            thefrontofthismidware->start();
            requestRead();
        }
        void end(){
            thefrontofthismidware->end();
            requestRead();
        }
};

#endif