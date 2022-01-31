#ifndef DECORATOR
#define DECORATOR

#include <iostream>
#include <string>

class Beverage // Абстрактный класс
{           
public:
   virtual std::string getDescription() const = 0;
   virtual double cost() const = 0;
   virtual ~Beverage() {}
};

class HouseBlend: public Beverage  // Молотый
{ 
public:
    std::string getDescription() const override
    {
        return "HouseBlend ";
    }
   double cost() const override 
   {
       return 5.5;
   }
};

class DarkRoast: public Beverage // Темной обжарки
{ 
public:
    std::string getDescription() const override
    {
        return "DarkRoast ";
    }
   double cost() const override 
   {
       return 6.0;
   }
};
 
class Decaf: public Beverage  // Без кофеина
{  
public:
    std::string getDescription() const override
    {
        return "Decaf ";
    }
   double cost() const override 
   {
       return 7.3;
   }
};

class Espresso: public Beverage // Эспрессо
{ 
public:
    std::string getDescription() const override
    {
        return "Espresso ";
    }
   double cost() const override 
   {
       return 3.5;
   }
};

class Add : public Beverage
{
protected:
    Beverage* beverage;
public:
    Add(Beverage* _beverage) : beverage(_beverage) {}

    std::string getDescription() const override
    {
        return beverage->getDescription();
    }
    double cost() const override
    {
        return beverage->cost();
    }
};

class ChocolateAdd : public Add
{
public:
    ChocolateAdd(Beverage* _beverage) : Add(_beverage){}

    std::string getDescription() const override
    {
        return Add::getDescription() + "with chocolate ";
    }

    double cost() const override
    {
        return Add::cost() + 0.5;
    }
};

class CinnamonAdd : public Add
{
public:
    CinnamonAdd(Beverage* _beverage) : Add(_beverage){}

    std::string getDescription() const override
    {
        return Add::getDescription() + "with cinnamon ";
    }

    double cost() const override
    {
        return Add::cost() + 0.4;
    }
};

class WhippedCreamAdd : public Add
{
public:
    WhippedCreamAdd(Beverage* _beverage) : Add(_beverage){}

    std::string getDescription() const override
    {
        return Add::getDescription() + "with wpipped cream ";
    }

    double cost() const override
    {
        return Add::cost() + 0.6;
    }
};

class NoSugarAdd : public Add
{
public:
    NoSugarAdd(Beverage* _beverage) : Add(_beverage){}

    std::string getDescription() const override
    {
        return Add::getDescription() + "without sugar ";
    }

    double cost() const override
    {
        return Add::cost() - 0.2;
    }
};

void client()
{
    Beverage* coffee = new NoSugarAdd(new ChocolateAdd(new HouseBlend));
    coffee = new WhippedCreamAdd(coffee);
    std::cout << coffee->cost() << std::endl;
    std::cout << coffee->getDescription() << std::endl;
}
#endif