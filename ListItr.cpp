#include "ListItr.h"



//Constructors

ListItr::ListItr(){
  current = NULL;
}

ListItr::ListItr(ListNode* theNode){
  current = theNode;
}



//Methods

bool ListItr::isPastEnd() const {
  if (current->next == NULL) {
      return true;
    } else{
    return false;
  }
}

bool ListItr::isPastBeginning() const {
  if (current->previous == NULL){
    return true;
  } else {
    return false;
  }
}

void ListItr::moveForward(){
  current = current->next;
}

void ListItr::moveBackward(){
  current = current->previous;
}

int  ListItr::retrieve() const{
  return current->value;
}

