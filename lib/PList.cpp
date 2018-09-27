#include <stdio.h>

#include "PList.h"

PList::PList()
{
  // start with an empty list
  head = NULL;
  tail = NULL;
}

void PList::append(Item a, Item *b =NULL)
{
  PListNode *node = new PListNode(a, b);
  if (head == NULL)
    {
      // list is empty
      head = node;
      tail = node;
    }
  else
    {
      tail->setNext(node);
      tail = node;
    }
}

bool PList::remove(Item &copy)
{
  if (!empty()) // if list is not empty
    {
      copy = head->getItem(); // return copy
      PListNode *tmp = head->getNext();
      delete head; // delete the node
      head = tmp;  // update the head
      if (tmp==NULL) // removed last element
	tail = NULL;
      return true;
    }
  return false; // nothing in list
}

bool PList::empty()
{
  return head==NULL;
}

void PList::insertAfter(PList::iterator it, Item item) // pseudocode in zyBook 2.3
{
    if (it.node==NULL)
      { // special case to insert at the head
	// point new node at current head of list
	PListNode *node = new PListNode(item,head);
	if (head==NULL) { // if head was NULL, tail was also NULL
	  tail = node;   // new node is now the tail
	  head = node;   // new node is now the head
	} else {
	  head = node;   // update head to new node
	}
      }
    else // insert after it
      {
	PListNode *node = new PListNode(item,it.node->getNext());
	it.node->setNext(node);
	if (tail==it.node) tail = node;
      }
}

void PList::removeAfter(PList::iterator it) // pseudocode in zyBook 2.4
{
   if (it.node==NULL) // special case to remove head, it’s not after any node
     {
       PListNode *remove = head;               // will remove the head
       head = head->getNext();      // advance head
       if (head==NULL) tail = NULL; // if head is NULL now, list is empty
       delete remove;               // delete removed node
     }
   else // normal case, if not the head, then simply disconnect the node
     {
       PListNode *tmp = it.node;
       PListNode *remove = tmp->getNext(); // next node to be removed
       tmp->setNext(remove->getNext());   // point around node to be removed
       if (tail==remove) tail = tmp;      // if removing tail, update tail
       delete remove; // delete node      // delete the removed node
     }
}


/* int main()
{
  // PList l;

  // l.append(Item("milk"));
  // l.append(Item("eggs"));
  // l.append(Item("bread"));
  // l.append(Item("potato chips"));
  // l.append(Item("toothpaste"));


  // PList::iterator it = l.begin();
  ////PList::iterator it = l.begin();
  // while(!it.end())
    // {
      // Item &copy = it.getItem();

      // printf("Next thing in list: %s\n",copy.str);

      // it.increment();
    // }

  return 0;
} */
