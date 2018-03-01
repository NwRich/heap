#include <iostream>
#include "node.h"
using namespace std;
void heapify();
void add(int toAdd);
node* head;
int main() {
  char* input = new char[4];
  add(3, head);
  return 0;
}

void add(int toAdd, node* current) {
  if (head == NULL) {//if the head is empty
    head->setValue(toAdd);//set the head
  }
  else {
    node* newNode = new node();
    newNode->setValue(toAdd);
    if (current->getLeft() == NULL) {
      current->setLeft(newNode);
    }
    else if (current->getRight() == NULL) {
      current->setRight(newNode);
    }
    else {
      node* temp;
      temp = head;
      int leftRoot;
      while (temp->getLeft() != NULL) {
	temp = temp->getLeft();
	leftRoot = leftRoot++;
      }
      temp = head;
      int rightRoot;
      while(temp->getRight() != NULL) {
	temp = temp->getRight();
	rightRoot = rightRoot++;
      }
      if (leftRoot == rightRoot) {
	if (current->getLeft()->getLeft() == NULL) {
	  current = current->getLeft();
	  add(toAdd, current);
	}
      }
      else if (leftRoot != rightRoot) {
	current = current->getRight();
	add(toAdd, current);
      }
    }
  }
}
void heapify() {

}
# heap
