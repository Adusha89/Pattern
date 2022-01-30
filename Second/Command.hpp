#ifndef COMMAND
#define COMMAND

enum class Colors 
{
   RED,
   ORANGE,
   YELLOW,
   GREEN,
   CYAN,
   BLUE,
   VIOLET,
   WHITE
};

class Light
{
public:
   Light():state(false), color(Colors::WHITE){};
   void On()
   {
       if(!state)
       {
           state = true;
       }
   };

   void Off()
   {
       if(state)
       {
           state = false;
       }
   };
  
   void changeColor(Colors newColor)
   {
       color = newColor;
   }
  
   bool getState() const 
   {
       return state;
   }

private:
   bool state;
   Colors color;
};

class Command
{
protected:
    Light* light;

public:
    virtual void Execute() = 0;
    virtual void SetLight(Light* _light)
    {
        light = _light;
    }
    virtual ~Command() {};
};

class OnCommand : public Command
{
public:
    void Execute() override
    {
        light->On();
    }
};

class OffCommand : public Command
{
public:
    void Execute() override
    {
        light->Off();
    }
};

class ChangeColorCommand : public Command
{
public:
    ChangeColorCommand(Colors _color) : color(_color) {}
    void Execute() override
    {
        light->changeColor(color);
    }
private:
    Colors color;
};

class GetStateCommand : public Command
{
public:
    void Execute() override
    {
        light->Off();
    }
};
#endif