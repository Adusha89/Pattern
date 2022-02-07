#ifndef BUILDER
#define BUILDER

#include <iostream>
#include <vector>

class Events{
public:
   virtual void getEvent() = 0;
   virtual ~Events() {};
};

class Hotel: public Events{
public:
   void getEvent() {
       std::cout << "Booking Hotel" << std::endl;
   }
};

class Park: public Events{
   void getEvent() {
       std::cout << "Park visiting" << std::endl;
   }
};

class Food: public Events{
public:
   virtual void getEvent() = 0;
   virtual ~Food() {};
};

class Dinner: public Food{
public:
   Dinner() : _type("Dinner") {}
   void getEvent(){
       std::cout << "Food " << _type << std::endl;
   } 
private:
   std::string _type;
};

class Lunch: public Food{
public:
   Lunch() : _type("lunch") {}
   void getEvent(){
       std::cout << "Food " << _type << std::endl;
   } 
private:
   std::string _type;
};

class Breakfast: public Food{
public:
   Breakfast() : _type("breakfast") {}
   void getEvent(){
       std::cout << "Food " << _type << std::endl;
   } 
private:
   std::string _type;
};

class Special: public Events{
public:
   virtual void getEvent() = 0;
   virtual ~Special() {};
};

class Skating:public Special{
public:
   Skating() : _type("Skating") {}
   void getEvent(){
       std::cout << _type << std::endl;
   } 
private:
   std::string _type;
};

class Circus:public Special{
public:
   Circus() : _type("Circus") {}
   void getEvent(){
       std::cout << _type << std::endl;
   } 
private:
   std::string _type;
};

class Plan
{
private:
    std::vector<Events*> events;
    std::vector<Food*> food;
    std::vector<Special*> special;

public:
    void infoAboutDay() const
    {
        for(const auto& e : events)
        {
            e->getEvent();
        }
        std::cout << std::endl;
    }
    void setEvents(Events* ev)
    {
        events.push_back(ev);
    }
};

class HollyDay
{
protected:
    Plan* plan = nullptr;

public:
    virtual ~HollyDay(){}
    virtual void createDay(){}
    virtual void addHotel(){}
    virtual void addPark(){}
    virtual void addDinner(){}
    virtual void addLunch(){}
    virtual void addBreakFast(){}
    virtual void addSkating(){}
    virtual void addCircus(){}
    virtual Plan* getPlan()
    {
        return plan;
    }

};

class Day1 : public HollyDay
{
public:
    void createDay()
    {
        plan = new Plan;
    }
    void addHotel()
    {
        plan->setEvents(new Hotel());
    }
    void addPark()
    {
        plan->setEvents(new Park());
    }
    void addDinner()
    {
        plan->setEvents(new Dinner());
    }
};

class Day2 : public HollyDay
{
public:
    void createDay()
    {
        plan = new Plan;
    }
    void addHotel()
    {
        plan->setEvents(new Hotel());
    }
    void addPark()
    {
        plan->setEvents(new Park());
    }
    void addBreakFast()
    {
        plan->setEvents(new Breakfast());
    }
    void addDinner()
    {
        plan->setEvents(new Dinner());
    }
    void addSkating()
    {
        plan->setEvents(new Skating());
    }
};

class Director
{
public:
    Plan* createPlan(HollyDay* hollyday)
    {
        hollyday->createDay();
        hollyday->addHotel();
        hollyday->addPark();
        hollyday->addBreakFast();
        hollyday->addLunch();
        hollyday->addDinner();
        hollyday->addCircus();
        hollyday->addSkating();
        return hollyday->getPlan();
    }
};

#endif