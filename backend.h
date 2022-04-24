/********************************************************************************************************************************************
 *  Author: Diego G Esquivel & Eric D Smith
 *  CSCE306 Spring 2022 - Object Oriented Software Development
 *  Portfolio Project v.0.1: - backend.h, <iostream>, <string>, <array>
 *  Code Summary: This code header file is the backend. The backend should be implemented using CRUD practices. All data can be CRUD using
 *      the CryptoBotDataObject for this project. 
 * 
 *      Create :
 *          - add all data to a CryptoBotDataObject instance
 *          - add CryptoBotDataObject from part 1 to data using the add class function.
 *      
 *      Read : 
 *          - know the index or (key,value) pair of the value to read.
 * 
 *      Update :
 *          - know the index or (key,value) pair of the value to update.
 * 
 *      Delete :
 *          know the index or (key,value) pair of the value to delete.
 * *****************************************************************************************************************************************/
#ifndef BACKEND_H
#define BACKEND_H
#include "CryptoBotDataObject.h"

 class backend {
     public:
    CryptoBotDataObject data;

    void add(CryptoBotDataObject _data){
        data.add(_data);
    }

    string read(int _index) {
        return data.index(_index);
    }

    string read(string key){
        return data.index(key);
    }

    void update(string _index, string newone){
        data.set(_index,newone);
    }

    void assimalate(string key){
        data.remove(key);
    }

 };

 #endif