#include "item.h"

int Item::getID(){
  return id;
}

void Item::setID(int i) { //Item:: is a reference to .h
  id = i;
}
