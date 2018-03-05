#include "node.h"

node::node() {
  value = NULL;
  right = NULL;
  left = NULL;
  prev = NULL;
}

void node::setValue(int newInt) {
  value = newInt;
}

int node::getValue() {
  return value;
}

node* node::getPrev() {
  return prev;
}

void node::setPrev(node* newNode) {
  prev = newNode;
}

node* node::getLeft() {
  return left;
}

void node::setLeft(node* newNode) {
  left = newNode;
}

node* node::getRight() {
  return right;
}

void node::setRight(node* newNode) {
  right = newNode;
}
