#ifndef INTEGERSET_H
#define INTEGERSET_H

//#include "List.h"
//#include "List.cpp"

//#include <math.h>
#include <stdlib.h>

namespace ece309{
// IntegerSet abstract base class to demonstrate hash table concepts
class IntegerSet {
protected:
   int size;
   int hash(int key) const { return abs((key * 1301081) % size); }// large prime #
public:
   IntegerSet(int htsize):size(htsize) {}
   virtual int insert(int) = 0;
   virtual bool search(int) const = 0;
   virtual void remove(int) = 0;
};

// Hash Table with Linear Probing
class IntegerSetHT : public IntegerSet {
protected:
  int *table;
  int probeDistance;
  int empty_since_start;
  int empty_after_removal;
public:
   IntegerSetHT(int htsize);
   virtual int insert(int) ;
   virtual bool search(int) const ;
   virtual void remove(int) ;
   
	//iterator for hw6 q3
	class Iterator{
	protected:
		int location;
		IntegerSetHT * ht;
	public:
		Iterator(IntegerSetHT * data){
			ht = data;
			location = 0;
		}
		bool end(){
			if(location >= ht->size)
				return true;
			else
				return false;
		}
		int getInt(){
			return ht->table[location];
			
		}
		void increment(){
			location++;
			while((ht->table[location] < 0) && (location < ht->size)){
				location++;
			}
		}
	};
   
	Iterator begin(){
		return Iterator(this);
	}
};
}




	
	
	


/*
// Hash Table with Chaining
class IntegerSetHTChain : public IntegerSet {
protected:
  List *table;
public:
   IntegerSetHTChain(int htsize);
   virtual bool insert(int) override;
   virtual bool search(int) const override;
   virtual void remove(int) override;
};
*/
#endif //INTEGERSET_H
