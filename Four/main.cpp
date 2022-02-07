#include <iostream>
#include "FabricMethod.hpp"
#include "Builder.hpp"

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
    return 0;
}
