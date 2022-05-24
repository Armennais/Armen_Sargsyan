#include <iostream>
using namespace std;

class Singleton
{
public:
	static Singleton* getInstance();

	void setValue(int val)
	{
		_value = val;
	}

	int getValue()
	{
		return (_value);
	}

protected:
	int _value;

private:
	static Singleton * _inst;
	Singleton(): _value(0) {}

	Singleton(const Singleton &);
};

Singleton *Singleton::_inst = NULL;

Singleton *Singleton::getInstance()
{
	if (_inst == NULL)
	{
		_inst = new Singleton();
	}

	return (_inst);
}

int main()
{
	Singleton *p1 = Singleton::getInstance();

	Singleton *p5 = Singleton::getInstance();
	p1->setValue(10);
	cout << "P1 address = " << p1 << " Value = " << p1->getValue() <<  '\n';
	p5->setValue(50);
	Singleton *p2 = Singleton::getInstance();

	cout << "P2 address = " << p2 << " Value = " << p2->getValue() <<'\n';

}