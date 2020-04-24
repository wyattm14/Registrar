
#include "ListNode.cpp"

template <class T>

class DoublyLinkedList
{
  //because it cannot be negative
public:
  ListNode<T> *front;
  ListNode<T> *back;
  unsigned int size;
  DoublyLinkedList();
  ~DoublyLinkedList();

  void insertFront(T data);//int is a T if it was the template class
  void insertBack(T data);
  T removeFront();
  T removeBack();
  T search(T val);//will return the value or position of node depending on implementation
  T removeAtPos(int pos);
  T remove (T val);
  T peekQ();

  unsigned int getSize();
  bool isEmpty();
  void printList();

};
