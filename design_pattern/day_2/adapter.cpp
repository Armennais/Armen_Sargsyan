#include <iostream>
#include <cmath>

using namespace std;

class RoundPeg
{
private:
    double _radius;
public:
    RoundPeg(){}
    RoundPeg(double radius){
        this->_radius = radius;
    }
    ~RoundPeg(){}
    virtual double getRadius() const
    {
        return _radius;
    }
};

class RoundHole{
private:
    double _radius;
public:
    RoundHole(){}
    RoundHole(double radius){
        this->_radius = radius;
    }
    ~RoundHole(){}
    double getRadius() const
    {
        return _radius;
    }
    bool fits(RoundPeg * peg)
    {
        return getRadius() >= peg->getRadius(); 
    }

};

class SquarePeg
{
private:
    double _width;
public:
    SquarePeg(){}
    SquarePeg(double width)
    {
        this->_width = width;
    }
    ~SquarePeg(){};
    double getWidth() const
    {
        return _width;
    }
};

class SquarePegAdapter: public RoundPeg
{
private:
    SquarePeg * _peg;
public:
    SquarePegAdapter(){}
    SquarePegAdapter(SquarePeg * peg)
    {
        this->_peg = peg;
    }
    ~SquarePegAdapter()
    {
        delete _peg;
        _peg = NULL;
    }
    double getRadius() const override
    {
        return _peg->getWidth() * sqrt(2.0) / 2.0;
    }
};

int main(){
    RoundHole * round_hole = new RoundHole(5.0);
    RoundPeg * round_peg = new RoundPeg(4.0);
    cout << round_hole->fits(round_peg) << endl;

    SquarePeg* peg1 = new SquarePeg(8.0);
    SquarePegAdapter* adapter = new SquarePegAdapter(peg1);
    cout << round_hole->fits(adapter) << endl;
    return 0;   
}