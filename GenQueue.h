#include "DoublyLinkedList.cpp"
template <class T>
class GenQueue{

public:
  GenQueue();//default
  // GenQueue(int maxSize);//overloaded
  ~GenQueue();



//core functions
  void insertQueue(T d);//enqueue
  T removeQueue();//dequeue


//aux functions
  T peek();
  bool isFull();
  bool isEmpty();
  int getSize();
  void printQueue();

  //vars
  int front;//head
  int rear;//tail
  int mSize;
  int numElements;

  DoublyLinkedList<T> *myQueue = new DoublyLinkedList<T>();//array

  // DoublyLinkedList *myQueue = new DoublyLinkedList();

};
