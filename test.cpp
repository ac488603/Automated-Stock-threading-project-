#include <iostream>
#include <string>
#include <thread>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;
ifstream ifs;

class stockInfo{
	string symbol; 
	double costPerShare;
	int numofShares;  
	vector<double> priceList;
	
	//make vector get/set
	public:
	stockInfo() {symbol = " "; costPerShare = 0; numofShares = 0; }
	void setSymbol(string symbol){this->symbol = symbol;}
	void setCost(double cost){
	if(cost == 0){
		costPerShare = 0; return;  
	}
	costPerShare = costPerShare + cost; 
	}
	void setShares(int shares) {
	if(shares == 0){
		numofShares = 0; return;  
	}
	numofShares = numofShares + shares;
	}
	string getSymbol(){return symbol;}
	double getCost(){return costPerShare;}
	int getShares(){return numofShares; }
	void addElement(double price){ priceList.push_back(price); }
	void updatePriceList(){ priceList.erase(priceList.begin()+0 );}
	vector<double> getpriceList(){return priceList;}
	void updateCost(double d){costPerShare = d; }
};
  
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
		p >> setprecision(10) >> showpoint >> price;  
		temp.addElement(price);  // add element to the list  
	}	
		stockArray.push_back(temp); //  add the stock to the array of stocks
	}
	}

int main(int argc,  char ** argv) 
{	
	std::vector<stockInfo> stock;
	
	ifs.open(argv[1]); 
	loadArray(stock); 
	ifs.close();
	
	for (int i =0;  i < stock.size(); i++)
	{
		for(int j =0;  j < stock[i].getpriceList().size(); j++)
		cout << stock[i].getpriceList()[j] << endl;
	}
    return 0;
}