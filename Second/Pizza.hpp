#ifndef PIZZA
#define PIZZA

#include <string>

class Pizza
{
public:
    virtual void prepare() = 0;
    virtual void bake() = 0;
    virtual void cut() = 0;
    virtual void box() = 0;
};

class CheesePizza : public Pizza
{
    void prepare() override {};
    void bake() override {};
    void cut() override {};
    void box() override {};
};
class GreekPizza : public Pizza
{
    void prepare() override {};
    void bake() override {};
    void cut() override {};
    void box() override {};
};
class PepperoniPizza : public Pizza
{
    void prepare() override {};
    void bake() override {};
    void cut() override {};
    void box() override {};
};

class PizzaFactory
{
public:
    virtual Pizza* createOrderPizza() = 0;
    virtual ~PizzaFactory() {};
};

class CheesePizzaFactory : public PizzaFactory
{
    Pizza* createOrderPizza() override
    {
        return new CheesePizza;
    }
};

class GreekPizzaFactory : public PizzaFactory
{
    Pizza* createOrderPizza() override
    {
        return new GreekPizza;
    }
};

class PepperoniPizzaFactory : public PizzaFactory
{
    Pizza* createOrderPizza() override
    {
        return new PepperoniPizza;
    }
};

Pizza* orderPizza(PizzaFactory& factory)
{
   return factory.createOrderPizza();
}

#endif