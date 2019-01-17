#include <iostream>
#include <string>
#include <pthread.h>
#include <thread>
#include <fstream>
#include <sstream>
#include <mutex>
#include <condition_variable>
#include "cs.h"

using namespace std;

void buy(vector<stockInfo> stocks, int tid ); // create buy string 
void sell(stockInfo temp, int tid); // create sell string 
void server(); // for server threads
int choose(); // random function
void loadArray(vector<stockInfo> &stockArray);// vector with all stock info
void processTrans(string trans, int tid);  // process string made by buy and sell 
int randNumberofStocks();
 double randomPercentage();

double balance = 1000000.0;
double yield = 0.0; 
double profit = 0.0; 
double Tcost = 0.0; 
int numTrans = 0; 
bool isBuy = true;  

thread t[10];  
int numthreads =0; 
	
ifstream ifs;
vector<stockInfo> stockVector;
///////////////////////////////////////////condition_variable
condition_variable buysellGo;
//////////////////////////////locks
mutex buysellMutex; 


/////////////////////////////////////////////////////main function //////////////////////////////////
int main(int argc, char **argv){ 
	ifs.open(argv[1]);
	loadArray(stockVector);
	ifs.close();	

	while(numTrans < 10000){
		
		if(isBuy){
			double r =  randomPercentage();
			if (r < z)
			{
			cout << "creatingBuyThread!" << endl;
			t[numthreads++] = thread(buy, stockVector, numthreads);
			numTrans++;
			}
			isBuy = false; 
		}
		else {
			int index = choose();
			int price = stockVector[index].getpriceList()[0];
			int cost = stockVector[index].getCost();
			if(price > ((1+x)*cost) || price < ((1-y)*cost))
			{
			t[numthreads++] = thread(sell, stockVector[index],numthreads);
			numTrans++; 
			}
		}
		  cout << numthreads << endl;
		isBuy = true; 
	}
}

struct node{
vector<stockInfo> stockVector; 
};
