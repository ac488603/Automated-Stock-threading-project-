#include "cs.h"
using namespace std;
 
	                 stockInfo::stockInfo() {symbol = " "; costPerShare = 0.0; numofShares = 0; }
	void             stockInfo::setSymbol(string symbol){this->symbol = symbol;}
	void             stockInfo::setCost(double cost){costPerShare = costPerShare + cost;}
	void             stockInfo::setShares(int shares) {numofShares = numofShares + shares;}
	string           stockInfo::getSymbol(){return symbol;}
	double           stockInfo::getCost(){return costPerShare;}
	int              stockInfo::getShares(){return numofShares; }
	void             stockInfo::addElement(double price){ priceList.push_back(price); }
	void             stockInfo::updatePriceList(){ priceList.erase(priceList.begin()+0 );}
	vector<double>   stockInfo::getpriceList(){return priceList;}
	void             stockInfo::updateCost(double d){costPerShare = d; }

	