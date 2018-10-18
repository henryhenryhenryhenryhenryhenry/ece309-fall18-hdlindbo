#include "IntegerSet.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

// can only hold positive integers
IntegerSetHT::IntegerSetHT(int htsize)
:IntegerSet(htsize)
{
   empty_since_start = -2;
   empty_after_removal = -1;
   probeDistance = 20;
   table = new int[size];
   for(int i=0; i<size; i++)
      table[i] = empty_since_start;  // -1 means empty
}

int IntegerSetHT::insert(int data)
{
  int index = hash(data);
  int bucketsProbed = 0;
  while( bucketsProbed++ < probeDistance )
  {
   if ( table[index] < 0 )
   {
     // if the entry is not being used, put the
    // data there
     table[ index ] = data;
     if(bucketsProbed < 2){
		return 1;//1 means inserted and not collisions
	 }else{
		return 0;//0 means inserted but collided
	 }
   }
   index = (index+1) % size;
  }
  // otherwise give up
   return -1;// -1 means failed to insert
}

bool IntegerSetHT::search(int data) const
{
  int index = hash(data);
  int bucketsProbed = 0;
  while( table[index] != empty_since_start &&
         bucketsProbed++ < probeDistance )
  {
   if ( table[index] == data )
   {
     return true;
   }
   index = (index+1) % size;
  }

  // data can only be in one location, check it
  return false;
}

void IntegerSetHT::remove(int data)
{
  int index = hash(data);
  int bucketsProbed = 0;
  while( table[index] != empty_since_start &&
         bucketsProbed++ < probeDistance )
  {
   if ( table[index] == data )
   {
     table[index] = empty_after_removal;
     //return;
   }
   index = (index+1) % size;
  }
}

/* //removed b/c i didn't feel like dealing with List
IntegerSetHTChain::IntegerSetHTChain(int htsize)
:IntegerSet(htsize)
{
  table = new List[size];
}

bool IntegerSetHTChain::insert(int data)
{
  List::iterator it;
  table[hash(data)].insertAfter(it,data);
  return true;
}

bool IntegerSetHTChain::search(int data) const
{
   List::iterator it = table[hash(data)].begin();
   while(!it.end())
   {
     if(it.getItem() == data)
        return true;
     it.increment();
   }
   return false;
}

void IntegerSetHTChain::remove(int data)
{
   List::iterator prev,it = table[hash(data)].begin();
   while(!it.end())
   {
     if(it.getItem() == data) {
        table[hash(data)].removeAfter(prev);
        return;
     }
     prev = it;
     it.increment();
   }
}
*/


int main(){
	/*
	int r = 0;
	int c;
	int failed_inserts = 0;
	int collisions = 0;
	int successful_inserts = 0;
    IntegerSetHT set(1000);
	srand(time(NULL));
	for(int i = 0; i<500; i++){
		r = rand()%200;
		c = set.insert(r);
		if(c == -1){
			failed_inserts++;
			//printf("failed to insert %d\n", r);
		}else if(c == 0){
			//printf("collision, inserted %d\n", r);
			collisions++;
			successful_inserts++;
		}else if(c == 1){
			//printf("inserted %d\n", r);
			successful_inserts++;
		}
	}
	printf("\n");
	printf("%d failed inserts\n",failed_inserts);
	printf("%d successful inserts\n",successful_inserts);
	printf("%d collisions\n",collisions);
	*/ 
	//this code was for question 1, the following code is for question 3
	IntegerSetHT set(100);
	set.insert(5);
	set.insert(99);
	set.insert(0);
	
	IntegerSetHT::Iterator sit = set.begin();
	
	while(!sit.end())
	{	
		printf("%d ", sit.getInt()); 
		sit.increment();
	}



  return 0;
}
