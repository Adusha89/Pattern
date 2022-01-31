#ifndef COMMAND
#define COMMAND

#include <iostream>

enum class Direction
{
    FORWARD,
    BACK
};

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
    virtual bool getState() const
    {
        return light->getState();
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
    ChangeColorCommand(Colors newColor) : color(newColor) {}
    void Execute() override
    {
        light->changeColor(color);
    }
private:
    Colors color;
};

class ControlLight
{
private:
    Light* light;
    Command* pCommand;
    bool state;
    
public:
    ControlLight(Light* _light) : light(_light), pCommand(nullptr) 
    {
        state = light->getState();
    }

    void on()
    {
        if(!state)
        {
            pCommand = new OnCommand;
            pCommand->SetLight(light);
            pCommand->Execute();
            state = pCommand->getState();
            delete pCommand;
        }
    }

    void off()
    {
        if(state)
        {
            pCommand = new OffCommand;
            pCommand->SetLight(light);
            pCommand->Execute();
            state = pCommand->getState();
            delete pCommand;
        }
    }

    void flicker(const Direction& dir)
    {
        if(!state)
        {
            pCommand = new OnCommand;
            pCommand->SetLight(light);
            pCommand->Execute();
            state = pCommand->getState();
            delete pCommand;
        }
        else
        {
            switch (dir)
            {
            case Direction::FORWARD :
                for (size_t idx = 0; idx < 8; ++idx)
                {
                    pCommand = new ChangeColorCommand(static_cast<Colors>(idx));
                    pCommand->Execute();
                    delete pCommand;
                }
                break;

            case Direction::BACK :
                for (size_t idx = 6; idx >= 0; ++idx)
                {
                    pCommand = new ChangeColorCommand(static_cast<Colors>(idx));
                    pCommand->Execute();
                    delete pCommand;
                }
                pCommand = new ChangeColorCommand(Colors::WHITE);
                pCommand->Execute();
                delete pCommand;
                break;
            }
            
        }
    }


};

#endif