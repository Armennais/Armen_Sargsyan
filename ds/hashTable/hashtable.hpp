#ifndef __HASHTABLE_H__
#define __HASHTABLE_H__


#include <iostream>
#include <string>

using namespace std;

#define CAPACITY 8

class HashNode {
  public:
    string _key;
    string _value;

    HashNode(string key, string value) {
      _key = key;
      _value = value;
    }
};

class HashTable {
  private:
    HashNode** _table;
    int _capacity;

    int hashFunction(string);
    void resize();
    void rehash();
    int getLastPosition();

  public:
    HashTable();
    void insert(string, string);
    void remove(string);
    string search(string);
    void printTable();
};

HashTable::HashTable() {
  _capacity = CAPACITY;
  _table = new HashNode* [_capacity];

  for (int i = 0; i < _capacity; i++) {
    _table[i] = NULL;
  }
}

int HashTable::hashFunction(string key) {
  int result = 0;

  for (int i = 0; key[i] != '\0'; i++) {
    result += key[i];
  }

  return result % _capacity;
}

void HashTable::resize() {
  _capacity *= 2;
  HashNode** temp = new HashNode*[_capacity];

  for (int i = 0; i < _capacity; i++) {
    temp[i] = NULL;
  }

  for (int i = 0; i < _capacity / 2; i++) {
    temp[i] = _table[i];
  }

  _table = temp;
}

void HashTable::rehash() {
  _capacity /= 2;
  HashNode** temp = new HashNode*[_capacity];

  for (int i = 0; i < _capacity; i++) {
    temp[i] = NULL;
  }

  for (int i = 0; i < _capacity; i++) {
    temp[i] = _table[i];
  }

  _table = temp;
}

int HashTable::getLastPosition() {
  for (int i = _capacity - 1; i >= 0; i--) {
    if (_table[i]) {
      return i;
    }
  }

  return -1;
}

void HashTable::insert(string key, string value) {
  int index = hashFunction(key);

  if (_table[index]) {
    while (_table[index]) {
      index++;
      if (index >= _capacity) {
        resize();
      }
    }

    _table[index] = new HashNode(key, value);
  } else {
    _table[index] = new HashNode(key, value);
  }
}

void HashTable::remove(string key) {
  int index = hashFunction(key);

  for (int i = index; i >= _capacity; i++) {
    if (_table[i] && _table[i]->_key == key) {
      _table[i] = NULL;
      break;
    }
  }

  if (getLastPosition() < _capacity / 2 && _capacity != CAPACITY) {
    rehash();
  }
}

string HashTable::search(string key) {
  int index = hashFunction(key);

  if (_table[index] && _table[index]->_key == key) {
    while (_table[index]) {
      if (_table[index]->_key == key) {
        return _table[index]->_value;
      }

      index++;
    }
  }

  return  key + " not found";
}

void HashTable::printTable() {
  for (int i = 0; i < _capacity; i++) {
    cout << "[" << i << "]: ";
    if (_table[i]) {
      cout << "[" << _table[i]->_key << ", " << _table[i]->_value << "] ";
    }
    cout << endl;
  }
}
#endif // __HASHTABLE_H__