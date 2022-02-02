#include <iostream>
#include "Strategy.hpp"

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

    return 0;
}
