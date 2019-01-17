#ifndef cd_h
#define cd_h

#include <chrono>
#include <vector>
#include <string>


using namespace std;
 
class stockInfo{
	string symbol; 
	double costPerShare;
	int numofShares;  
	vector<double> priceList;
	
	//make vector get/set
	public:
	stockInfo();
	void setSymbol(string symbol);
	void setCost(double cost);
	void setShares(int shares);
	string getSymbol();
	double getCost();
	int getShares();
	void addElement(double price);
	void updatePriceList();
	vector<double> getpriceList();
	void updateCost(double d);
};

#endif