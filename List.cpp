#include "List.h"




//Constructors

List::List(){ //create node , then connect node
  head  = new ListNode; //dummy node
  tail  = new ListNode;
  count = 0;
  head->next     = tail;
  tail->previous = head;
  
}

//Copy constructor
List::List(const List& source){
    head = new ListNode();
    tail = new ListNode();
    head->next = tail;
    tail->previous = head;
    count = 0;

    // Make a deep copy of the list
    ListItr iter(source.head->next);
    while (!iter.isPastEnd()) {
        insertAtTail(iter.retrieve());
        iter.moveForward();
    }
}


//Destructor
List::~List(){
  makeEmpty();
  delete (head);
  delete (tail);
}


//Copy assignment operator
// Called when the code looks something like list2 = list1;
// (In other words, it is called when you are trying to set an **existing** list equal to another one)
List& List::operator=(const List& source){
  if (this == &source) {
        // The two are the same list; no need to do anything
        return *this;
    } else {
        // Clear out anything this list contained
        // before copying over the items from the other list
        makeEmpty();

        // Make a deep copy of the list
        ListItr iter(source.head->next);
        while (!iter.isPastEnd()) {
            insertAtTail(iter.retrieve());
            iter.moveForward();
        }
    }
    return *this;
}



//Methods

bool List::isEmpty() const {
  if (count == 0) {
    return true;
  }else{
    return false;
  }
}

void List::makeEmpty(){
  //for loop through the list
  //delete node
  //reset the head and tail dummy nodes

  ListItr itr = first();
  while (itr.current->next != NULL){
    //go to the second pointer
    //delete the first pointer
    itr.moveForward();
    delete (itr.current->previous);
  }
  
  head->next = tail;
  tail->previous = head;
  count = 0;
  
}


ListItr List::first(){
  return head->next;
}

ListItr List::last(){
  return tail->previous;
}


void List::insertAfter(int x, ListItr position){
  ListNode * node = new ListNode;
  node->value = x;
  node->next = position.current->next;
  node->previous = position.current;
  position.current->next->previous = node;
  position.current->next = node;
  count++;
  
}

void List::insertBefore(int x, ListItr position){
  ListNode * node = new ListNode;
  node->value = x;
  node->next = position.current;
  node->previous = position.current->previous;
  position.current->previous->next = node;
  position.current->previous = node;
  count++;
}

void List::insertAtTail(int x){
  ListNode * node = new ListNode;
  node->value = x;
  node->next = tail;
  node->previous = tail->previous;
  tail->previous->next  = node;
  tail->previous = node;
  count++;
}

void List::remove(int x){
  ListItr itr = find(x);
  if (&itr != NULL){
    itr.current->next->previous = itr.current->previous;
    itr.current->previous->next = itr.current->next;
    count--;
    delete (itr.current);
  }
}

ListItr List::find(int x){
  ListItr itr = ListItr();
  itr.current = head;
  while (itr.current->next != NULL){
    if (itr.retrieve() == x){
      return itr;
    }else{
      itr.moveForward();
    }
  }
  itr.current = tail;
  return itr;
}



int List::size() const {
  return count;
}



void printList(List& source, bool forward){
   ListItr list = source.first();
   ListItr listbackward = source.last();
   if (forward == true){
    while (list.isPastEnd()  == false ){
    cout << list.retrieve()  << endl;
    list.moveForward();
  }
 }else{
    while (listbackward.isPastBeginning() == false){
      cout << listbackward.retrieve() << endl;
      listbackward.moveBackward();
    }
  }
}

