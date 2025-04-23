#ifndef RSVLIST_H
#define RSVLIST_H

#include "Reservation.h"

class RsvList
{
  class Node
  {
    public:
      Reservation* data;
      Node*    next;
  };

  public:
    RsvList();
    ~RsvList();
    void add(Reservation* r);
    void convertToArray(Reservation** arr, int& size);
    void print();

  private:
    Node* head;
};

#endif
