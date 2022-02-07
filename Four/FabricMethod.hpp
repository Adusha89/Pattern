#ifndef FABRICMETHOD
#define FABRICMETHOD

#include <string>


class Pizza{
public:
   virtual void prepare(std::string);
   virtual void bake() {};
   virtual void cut() {};
   virtual void box() {};
};

class CheesePizza:public Pizza{};
class GreekPizza:public Pizza{};
class PepperoniPizza:public Pizza{};

class PizzaFabric
{
public:
    virtual Pizza* createPizza() = 0;
    virtual ~PizzaFabric();
};

class CheesePizzaFabric : public PizzaFabric
{
public:
    Pizza* createPizza() override
    {
        return new CheesePizza;
    }
};

class GreekPizzaFabric : public PizzaFabric
{
public:
    Pizza* createPizza() override
    {
        return new GreekPizza;
    }
};

class PepperoniPizzaFabric : public PizzaFabric
{
public:
    Pizza* createPizza() override
    {
        return new PepperoniPizza;
    }
};

Pizza* orderPizza(PizzaFabric* pizza){
   return pizza->createPizza();
}

#endif

