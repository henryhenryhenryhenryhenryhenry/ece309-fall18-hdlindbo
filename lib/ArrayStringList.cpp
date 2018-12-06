#include <stdio.h>
#include <string.h>
#include <stdlib.h>

namespace ece309{
class ArrList{
	public:
	
	ArrList();
	~ArrList();
	char* get(int n);
	char* remove_front();
	int length();
	bool push_back(const char *str);
	bool is_there_a_problem();
	void fix_the_problem();
	
	private:
	int head;
	int tail;
	int max;
	char data[100][100];
};

bool ArrList::is_there_a_problem(){//finds out if the amount of data can no longer fit in the array
	if(tail >= 100){
		return true;
	}else{
		return false;
	}
}

void ArrList::fix_the_problem(){//fixes an excess of data by making a new array that is larger and 
	if(!is_there_a_problem()){//  copying everything into the new array
		return;
	}
	//max;
	char data2[max+100][100];
	for(int i = 0; i<max; i++){
		strcpy(data2[i],data[i]);
	}
	max+=100;
	return;
}

ArrList::ArrList(){
	head = 0;
	tail = head;
	max = 100;
}

ArrList::~ArrList(){
	//everything should automaticaly get destroyed because there are no pointers to anything on the heap
}

bool ArrList::push_back(const char *str){
	if(is_there_a_problem()){
		fix_the_problem();
	}
	
	
	strcpy(data[tail], str);
	printf("added %s\n", data[tail]);
	tail++;
	return true;
}

char* ArrList::get(int n){
	return data[n-1];
}

int ArrList::length(){
	return tail-head;
}

char* ArrList::remove_front(){
	char* tmp;
	tmp = data[head];
	head++;
	printf("the new head is %s\n", data[head]);
	return tmp;
}
}
	
int main(){
	using namespace ece309;
	
	ArrList L;
	L.push_back("milk");
	L.push_back("eggs");
	L.push_back("cheese");
	L.push_back("butter");
	
	printf("item #2 is %s\n", L.get(2) );
	printf("the list is %d items long\n", L.length());
	
	printf("we deleted %s\n", L.remove_front());
	printf("the list is %d items long\n", L.length());
	
	printf("\ndone\n");
	return 0;
}
