#include <stdio.h>

class Item {
public:
  const char * str;
  Item(const char *as = "") 
  { 
    str = as; 
  }
};


class List {
	private:

	// ListNode represents each 
	// node of the list
  class ListNode {
  private:
    Item item; // data in the list
    ListNode *next;	
	
  public:
    ListNode(Item a){ 
      item = a; 
      next=NULL; // automatically serves as a list tail
    }
	
    ListNode* getNext(){ 
      return next; 
    }
	
    void setNext(ListNode *n){ 
      next = n; 
    }
	
    Item getItem(){ 
      return item; 
    }
	
  };

  // add head and tail pointer
  ListNode *head;
  ListNode *tail;
  int theSize;

  
  public:
	List();
	~List();
	void append(Item a);    
	bool remove(Item &a);    
	bool empty(); 
	void push_back(const char *string);
	int length();
	Item get(int n);
	Item remove_front();
};

List::~List(){//destroys the entire list
	while(!empty()){
		remove_front();
		//printf("deleted an item\n");
	}
}

Item List::remove_front(){//assumes there is a head to destroy
	ListNode *temp = head->getNext();
	Item temp2 = Item();
	temp2 = head->getItem();
	delete head;
	theSize--;
	head = temp;
	
	//Item temp2 = Item();
	//temp2 = temp->getItem();
	return temp2;
}

Item List::get(int n){
	if(n>theSize){//prevents everything from getting messed up if user asks for index not in list
		return NULL;
	}
	if(n<1){//if user asks for 0 or negative index
		return NULL;
	}
	n--;//needed to fix off-by-one error
	ListNode *temp2 = head;
	for(int c=1; c<=n; c++){
		temp2 = temp2->getNext();
	}
	return temp2->getItem();
}

int List::length(){
	return theSize;
}

List::List(){
  // start with an empty list
  head = NULL;
  tail = NULL;
  theSize = 0;
}

void List::append(Item a){
  ListNode *node = new ListNode(a);
  if (head == NULL){
      // list is empty
      head = node;
      tail = node;
  }else{
      tail->setNext(node);
      tail = node;
  }
  theSize++;
}

void List::push_back(const char *string){//this function assumes that the list is not empty
	Item temp = Item(string);
	ListNode *node = new ListNode(temp);
	tail->setNext(node);
	tail = node;
	theSize++;
}

bool List::remove(Item &copy){
  if (!empty()) // if list is not empty
    {
      copy = head->getItem(); // return copy
      ListNode *tmp = head->getNext();
      delete head; // delete the node
      head = tmp;  // update the head
      if (tmp==NULL) // removed last element 
		tail = NULL;
	  theSize--;
      return true;
    }
  return false; // nothing in list
}

bool List::empty(){
  return head==NULL;
}


int main(){
  List l;

  l.append(Item("milk"));
  l.append(Item("eggs"));
  l.append(Item("bread"));
  l.append(Item("potato chips"));
  l.push_back("BUTTER");
  l.append(Item("toothpaste"));
  
  printf("the 1th item in the list is %s\n", l.get(1).str);
  printf("size of list is %d items \n", l.length());
  printf("deleted the first element, it was: %s\n", l.remove_front().str);
  printf("size of list is %d items \n", l.length());
  printf("the 1th item in the list is %s\n", l.get(1).str);
  printf("the 2th item in the list is %s\n", l.get(2).str);
  
  // printf("the -1th item in the list is %s\n", l.get(-1).str);
  // printf("the 0th item in the list is %s\n", l.get(0).str);
  // printf("the 1th item in the list is %s\n", l.get(1).str);
  // printf("the 2th item in the list is %s\n", l.get(2).str);
  // printf("the 3th item in the list is %s\n", l.get(3).str);
  // printf("the 4th item in the list is %s\n", l.get(4).str);
  // printf("the 5th item in the list is %s\n", l.get(5).str);
  // printf("the 6th item in the list is %s\n", l.get(6).str);
  // printf("the 7th item in the list is %s\n", l.get(7).str);


  // while(!l.empty()){
      // Item copy;
      // l.remove(copy);

      // printf("Next thing removed: %s\n",copy.str);
	  // printf("size of list is %d items \n", l.length());
   //}

  return 0;
}
