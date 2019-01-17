#include "random.h"
#include "node.h"
#include "globals.h"

using namespace std;  

int choose(){
	srand(time(0)); 
	 return rand()%stocks.stockVector.size();
}
 double randomPercentage(){
	 srand(time(0)); 
	 return (rand()%10 + 1) *.01; 
 }
 int randNumberofStocks(){
	 srand(time(0)); 
	 return rand()%100 +1 ;  
 }