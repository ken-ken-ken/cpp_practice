#ifndef _INC_LLIST
#define _INC_LLIST

#include <string.h>

int MAX_SIZE = 1000;
template<class K, class V>
class BinaryTree
{  
  // Node struct
  struct Node
  {
    K key;
    V value;
    Node *rightChild;
    Node *leftChild;
  Node(const K& k, const V& v):key(k), value(v), rightChild(), leftChild() {}


  private:
    Node& operator=(const Node&) = delete; //Prevent assignment
  };
  int currentSize;
  K keyFound;
  Node *root;
  
 private:
  bool search(K key, Node *node);
  bool insert(K key, V value, Node *node, Node *parent, bool wasLeft);
  void searchKey(V value, Node *node);
  V searchValue(K key, Node *node, Node *parent);
  bool remove(K key, Node *node, Node *parent, bool wasLeft);
  
 public:
  BinaryTree(); //constructor
  BinaryTree(K key, V value); // constructor with the root value, key already defined
  bool contains(K key);
  bool add(K key, V value);
  bool deleteNode(K key);
  V getValue(K key);
  K getKey(V value);
  int size();
  bool isFull();
  bool isEmpty();
  bool clear();

  ~BinaryTree(); //destructor
};


template<class K, class V>
BinaryTree<K, V>::BinaryTree()
{
  root = NULL;
  currentSize = 0;
  keyFound = NULL;
}

template<class K, class V>
BinaryTree<K, V>::BinaryTree(K key, V value)
{
  root = new Node(key, value);
  currentSize = 1;
  keyFound = NULL;
}


template<class K, class V>
BinaryTree<K, V>::~BinaryTree()
{
  std::cout << "Calling Destructor" << std::endl;
}

template<class K, class V>
bool BinaryTree<K, V>::contains(K key)
{
  return search(key, root);
}


template<class K, class V>
bool BinaryTree<K, V>::search(K key, Node *node)
{
  if (node == NULL) return false;
  if (key > node->key)
    return search(key, node->rightChild);
  else if (key < node->key)
    return search(key, node->leftChild);
  else
    return true;
}


template<class K, class V>
bool BinaryTree<K,V>::add(K key, V value)
{
  if (root == NULL) root = new Node(key, value);
  else insert(key, value, root, NULL, false);
  currentSize++;
  return true;
}

template<class K, class V>
bool BinaryTree<K, V>::insert(K key, V value, Node *node, Node *parent, bool wasLeft)
{
  if (node == NULL){
    if (wasLeft)
      parent->leftChild = new Node(key, value);
    else
      parent->rightChild = new Node(key, value);
    return true;
  }
  else if (key > node->key)
    return insert(key, value, node->rightChild, node, false);
  else
    return insert(key, value, node->leftChild, node, true);
}


template<class K, class V> 
bool BinaryTree<K, V>::deleteNode(K key) {
  if (isEmpty()) return false;
  if (!remove(key, root, NULL, false)) return false;
  currentSize--;
  return true;
}


template<class K, class V>
bool BinaryTree<K, V>::remove(K key, Node *node, Node *parent, bool wasLeft)
{
  if(node == NULL) return false;
  if(key > node->key) return remove(key, node->rightChild, node, false);
  else if(key < node->key) return remove(key, node->leftChild, node, true);
  // Key found
  else {
  // No children
  if (node->leftChild == NULL && node->rightChild == NULL){
    if (parent == NULL) clear();
    else if(wasLeft) parent->leftChild = NULL;
    else parent->rightChild = NULL;
  }
  // Right child only
  else if (node->leftChild == NULL) {
    if (parent == NULL) root = node->rightChild;
    else if (wasLeft) parent->leftChild = node->rightChild;
    else parent->rightChild = node->rightChild;
  }
  // Left child only
  else if (node->rightChild == NULL) {
    if (parent == NULL) root = node->leftChild;
    else if (wasLeft) parent->leftChild = node->leftChild;
    else parent->rightChild = node->leftChild;
  }
  // The node has both right and left children
  else {
    Node *successor = node->rightChild;
    while (successor->leftChild != NULL)
      successor = successor->leftChild;
    node = successor;
    successor = NULL;
  }
  return true;
  }
}


template<class K, class V>
V BinaryTree<K, V>::getValue(K key) {
  if (isEmpty()) return NULL;
  V foundValue = searchValue(key, root, NULL);
  return foundValue;
}


template<class K, class V>
V BinaryTree<K, V>::searchValue(K key, Node *node, Node *parent)
{
  if (node == NULL) return NULL;
  else if (key > node->key) return searchValue(key, node->rightChild, node);
  else if (key < node->key) return searchValue(key, node->leftChild, node);
  else return node->value;
}


template<class K, class V>
K BinaryTree<K, V>::getKey(V value) {
  keyFound = NULL;
  searchKey(value, root);
  return keyFound;
}


template<class K, class V>
void BinaryTree<K, V>::searchKey(V value, Node *node)
{
  if (node == NULL) return;
  searchKey(value, node->leftChild);
  if(node->value == value) keyFound = node->key;
  searchKey(value, node->rightChild);
}


template<class K, class V>
int BinaryTree<K, V>::size()
{
  return currentSize;
}


template<class K, class V>
bool BinaryTree<K , V>::isFull() {
  return currentSize == MAX_SIZE;
}


template<class K, class V>
bool BinaryTree<K, V>::isEmpty()
{
  return currentSize == 0;
}

#endif
