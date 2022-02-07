#include <iostream>
#include "FabricMethod.hpp"
#include "Builder.hpp"
#include "Bridge.hpp"

int main(int argc, char const *argv[])
{
    Director dir;

    HollyDay* day1 = new Day1;
    HollyDay* day2 = new Day2;

    Plan* d1 = dir.createPlan(day1);
    Plan* d2 = dir.createPlan(day2);

    std::cout << "First day: " << std::endl;
    d1->infoAboutDay();
    std::cout << "Second day: " << std::endl;
    d2->infoAboutDay();
    std::cout << std::endl;

    DrawingImplementor* draw = new DrawingWithBrush;
    Shape* rec = new Rectangle(draw);
    rec->draw(23);
    delete rec;

    rec = new Rectangle(new DrawingWithPencil);
    rec->draw(24);
    delete rec;
    return 0;
}
