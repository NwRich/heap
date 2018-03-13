 /*Nicholas Rich
 *3/5/18
 *a program that creates a max heap from a user input or from a file and then prints it out
 */
#include <iostream>
#include <ctype.h>
#include <cstring>
#include <stdlib.h>
#include "node.h"
using namespace std;
node* heap[100];
node* head;
void heapify(int place, node* heap[]);
void add(int toAdd, node* heap[]);
void makeTree(node* heap[]);
void print(node* current, int depth);
int main() {
  //node* heap[100];
  for(int i = 0; i < 100; i++) {//used to fill the array with emtpy nodes
    node* newNode = new node();//empty node
    heap[i] = newNode;//empty node
  }
  char* input = new char[32];//used to get the input from the user
  cout << "type in numbers, when you are done type in 'end'" << endl;//give the user instructions
  for (int i = 0; i < 100; i++) {//go through the length of the array
    cin >> input;//write to input
    if (strcmp(input, "end") != 0) {//if the input is not "end"
      int in = atoi(input);//convert to the char array to an int
      add(in, heap);//pass in head
    }
    else {//otherwise the input is not a number
      break;//end the for loop
    }
  }
  makeTree(heap);//make the heap array into a max heap tree using nodes
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
      heapify(place, heap);
    }
  }
}

void heapify(int place, node* heap[]) {//compare the the parent and the child and switch of the child is greater
  int temp = heap[place-1]->getValue();//create a temp value for the place of heap
  if (temp < heap[place*2-1]->getValue() || temp < heap[place*2]->getValue()) {//check the left and the right child
    if (heap[place*2-1]->getValue() < heap[place*2]->getValue()) {//if the left child is greater than the right child
      heap[place-1]->setValue(heap[place*2]->getValue());
      heap[place*2]->setValue(temp);
      heapify(place*2+1,heap);
    }
    else {//the right child is greater than or equal to its sibling
      heap[place-1]->setValue(heap[place*2-1]->getValue());
      heap[place*2-1]->setValue(temp);
      heapify(place*2,heap);
    }
  }
}

void makeTree(node* heap[]) {
  int parent = -1;
  if (head == NULL) {//if the head is empty
    head = heap[0];//set the head to the first spot in the array
    head->setLeft(heap[1]);//set its left child
    head->setRight(heap[2]);//set its right child
  }
  for (int i = 1; i < 100; i++) {//go through the array ignoring the head
    if (heap[i]->getValue() != 0) {//if the spot is not empty
      parent = i+1;//parents spot is equal to 1 greater than its spot
      int childPlace = parent*2;//the childs place is 2 times greater
      if (heap[childPlace-1]->getValue() != 0) {
	heap[parent-1]->setLeft(heap[childPlace-1]);//set the left value
      }
      if (heap[childPlace]->getValue() != 0) {
	heap[parent-1]->setRight(heap[childPlace]);//set the right value
      }
      else {
	break;
      }
    }
  }
  print(head, 0);
}

void print(node* current, int depth) {
  if (current->getLeft() != NULL) {
    print(current->getLeft(), depth+1);//go to the end of the tree left bound
  }
  int tab = depth;
  for (tab; tab > 0; tab--) {
    cout << "\t";
  }
  cout << current->getValue() << endl;
  if (current->getRight() != NULL) {
    print(current->getRight(), depth+1);
  }
}
