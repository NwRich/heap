#include <iostream>
#include "node.h"
using namespace std;
void heapify(int place, node heap[]);
void add(int toAdd, node* heap[]);
int main() {
  node* heap[100];
  int input;
  node* nodeToAdd = new node();
  cin >> input;
  add(input, heap);
  
  return 0;
}

void add(int toAdd, node* heap[]) {
  int place = -1;
  for (int i = 0; i < 100; i++) {//go through the array to insert into an empty spt
    if (heap[i]->getValue() == 0) {//if the value the spot is empty
      heap[i]->setValue(toAdd);//add the node to the array
      place = i;//keep track of where I placed the array
      break;//end the for loop
    }
  }
  if (place != -1) {//if the place has changed from intilization
    place = place+1;//I want zero to be equal to null so I can divide by two
    while (place != 0) {//make sure that the place is not the first in the array
      int parentPlace = place/2;//this finds the parent node
      if (parentPlace != 0 && heap[parentPlace-1] < heap[place-1]) {//while the parent is not at the zero point
	int temp = heap[parentPlace-1]->getValue();//used to hold the parents info
	heap[parentPlace-1]->setValue(heap[place-1]->getValue());//change the nodes data instead of having to worry about the place
	heap[place-1]->setValue(temp);//used to set the left and right values of the array
      }
      else {
	break;//end
      }
      place = parentPlace;//now at the parents place
    }
  }
}

void heapify(int place, node* heap[]) {//compare the the parent and the child and switch of the child is greater
  int temp = heap[place-1]->getValue();//create a temp value for the place of heap
  if (temp < heap[place*2-1]->getValue() || temp < heap[place*2]->getValue()) {
    if (heap[place*2-1]->getValue() < heap[place*2]->getValue()) {
      heap[place-1]->setValue(heap[place*2]->getValue());
      heap[place*2]->setValue(temp);
      heapify(place*2+1,heap);
    }
    else {
      heap[place-1]->setValue(heap[place*2-1]->getValue());
      heap[place*2-1]->setValue(temp);
      heapify(place*2,heap);
    }
  }
}
