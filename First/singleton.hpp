#ifndef SINGLETON
#define SINGLETON

class ChocolateBoiler
{
private:
    bool _empty;
    bool _boiled;
    static ChocolateBoiler* _uniqueInst;
    ChocolateBoiler() : _empty(true), _boiled(false) {}

public:
    ChocolateBoiler(ChocolateBoiler& other) = delete;
    void operator=(ChocolateBoiler&) = delete;
    static ChocolateBoiler* GetInst();
    ~ChocolateBoiler();
    bool isEmpty() const;
    bool isBoiled() const;
    void fill();
    void drain();
    void boil();
};

ChocolateBoiler::~ChocolateBoiler()
{
    delete _uniqueInst;
}

ChocolateBoiler* ChocolateBoiler::_uniqueInst = nullptr;

ChocolateBoiler* ChocolateBoiler::GetInst()
{
    if (_uniqueInst == nullptr)
    {
        _uniqueInst = new ChocolateBoiler();
    }

    return _uniqueInst;
}

bool ChocolateBoiler::isEmpty() const
{
    return _empty;
}

bool ChocolateBoiler::isBoiled() const
{
    return _boiled;
}

//Заполнение
void ChocolateBoiler::fill()
{
    if (isEmpty())
    {
        _empty = false;
        _boiled = false;
    }
}

//Опустошить
void ChocolateBoiler::drain()
{
    if (!isEmpty() && isBoiled())
    {
        _empty = true;
    }
}
    
//Нагревание
void ChocolateBoiler::boil()
{
    if (!isEmpty() && !isBoiled())
    {
        _boiled = true;
    }
}
#endif
