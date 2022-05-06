/********************************************************************************************************************************************
 *  Author: Diego G Esquivel & Eric D Smith
 *  CSCE306 Spring 2022 - Object Oriented Software Development
 *  Portfolio Project v.0.1: - middleware.h, <iostream>, <string>, <array>
 *  Code Summary: This code header file is the middleware. 
 * *****************************************************************************************************************************************/
#ifndef CRYPTOBOTDATAOBJECT_H
#define CRYPTOBOTDATAOBJECT_H
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

class CryptoBotDataObject {
    public:
     stack<string> data;

// add function for cryptobot. the function utilizes the stack push() to add values into data.
     void add(CryptoBotDataObject _data){
         string value = _data.data.top();
         while(_data.data.empty() == false){
            data.push(value);
            _data.data.pop();
            value = _data.data.top();  
         }
     }

// index function for cryptobot. the function utilizes the stack size(), push(), pop(), and top() to find a value at index
     string index(int _index){
         stack<string> temp;

         if(data.size() < _index || _index < 0)
            return "Not valid index";

         for(int i = 0; i < _index; i++){
            temp.push(data.top());
            data.pop();
         }

         string return_value = data.top();

         while(!(data.empty())){
             temp.push(data.top());
             data.pop();
         } 

         while(!(temp.empty())){
             data.push(temp.top());
             temp.pop();
         }
         return return_value;
     }


// index function for cryptobot. the function utilizes the stack size(), push(), pop() and top() to find a value of index
     string index(string _index){
         stack<string> temp;

         if(data.top() != _index || data.empty())
            return "Not valid index";
        string topValue = data.top();
         while(topValue != _index && data.empty() == false){
             temp.push(data.top());
            data.pop();
            topValue = data.top();
         }

        string return_value;
        if(data.top() == _index)
            return_value = data.top();
        else
            return_value = "Not a valid key";

         while(!(data.empty())){
             temp.push(data.top());
             data.pop();
         } 

         while(!(temp.empty())){
             data.push(temp.top());
             temp.pop();
         }
         return return_value;
     }


// set function for cryptobot. the function utilizes the stack to set the value at index to anotherone.
     void set(string _index, string anotherone){
         stack<string> temp;
         string topValue;
         while(data.empty() == false){
                topValue = data.top();
                if(topValue == _index){
                    data.pop();
                    temp.push(anotherone);
                }
                else{
                    temp.push(data.top());
                    data.pop();
                }
         }
        while(temp.empty() == false){
            data.push(temp.top());
        }
     }

    void remove(string key){
        stack<string> temp;
         string topValue;
         while(data.empty() == false){
                topValue = data.top();
                if(topValue == key){
                    data.pop();
                }
                else{
                    temp.push(data.top());
                    data.pop();
                }
         }
        while(temp.empty() == false){
            data.push(temp.top());
        }
    }

};

#endif