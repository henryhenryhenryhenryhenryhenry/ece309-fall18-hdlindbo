#ifndef PLIST_H
#define PLIST_H

#include <stdio.h>

class Item {
public:
  virtual void print(){printf("default\n");};
};

class IntItem : public Item{
public:
	int integer;
	IntItem(int x = 0):integer(x){}
	void print() {
		printf("data = %d\n", integer);
	} 
};

class DoubleItem : public Item{
public:
	double data;
	DoubleItem(double d = 0.0):data(d){}
	void print() {
		printf("data = %lf\n",data);
	}
};

class StringItem : public Item{
public:
	const char * string;
	StringItem(const char * s = ""):string(s){}
	void print() {
		printf("data = %s\n",string);
	}
};


class PList {
private:

// PListNode represents each
// node of the list
  class PListNode {
  public:
    Item item; // data in the list
	Item* ptitem; //pointer to item
    PListNode *next;
  public:
    PListNode(Item a, PListNode *n=NULL)
    {
      item = a;
      next=n; // automatically serves as a list tail
    }
	PListNode(Item a, Item *b=NULL)
    {
      item = a;
      ptitem = b;
    }
    PListNode* getNext()
    {
      return next;
    }
    void setNext(PListNode *n)
    {
      next = n;
    }
    Item& getItem()
    {
      return item;
    }
	/* Item * getItem2(){//for hw 4
		Item * tmp = &item;
		return tmp;
	} */
	void printnode(){
		ptitem->print();
	}
  };

  // add head and tail pointer
  PListNode *head;
  PListNode *tail;

public:

  class iterator {
  private:
    PListNode *node;

  public:
    iterator(PListNode *n=NULL) { node = n; }
    Item &getItem() { return node->getItem(); }
    void increment() { node = node->next; }
    bool end() {  return node==NULL; }
	void itPrint(){node->printnode();}//added for hw4
    friend class PList;
  };


public:
  PList();
  void append(Item a, Item *b);
  bool remove(Item &a);
  bool empty();

  iterator begin()
  {
    return iterator(head);
  }

  void removeAfter(iterator it); // pseudocode in zyBook 2.4
  void insertAfter(iterator it, Item item);
};

#endif //PLIST_H
