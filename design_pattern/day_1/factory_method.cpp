#include <iostream>
using namespace std;
class Factory {
 public:
  virtual ~Factory() {}
  virtual string Operation() const = 0;
};

class RoadLogistecs : public Factory {
 public:
  string Operation() const override {
    return "{Truck}";
  }
};

class SeaLogistecs : public Factory {
 public:
  string Operation() const override {
    return "{Ship}";
  }
};

class Creator {
 public:
  virtual ~Creator(){};
  virtual Factory* FactoryMethod() const = 0;
  string SomeOperation() const {
    Factory* factory = this->FactoryMethod();
    string result = "Landing with " + factory->Operation();
    delete factory;
    return result;
  }
};
class Creator1 : public Creator {
 public:
  Factory* FactoryMethod() const override {
    return new RoadLogistecs();
  }
};

class Creator2 : public Creator {
 public:
  Factory* FactoryMethod() const override {
    return new SeaLogistecs();
  }
};



int main() {

  Creator* creator = new Creator1();
  cout << creator->SomeOperation() << endl;
  

  Creator* creator2 = new Creator2();
  cout << creator2->SomeOperation() << endl;
  delete creator;
  delete creator2;
  return 0;
}