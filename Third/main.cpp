#include <iostream>
#include "Strategy.hpp"

int main(int argc, char const *argv[])
{
    TextEditor text;

    DivideByScreenWidth* BSW = new DivideByScreenWidth(55);
    DivideBySentence* DBS = new DivideBySentence;
    DivideByUserWidth* BUW = new DivideByUserWidth(45);

    text.getDivide(BSW);
    text.useDivide();

    text.getDivide(DBS);
    text.useDivide();

    text.getDivide(BUW);
    text.useDivide();

    return 0;
}
