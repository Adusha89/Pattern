#ifndef STRATEGY
#define STRATEGY

#include <iostream>
#include <fstream>

class IDivideMethod
{
public:
    virtual void Divide(std::string&, size_t) = 0;
    virtual ~IDivideMethod(){};
};

class DivideByScreenWidth : public IDivideMethod
{
private:
public:
    void Divide(std::string& text, size_t EditorWidth) override
    {
        std::cout << "DivideByScreenWidth by screen width = " << EditorWidth << std::endl;
    }
};

class DivideBySentence : public IDivideMethod
{
public:
    void Divide(std::string& text, size_t EditorWidth) override
    {
        std::cout << "Divided by Sentences" << std::endl;
    }
};

class DivideByUserWidth : public IDivideMethod
{
public:
    void Divide(std::string& text, size_t EditorWidth) override
    {
        std::cout << "DivideByScreenWidth by screen width = " << EditorWidth << std::endl;
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
        divide->Divide(all_text, 55);
    }
    
};

#endif