#ifndef threadFunc_h
#define threadFunc_h
#include <unistd.h> // sleep
#include <iomanip> // set percision
#include "cs.h"
#include "random.h"

//functions being used 
void *buy(void *arg);
void *sell(void * arg);
void *server (void * arg);
void processTrans(string trans); 

#endif