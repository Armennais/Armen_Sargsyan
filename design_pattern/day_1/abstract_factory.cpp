#include <iostream>
using namespace std;

class AbstractCreateChair {
 public:
  virtual ~AbstractCreateChair(){};
  virtual string Chair() const = 0;
};

class CreateChair1 : public AbstractCreateChair {
 public:
  string Chair() const override {
    return "Create victorian chair.";
  }
};

class CreateChair2 : public AbstractCreateChair {
  string Chair() const override {
    return "Create modern chair.";
  }
};


class AbstractFactory {
 public:
  virtual AbstractCreateChair *createChair() const = 0;
};


class SphericFactroy : public AbstractFactory {
 public:
  AbstractCreateChair *createChair() const override {
    return new CreateChair1();
  }

};

class PiramidalFactory : public AbstractFactory {
 public:
  AbstractCreateChair *createChair() const override {
    return new CreateChair2();
  }
};

void ClientCode(const AbstractFactory &factory) {
  const AbstractCreateChair *product_a = factory.createChair();
  cout << product_a->Chair() << "\n";
  delete product_a;
}

int main() {
  cout << "Client: Testing client code with the first factory type:\n\n";
  SphericFactroy *f1 = new SphericFactroy();
  ClientCode(*f1);
  delete f1;

  cout << endl;

  cout << "Client: Testing the same client code with the second factory type:\n\n";
  PiramidalFactory *f2 = new PiramidalFactory();
  ClientCode(*f2);
  delete f2;

  return 0;
}