#include <iostream>
#include "Strategy.hpp"
#include "Iterator.hpp"

int main(int argc, char const *argv[])
{
    TextEditor text;

    IDivideMethod* BSW = new DivideByScreenWidth;
    IDivideMethod* DBS = new DivideBySentence;
    IDivideMethod* BUW = new DivideByUserWidth;

    text.getDivide(BSW);
    text.useDivide();

    text.getDivide(DBS);
    text.useDivide();

    text.getDivide(BUW);
    text.useDivide();

    VectorContainer<Class1> vc;
    vc.Add(Class1());
    vc.Add(Class1());

    ListContainer<Class2> lc;
    lc.Add(Class2());
    lc.Add(Class2());

    Iterator<Class1>* ivc = vc.createIterator();
    Iterator<Class2>* ilc = lc.createIterator();

    while (ivc->hasNext())
    {
        ivc->getNext().info();
    }

    while (ivc->hasPrev())
    {
        ivc->getPrev().info();
    }

    while (ilc->hasNext())
    {
        ilc->getNext().info();
    }

    while (ilc->hasPrev())
    {
        ilc->getPrev().info();
    }

    return 0;
}
