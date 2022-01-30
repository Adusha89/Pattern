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
    virtual ~Pizza(){};
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

class Factory
{
public:
    virtual Pizza* createOrder() = 0;
    virtual ~Factory() {};
};

class CheesePizzaFactory : public Factory
{
    Pizza* createOrder() override
    {
        return new CheesePizza;
    }
};

class GreekPizzaFactory : public Factory
{
    Pizza* createOrder() override
    {
        return new GreekPizza;
    }
};

class PepperoniPizzaFactory : public Factory
{
    Pizza* createOrder() override
    {
        return new PepperoniPizza;
    }
};

Pizza* orderPizza(Factory& factory)
{
   return factory.createOrder();
}

#endif