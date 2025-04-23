#include <iostream>
using namespace std;
#include <string>

#include "RsvList.h"

RsvList::RsvList() : head(NULL) { }

RsvList::~RsvList()
{
  Node* currNode = head;
  Node* nextNode;

  while (currNode != NULL) {
    nextNode = currNode->next;
    delete currNode->data;
    delete currNode;
    currNode = nextNode;
  }
}

void RsvList::add(Reservation* r)
{
  Node* tmpNode;
  Node* currNode;
  Node* prevNode;

  tmpNode = new Node;
  tmpNode->data = r;
  tmpNode->next = NULL;

  prevNode = NULL;
  currNode = head;

  while (currNode != NULL) {
    if (tmpNode->data->lessThan(currNode->data) == true) {
      break;
    }
    prevNode = currNode;
    currNode = currNode->next;
  }

  if (prevNode == NULL) {
    head = tmpNode;
  }
  else {
    prevNode->next = tmpNode;
  }

  tmpNode->next  = currNode;
}

void RsvList::convertToArray(Reservation** arr, int& size)
{
  Node* currNode;
  Node* prevNode;

  prevNode = NULL;
  currNode = head;
  int s = 0;
  while (currNode != NULL) {
    arr[s++] = currNode->data;
    prevNode = currNode;
    currNode = currNode->next;
  }
  size = s;
}

void RsvList::print()
{
  Node* currNode = head;

  while (currNode != NULL) {
    currNode->data->print();
    currNode = currNode->next;
  }
}

