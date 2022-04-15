/********************************************************************************************************************************************
 *  Author: Diego G Esquivel & Eric D Smith
 *  CSCE306 Spring 2022 - Object Oriented Software Development
 *  Portfolio Project v.0.1: - esquivel_diego_labfinal.cpp, <iostream>, <string>, <array>
 *  Code Summary: This source code file demonstrates our class learned materail.
 * *****************************************************************************************************************************************/
#include "backend.h"
#include <iostream>

using namespace std;

void download() {
    //function to download the data from https://coinmarketcap.com  https://www.worldcoinindex.com/coin/solana/historical    https://www.worldcoinindex.com/coin/dogecash/historical  https://www.worldcoinindex.com/coin/bitcoin/historical   https://www.worldcoinindex.com/coin/ethereum/historical  https://www.worldcoinindex.com/coin/polygon/historical      https://www.worldcoinindex.com/coin/apecoin/historical
    //download function is curl -o <coin>.json https://www.worldcoinindex.com/coin/<coin>/historical
    string coins[6] = {"https://www.coingecko.com/en/coins/solana/historical_data/usd#panel", "https://www.coingecko.com/en/coins/dogecash/historical_data/usd#panel", "https://www.coingecko.com/en/coins/bitcoin/historical_data/usd#panel", "https://www.coingecko.com/en/coins/ethereum/historical_data/usd#panel", "https://www.coingecko.com/en/coins/polygon/historical_data/usd#panel", "https://www.coingecko.com/en/coins/apecoin/historical_data/usd#panel"};
    string coinname[6] = {"solana", "dogecash", "bitcoin", "ethereum", "polygon", "apecoin"};

    for(int i = 0; i < 6; i ++){
        string& req = "curl -o data\\" + coinname[i] + ".json " + coins[i];
        system(req.c_str());
    }
}

int main ()
{
    //description of program
    /*
        Download all crypto data. 

        Sort data into JSON style form (70 history data values per coin of marketcap)
            "name": bitcoin
            {
                "date": date
                {
                    "data": int
                }
            }
        
        Calculate result_matrix

        Read result_matrix and output answer to front-end and db
    */
    download();
    backend one{};
    
   return 1;
}