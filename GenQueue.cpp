// #ifndef GENQUEUE_H
// #define GENQUEUE_H
// #include "GenQueue.h"
//
//
// //last resort  https://www.geeksforgeeks.org/queue-linked-list-implementation/
// GenQueue::GenQueue(){
//   DoublyLinkedList *myQueue = new DoublyLinkedList();
//   // GenQueue *myQueue = new GenQueue();
//
//   mSize= 100;
//   front = 0;
//   rear = -1;
//   numElements = 0;
// }
// // //overloaded
// // GenQueue::GenQueue(){
// //   myQueue = new DoublyLinkedList();
// //   // mSize = maxSize;
// //   front = 0;
// //   rear = -1;
// //   numElements = 0;
// // }
//
// GenQueue::~GenQueue(){
//   delete myQueue;
//   //we figure it out
//
// }
//
// void GenQueue::insertQueue(int d){
//   // DoublyLinkedList *poop = new DoublyLinkedList();
//   //add error checking
//   // myQueue[++rear]=d;
//   myQueue->insertFront(d);
//
//   ++numElements;
//
// }
//
// int GenQueue::removeQueue(){
//
//   //error checking
//   // int c = 0; //null intecter
//   // c = myQueue[front];
//   myQueue -> removeFront();
//   --numElements;
//   // return c;
//   return 0;
// }
//
// void GenQueue::peek(){
//   myQueue->peekQ();
//   // return myQueue[front];
// }
//
// bool GenQueue::isFull(){
//   cout << "This has doubly linked list implementation so it will return false"<<endl;
//   return(numElements== mSize);
// }
// bool GenQueue::isEmpty(){
//   cout << "This has doubly linked list implementation so it will return false"<<endl;
//   return(numElements == 0);
// }
//
// int GenQueue::getSize(){
//   return numElements;
// }
// void GenQueue::printQueue(){
//   cout << "Here is the printed Queue" << endl;
//   myQueue->printList();
// }
//
// #endif



#ifndef GENQUEUE_H
#define GENQUEUE_H
#include "GenQueue.h"


//last resort  https://www.geeksforgeeks.org/queue-linked-list-implementation/
template <class T>
GenQueue<T>::GenQueue(){
  DoublyLinkedList<T> *myQueue = new DoublyLinkedList<T>();
  // GenQueue *myQueue = new GenQueue();

  mSize= 100;
  front = 0;
  rear = -1;
  numElements = 0;
}
// //overloaded
// GenQueue::GenQueue(){
//   myQueue = new DoublyLinkedList();
//   // mSize = maxSize;
//   front = 0;
//   rear = -1;
//   numElements = 0;
// }
template <class T>
GenQueue<T>::~GenQueue(){
  delete myQueue;
  //we figure it out

}
template <class T>
void GenQueue<T>::insertQueue(T d){
  // DoublyLinkedList *poop = new DoublyLinkedList();
  //add error checking
  // myQueue[++rear]=d;
  myQueue->insertFront(d);

  ++numElements;

}
template <class T>
T GenQueue<T>::removeQueue(){

  myQueue -> removeBack();
  --numElements;
  // return c;
  return 0;
}
template <class T>
T GenQueue<T>::peek(){
  return myQueue->peekQ();
  // return myQueue[front];
}
template <class T>
bool GenQueue<T>::isFull(){
  cout << "This has doubly linked list implementation so it will return false"<<endl;
  return(numElements== mSize);
}
template <class T>
bool GenQueue<T>::isEmpty(){
  cout << "This has doubly linked list implementation so it will return false"<<endl;
  return(numElements == 0);
}
template <class T>
int GenQueue<T>::getSize(){
  return numElements;
}
template <class T>
void GenQueue<T>::printQueue(){
  cout << "Here is the printed Queue" << endl;
  myQueue->printList();
}

#endif
