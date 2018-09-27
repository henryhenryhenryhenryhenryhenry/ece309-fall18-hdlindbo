#include <stdio.h>
#include "Plist.cpp"
#include "PList.h"

int main(){
	
	StringItem *A = new StringItem("milk");
	IntItem *B = new IntItem(5);
	DoubleItem *C = new DoubleItem(4.2);
	
	PList l;
	l.append(StringItem("milk"),A);
	l.append(IntItem(5),B);
	l.append(DoubleItem(4.2),C);

	/* PList l;
	l.append(StringItem("milk"));
	l.append(IntItem(5));
	l.append(DoubleItem(4.2)); */
	
	
	PList::iterator it = l.begin();
    while(!it.end()){
		Item &copy = it.getItem();

		//copy.print();
		//it.getItem().print();
		it.itPrint();

		it.increment();
    }
	
	return 0;
}