#include <fstream>
#include <sstream>
#include <cmath>
#include "cs.h"
#include "threadFunc.h"
#include "globals.h"
using namespace std; 

void loadArray(vector<stockInfo> &stockArray);
ifstream ifs; 
 
// stock vector
node stocks;
int numTrans = 0;
int main(int argc, char **argv){  
	ifs.open(argv[1]); 
	loadArray(stocks.stockVector); 
	ifs.close();
	
	
	int numthreads = 0; 
	pthread_t t[20000];
	
	bool isBuy = true;
	while(numTrans < 10000){
		sleep(1); 
		pthread_create(&t[numthreads++],NULL, &server, (void *) &stocks);
		if(isBuy){
			double r = randomPercentage();
			if (r < z)
			{
			pthread_create(&t[numthreads++], NULL,&buy, (void *) &stocks);
			numTrans++;
			}
			isBuy = false; 
		}
		else{
			int index = choose();
			int price = stocks.stockVector[index].getpriceList()[0]; //  price is first element in price list 
			int cost = stocks.stockVector[index].getCost();
			if(price > ((1+x)*cost) || price < ((1-y)*cost))
			{
			stockInfo temp = stocks.stockVector[index];
			pthread_create(&t[numthreads++], NULL, &sell, (void *) &temp);
			numTrans++; 
			}
			isBuy = true; 
		}
	}
	
	for(int i =0; i < numthreads; i++)
		pthread_join(t[i], NULL);
	
	return 0; 
}


// initializing array with list of prices 
void loadArray(vector<stockInfo> &stockArray){
	string symbol; // name of company 
	double  cps; // costPerShare
	
	while (!(ifs.eof())){
	ifs >> symbol; 
	stockInfo temp; 
	temp.setSymbol(symbol);  // set symbol of object 
	
	string prices; 
	if(!std::getline(ifs, prices)) // grab all prices associated with symbol
		break;
		
	stringstream ss(prices); // all prices loaded into stream 
	
	while(ss)  // while theres items in the stream
	{
		string temps; // conversion string 
		double price; //  price to be loaded 
		
		if(!std::getline(ss,temps,',')) // break if done parsing stream 
			break; 		
			
		stringstream p(temps);  //  convert string into double  
		p >> price;  
		temp.addElement(price);  // add element to the list  
	}	
		stockArray.push_back(temp); //  add the stock to the array of stocks
	}
	}
