#include <iostream>
#include <string.h>

#include "BinaryTree.h"
#include <python3.5m/Python.h>
using namespace std;
int main()
{
  cout << MAX_SIZE << endl;
  BinaryTree<int, string> bt;
  bt.add(6, "aaaaa");
  cout << bt.getKey("aaaaa") << endl;
  string a;
  a = "hello";
  cout << a << endl;
}
