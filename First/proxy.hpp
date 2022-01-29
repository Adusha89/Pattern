#ifndef PROXY
#define PROXY

#include <iostream>
#include <map>
#include <ctime>

class ISellSystem
{
public:
   virtual void changePrice(std::string, float) = 0;
   virtual void sellProduct(std::string) = 0;
   virtual void addProduct(std::string, size_t) = 0;
};


class Automaton: ISellSystem 
{
private:
   std::string location;
   double recieved_money;
   double spent_money;
   std::map <std::string, float> goods_price;
   std::map <std::string, size_t> goods_count;

public:
   Automaton(const std::string &location, double recievedMoney) 
    : location(location), recieved_money(recievedMoney) 
   {
       spent_money = 0.0;
   }

   void changePrice(std::string name, float newPrice) override 
   {
       goods_price[name] = newPrice;
   }

   void sellProduct(std::string name) override
   {
       if(goods_count[name] > 0)
       {
           recieved_money += goods_price[name];
       }
       else
       {
           std::cerr << "Not enough goods" << std::endl;
       }
   }

   void addProduct(std::string name, size_t count) override
   {
       goods_count[name] += count;
   }

   double allMoneyReport() const
   {
       return recieved_money - spent_money;
   }

   const std::string& getLocationReport() const 
   {
       return location;
   }

   std::map <std::string, size_t> goodsCountReport() const
   {
       return goods_count;
   }

   std::map <std::string, float> goodsPriceReport() const
   {
       return goods_price;
   }
};

class ProxyAutomaton: ISellSystem 
{
private:
   std::string location;
   double money_report;
   std::map <std::string, float> goods_price;
   std::map <std::string, size_t> goods_count;
   Automaton* _realAutomaton;
   time_t updateTime;

public:
   ProxyAutomaton(Automaton* realAutomaton) : _realAutomaton(realAutomaton) 
   {
       updateTime = 1;
   }

   void changePrice(std::string name, float newPrice) override 
   {
       _realAutomaton->changePrice(name, newPrice);
   }

   void sellProduct(std::string name) override
   {
       _realAutomaton->sellProduct(name);
   }

   void addProduct(std::string name, size_t count) override
   {
       _realAutomaton->addProduct(name, count);
   }

   double allMoneyReport()
   {
       if (difftime(time(NULL), updateTime) > 3600.0)
       {
           money_report = _realAutomaton->allMoneyReport();
       }
       return money_report;
   }

   const std::string& getLocationReport() 
   {
       if (difftime(time(NULL), updateTime) > 3600.0)
       {
           location = _realAutomaton->getLocationReport();
       }
       return location;
   }

   std::map <std::string, size_t> goodsCountReport()
   {
        if (difftime(time(NULL), updateTime) > 3600.0)
        {
           goods_count = _realAutomaton->goodsCountReport();
        }
        return goods_count;
   }

   std::map <std::string, float> goodsPriceReport()
   {
        if (difftime(time(NULL), updateTime) > 3600.0)
        {
           goods_price = _realAutomaton->goodsPriceReport();
        }
        return goods_price;
   }
};

#endif