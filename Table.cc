#include "Table.h"

using namespace std;

Table::Table(int n, int c){
	number =  n;
	capacity = c;
}

int Table::getNum(){
	return number;
}

int Table::getCap(){
	return capacity;
}
