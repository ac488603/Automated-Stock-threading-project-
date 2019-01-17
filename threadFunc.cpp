#include<string>
#include <vector>
#include <sstream>
#include <pthread.h>
#include <iostream>

#include "threadFunc.h"
#include "globals.h"

using namespace std;  

pthread_mutex_t mutexProcess;
pthread_mutex_t buyLock;
pthread_mutex_t sellLock;

void *server (void * arg){
	node *temp;
	temp = (node *) arg; 
	sleep(3); 
	cout << "Balance:"<<setprecision(2) << fixed << temp -> balance << endl;  
	temp -> yield = temp -> profit/ temp-> Tcost;
	cout << "Yield: " << setprecision(4) << temp -> yield *100 << "%" << endl;
	cout << "numTrans:"<<numTrans << endl; 
	pthread_exit(NULL);
}

void *buy(void *arg){
	pthread_mutex_lock (&buyLock);
	node *temp;
	temp = (node *) arg; 
	string numShare, costShare;   
	int stock = choose(); int rnumshare = randNumberofStocks();
	stringstream ss;
	ss << rnumshare; 
	ss >> numShare; 
	stringstream ss1;
	ss1 << setprecision(2) << fixed << temp->stockVector[stock].getpriceList()[0];
	ss1 >> setprecision(2) >> fixed >> costShare;
	string transaction = "Buy "+ temp->stockVector[stock].getSymbol() + ' ' + numShare  + ' ' + costShare; 
	processTrans(transaction);
	pthread_mutex_unlock (&buyLock);
	sleep(4); 
	pthread_exit(NULL);
}

//only pass in object because we know which stock we have decided to purchase
void *sell(void *arg){
	pthread_mutex_lock (&sellLock);
	stockInfo *temp; 
	temp = (stockInfo *) arg;  
	stringstream ss,ss1;
	string numShare, priceShare;
	ss1 << setprecision(2) << fixed << temp->getpriceList()[0];
	ss1 >>  setprecision(2) >> fixed >> priceShare;
	ss << temp->getShares(); ss >> numShare; // convert int to string   
	string transaction =  "Sell "+ temp->getSymbol() + ' ' + numShare + ' ' + priceShare;  
	processTrans(transaction);
	pthread_mutex_unlock (&sellLock);
	sleep(4);
	pthread_exit(NULL);
}

void processTrans(string trans)
{
	string action, symbol, numberofStocks, costofStock;  
	int numberstock;
	double costStock;  
	stringstream ss(trans);  
	getline(ss,action, ' ');
	getline(ss,symbol, ' ');
	getline(ss,numberofStocks, ' ');
	getline(ss, costofStock, ' '); 
	ss.str(""); 
	ss << numberofStocks;
	ss >> numberstock;
	stringstream ss1(costofStock);
	ss1 >>  setprecision(2) >> fixed >> costStock; 
	
	////get stock index
	int index;
	for (int i = 0; i < stocks.stockVector.size(); i++)
	{
	if(symbol == stocks.stockVector[i].getSymbol())
	{
			index = i;
			break;  
	}
	}
	// transaction lock 
	pthread_mutex_lock (&mutexProcess);
	cout << trans << endl; 
	if(action == "Buy")
	{ 
		stocks.stockVector[index].setShares(numberstock); 
		stocks.stockVector[index].updateCost(costStock);  // how much that cost per stock
		stocks.balance = (stocks.balance - (numberstock * costStock));  // losing money
		stocks.Tcost   = (stocks.Tcost + (numberstock * costStock));  // total spent to far
		stocks.stockVector[index].updatePriceList();      
	}
	else if(action == "Sell")
	{
		stocks.profit = stocks.profit + ((numberstock * costStock) - (numberstock * stocks.stockVector[index].getCost()));
		stocks.balance = stocks.balance + (numberstock * costStock);
		stocks.stockVector[index].setShares(0);      // sell all shares 
		stocks.stockVector[index].updateCost(0); 
		stocks.stockVector[index].updatePriceList();
	}
	 pthread_mutex_unlock (&mutexProcess); 
}


