#include <iostream>
#include "LinkedList.h"

using namespace std;
void add(LinkedList<int>& ll);//adds to the front, end, and in between

int main(){
  LinkedList<int> ll;
  add(ll);

  // Check if contains method works
  cout << "Does it contain 20?: ";
  if (ll.contains(20))
    cout << "Yes" << endl;
  else
    cout << "No" << endl;

  cout << "How about 15?: ";
  if (ll.contains(15))
    cout << "Yes" << endl;
  else
    cout << "No" << endl;

  // check if removeFirst method works
  cout << "Now, delete them from the beginning number" << endl;
  int listSize = ll.size();
  for (int i = 0; i <= listSize-1; i++) {
    ll.removeFirst();
    ll.print();
  }

  cout << "Lets have another 5, 15, 10 list" << endl;
  add(ll);

  cout << "Now, delete them from the tail" << endl;
  for (int i = 0; i <= listSize - 1; i++) {
    ll.removeLast();
    ll.print();
  }
  return 0;
}

void add(LinkedList<int>& ll){
  cout << "adding 5 to the index 0" << endl;
  // Empty -> 5
  ll.addFirst(5);

  cout << "adding 10 at the end of the list" << endl;
  // 5 -> 5, 10
  ll.addLast(10);

  cout << "inserting 15 at index 1 (between 5 and 10)" << endl;
  // 5, 10 -> 5, 15, 10
  ll.insert(15, 1);
  cout << "Now, the size of the list is: " << ll.size() << endl;

  cout << "result:" << endl;
  ll.print();
}  
