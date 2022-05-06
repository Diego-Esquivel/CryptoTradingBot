/********************************************************************************************************************************************
 *  Author: Diego G Esquivel & Eric D Smith
 *  CSCE306 Spring 2022 - Object Oriented Software Development
 *  Portfolio Project v.0.1: - esquivel_diego_labfinal.cpp, <iostream>, <string>, <array>
 *  Code Summary: This source code file demonstrates our class learned materail.
 * *****************************************************************************************************************************************/
#ifndef FRONTEND_H
#define FRONTEND_H 
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int coin_count = 0;
class frontend {
    public:
    void start(){
        char* cmd = "start cryptoBot\\cryptoBot.html";
        system(cmd);
    }
    void end () {
        if(coin_count % 3 == 0)
            addData("Sell that coin");
        else
            addData("Keep that coin");
        coin_count++;
        char* cmd = "start cryptoBot\\cryptoBot2.html";
        system(cmd);
    }

    void addData(string _data){
        //TODO
        string save_file_name = "cryptoBot/cryptoBot2.html";
        ofstream out_file;
        out_file.open(save_file_name);
        ifstream in_file1("cryptoBot/cryptoBot2top.html");
        ifstream in_file2("cryptoBot/cryptoBot2bot.html");
        string thisline;
        while(getline(in_file1,thisline)){
            out_file << thisline;
        }
        out_file << _data << endl;
        while(getline(in_file2,thisline)){
            out_file << thisline;
        }
        in_file1.close();
        in_file2.close();
        out_file.close();
    }
};

#endif