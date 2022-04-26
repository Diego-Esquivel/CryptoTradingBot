/********************************************************************************************************************************************
 *  Author: Diego G Esquivel & Eric D Smith
 *  CSCE306 Spring 2022 - Object Oriented Software Development
 *  Portfolio Project v.0.1: - esquivel_diego_labfinal.cpp, <iostream>, <string>, <array>
 *  Code Summary: This source code file demonstrates our class learned materail.
 * *****************************************************************************************************************************************/
#ifndef FRONTEND_H
#define FRONTEND_H 
#include <iostream>
#include <string>
using namespace std;

class frontend {
    public:
    void start(){
        char* cmd = "start cryptoBot\\cryptoBot.html";
        system(cmd);
    }
    void end () {
        char* cmd = "start cryptoBot\\cryptoBot2.html";
        system(cmd);
    }

    void addData(string _data){
        //TODO
    }
};

#endif