#ifndef _INC_LLIST
#define _INC_LLIST

#include <string.h>
template<class T>
class LinkedList
{  
  // Node struct
  struct Node
  {
    T data;
    Node *next;
    Node(const T& d):data(d), next() {}


  private:
    Node& operator=(const Node&) = delete; //Prevent assignment
  };
  Node* head;
  Node* tail;
  int currentSize;
  
 public:

  LinkedList(); //constructor


  void addLast(T obj);
  void addFirst(T obj);
  void insert(T obj, int location);
  T remove(int location);
  //T remove(T obj);
  T removeFirst();
  T removeLast();
  T get(int location);
  bool contains(T obj);
  void clear();
  bool isEmpty();
  int size();
  void print();
  ~LinkedList(); //destructor
};


template<class T>
LinkedList<T>::LinkedList()
{
  head = NULL;
  tail = NULL;
  currentSize = 0;
}

template<class T>
LinkedList<T>::~LinkedList()
{
  // destructor; traverse the list and delete each
  Node * tmp = head;
  while (head)
  {
    head = head->next;
    delete tmp;
    tmp = head;
  }
}

template<class T>
void LinkedList<T>::addLast(T obj){
  Node *newNode = new Node(obj);
  if (head == NULL){
    head = tail = newNode;
  }
  else {
    tail->next = newNode;
    tail = newNode;
  }
  currentSize++;
}

template<class T>
void LinkedList<T>::addFirst(T obj){
  Node *newNode = new Node(obj);
  newNode->next = head;
  head = newNode;
  if (head->next == NULL) tail = newNode;
  currentSize++;
}


template<class T>
void LinkedList<T>::insert(T obj, int location){
  Node *newNode = new Node(obj);
  Node *previous = NULL;
  Node *curr = head;
  if (isEmpty()) head = tail = newNode;
  else {
    for (int i = 0; i <= location - 1; i++){
      previous = curr;
      curr = curr->next;
    }
    if (curr == NULL) { // The location is at the end
      previous->next = newNode;
      tail = newNode;
    }
    else if (previous == NULL) { // the location is at the beginning
      newNode->next = head;
      head = newNode;
    }
    else {
      previous->next = newNode;
      newNode->next = curr;
    }
  }
  currentSize++;
}

template<class T>
T LinkedList<T>::remove(int location){
  Node *previous = NULL;
  Node *curr = head;
  if (isEmpty())
    throw std::runtime_error("The list is empty, nothing to remove");
  if (location >= size() || location < 0)
    throw std::invalid_argument("Not a valid location");
  
  for (int i = 0; i <= location-1; i++) {
    previous = curr;
    curr = curr->next;
  }
  T obj = curr->data;
  if (head == curr) { 
    head = head->next;
  }
  else {
    previous->next = curr->next;
  }
  delete curr;
  currentSize--;
  return obj;
}

template<class T>
T LinkedList<T>::removeFirst(){
  return remove(0);
}

template<class T>
T LinkedList<T>::removeLast(){
  return remove(size() - 1);
}

template<class T>
T LinkedList<T>::get(int location){
  Node *previous = NULL;
  Node *curr = head;
  if (location >= size() || location < 0)
    throw std::invalid_argument("Not a valid location");
  for (int i = 0; i <= location; i++) {
    previous = curr;
    curr = curr->next;
  }
  return curr->data;
}

template<class T>
bool LinkedList<T>::contains(T obj){
  Node *tmp = head;
  while(tmp) {
    if (tmp->data == obj)
      return true;
    tmp = tmp->next;
  }
  return false;
}

template<class T>
void LinkedList<T>::clear(){
  ~LinkedList();
  head = tail = NULL;
  currentSize = 0;
  std::cout << "a" << std::endl;
}

template<class T>
bool LinkedList<T>::isEmpty() {
  return size() == 0;
}

template<class T>
int LinkedList<T>::size() {
  return currentSize;
}

template<class T>
void LinkedList<T>::print() {
  Node *tmp = head;
  if (isEmpty())
    std::cout << "EMPTY" << std::endl;
  else {
    while (tmp) {
      if (tmp->next == NULL)
	std::cout << tmp->data << std::endl;
      else
	std::cout << tmp->data << " --> ";
      tmp = tmp->next;
    }
  }
}
    

#endif
