
#include "DoublyLinkedList.h"

//implementation file for my DoublyLinkedList (.cpp)

template <class T>
DoublyLinkedList<T>::DoublyLinkedList(){
  //empty list
  size = 0;
  front = NULL;
  back = NULL;

}
template <class T>
DoublyLinkedList<T>::~DoublyLinkedList(){
  //build on our own
}
template <class T>
unsigned int DoublyLinkedList<T>::getSize(){
  return size;
}

template <class T>
bool DoublyLinkedList<T>::isEmpty(){
  return (size==0);
}

template <class T>
void DoublyLinkedList<T>::printList(){
  ListNode<T> *curr = front;

  while (curr != NULL){
    cout << curr -> data << endl;
    curr = curr -> next;
  }
}
template <class T>
T DoublyLinkedList<T>::peekQ(){
  ListNode<T> *curr = back;

  if (front == NULL){
    cout << "The Queue is empty"<< endl;

  }
  return back->data;
}

template <class T>
void DoublyLinkedList<T>::insertFront(T d){
  ListNode<T> *node = new ListNode<T> (d);
  node->data=d;
  if (front != NULL) {
    node->next=front;
    front->prev=node;
    front = node;
    front->prev=NULL;
  } else {
    front = node;
    front->prev=NULL;
    back  = node;
    back->next=NULL;
  }
}

template <class T>
void DoublyLinkedList<T>::insertBack(T d){
  ListNode<T> *node = new ListNode<T> (d);
  node -> data=d;
    // newNode->data(d);
  if(front==NULL){
    front = node;
    front->prev=NULL;
    back = node;
    front->next = back;
    back->next=NULL;
    back->prev=front;
    } else if(back!=NULL){

      node->prev=back;
      back->next=node;
      node->next=NULL;
    }
    back = node;
}

template <class T>
T DoublyLinkedList<T>::removeFront(){
  ListNode<T> *node = front;
  int temp = front -> data;

  if (front ->next == NULL){
    //we have one node in the list
    back = NULL;
  }else{
    //there is more than one node in the list
    front -> next->prev = NULL;
  }
  front = front -> next;
  node -> next = NULL;

  delete node;
  size--;
  return temp;
}

template <class T>
T DoublyLinkedList<T>::removeBack(){
  ListNode<T> *node = back;
  int temp = back -> data;
  if (back -> prev == NULL){
    front = NULL;
  }else{
    back -> prev -> next = NULL;
  }
  back = back -> prev;
  node -> prev = NULL;

  delete node;
  size--;
  return temp;


}

template <class T>
T DoublyLinkedList<T>::removeAtPos(int pos){

  ListNode<T>* temp;
  ListNode<T>* prev;
  temp =front;
  if (pos !=0){
    for(int i=0;i<pos;i++){
        temp=temp->next;
  }
  prev = temp->prev;
  if(temp->next!=NULL){
  prev->next=temp->next;
  temp->next->prev=prev;
  }
  else{
  prev->next=NULL;
  }

  delete temp;
  }  else {
      prev = temp->next;
      prev->prev=NULL;
      delete temp;
      front = prev;
    }
}
//find the value in the list before we can delete
// this does not take in a positiion as a param. it takes a value

template <class T>
T DoublyLinkedList<T>::remove(T val){
  ListNode<T> *curr = front;
  while (curr -> data != val){
    //keep iterating till we find our value
    curr = curr->next;
    if (curr==NULL){
      return NULL;//maybe have to return 0 or -1

    }
  }
  //we found the val, now lets delete it
  if (curr == front ){
    //check if node is in the front when we deleting it
    front = curr-> next;
  }else{
    //node is not front or back, in the middle
    curr -> prev-> next = curr -> next;
  }
  if (curr == back){
    back = curr -> prev;
  }else {
    curr -> next -> prev = curr -> prev;
  }

  curr -> next = NULL;
  curr -> prev = NULL;
  int temp = curr -> data;
  delete curr;
  size--;
  return temp;

}

template <class T>
T DoublyLinkedList<T>::search(T value){
  ListNode<T> *curr = front;
    while(curr != NULL)
    {
        if(curr->data == value)
            return value;
        curr = curr->next;
    }

    std::cerr << "No such element in the list \n";
    return NULL;

}
