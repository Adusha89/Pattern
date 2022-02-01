#ifndef STRATEGY
#define STRATEGY

#include <iostream>
#include <fstream>

class IDivideMethod
{
public:
    virtual void Divide() = 0;
    virtual ~IDivideMethod(){};
};

class DivideByScreenWidth : public IDivideMethod
{
private:
    size_t EditorWidth;
public:
    DivideByScreenWidth(size_t _EditorWidth) : EditorWidth(_EditorWidth){}
    void Divide() override
    {
        std::cout << "DivideByScreenWidth by screen width = " << EditorWidth << std::endl;
    }
};

class DivideBySentence : public IDivideMethod
{
public:
    void Divide() override
    {
        std::cout << "Divided by Sentences" << std::endl;
    }
};

class DivideByUserWidth : public IDivideMethod
{
private:
    size_t userWidth;
public:
    DivideByUserWidth(size_t _userWidth) : userWidth(_userWidth){}
    void Divide() override
    {
        std::cout << "DivideByScreenWidth by screen width = " << userWidth << std::endl;
    }
};


class ITextWork
{
protected:
    IDivideMethod* divide;
public:
    virtual void getDivide(IDivideMethod*) = 0;
    virtual void useDivide() = 0;
    virtual ~ITextWork(){}
};

class TextEditor: ITextWork{
private:
    size_t EditorWidth;
    std::string all_text;
public:
    TextEditor(){};
    TextEditor(const std::string &text) : all_text(text) {};

    TextEditor(std::ifstream& file) {
        std::string line;
        if (file.is_open()){
            while (getline(file, line))
            {
                all_text+=line;
            }
        }
    }

    void PrintText() const{
        std::cout << all_text << std::endl;
    }

    void getDivide(IDivideMethod* _divide) override
    {
        divide = _divide;
    }

    void useDivide() override
    {
        divide->Divide();
    }
    
};

#endif