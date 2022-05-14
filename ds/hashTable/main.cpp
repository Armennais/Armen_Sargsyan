#include "./hashtable.hpp"

int main() {
  HashTable hashTable;
  hashTable.insert("Levon", "33op332");
  hashTable.insert("Robert", "45ss55");
  hashTable.insert("Serzh", "45ss55");
  hashTable.insert("Nikol", "12jj112");

  hashTable.remove("Nikol");
  hashTable.printTable();
  cout << hashTable.search("Nikol") << endl;
  return 0;
}