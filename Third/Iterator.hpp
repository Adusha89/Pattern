#ifndef ITERATOR
#define ITERATOR

#include <list>
#include <array>
#include <vector>
#include <deque>
#include <iostream>

template <class T>
class Iterator
{
public:
    virtual bool hasNext() const = 0;
    virtual bool hasPrev() const = 0;
    virtual T getNext() = 0;
    virtual T getPrev() = 0;
};

template <class T>
class ListIterator : public Iterator<T>
{
private:
    std::list<T> container;
    int position;
public:
    ListIterator(const std::list<T>& _container) : container(_container), position(0){}
    bool hasNext() const override
    {
        return position < container.size();
    }

    bool hasPrev() const override
    {
        return position > 0;
    }

    T getNext() override
    {
        return *(std::next(container.begin(), position++));
    }

    T getPrev() override
    {
        return *(std::prev(std::next(container.begin(), position--)));
    }

};

template <class T>
class ArrayIterator : public Iterator<T>
{
private:
    std::array<T, 10> container;
    int position;
public:
    ArrayIterator(const std::array<T, 10>& _container) : container(_container), position(0){}
    bool hasNext() const override
    {
        return position < container.size();
    }

    bool hasPrev() const override
    {
        return position > 0;
    }

    T getNext() override
    {
        return *(std::next(container.begin(), position++));
    }

    T getPrev() override
    {
        return *(std::prev(std::next(container.begin(), position--)));
    }

};

template <class T>
class VectorIterator : public Iterator<T>
{
private:
    std::vector<T> container;
    int position;
public:
    VectorIterator(const std::vector<T>& _container) : container(_container), position(0){}
    bool hasNext() const override
    {
        return position < container.size();
    }

    bool hasPrev() const override
    {
        return position > 0;
    }

    T getNext() override
    {
        return *(std::next(container.begin(), position++));
    }

    T getPrev() override
    {
        return *(std::prev(std::next(container.begin(), position--)));
    }

};

template <class T>
class DequeIterator : public Iterator<T>
{
private:
    std::deque<T> container;
    int position;
public:
    DequeIterator(const std::deque<T>& _container) : container(_container), position(0){}
    bool hasNext() const override
    {
        return position < container.size();
    }

    bool hasPrev() const override
    {
        return position > 0;
    }

    T getNext() override
    {
        return *(std::next(container.begin(), position++));
    }

    T getPrev() override
    {
        return *(std::prev(std::next(container.begin(), position--)));
    }

};

class Class1
{
public:
    void info() const
    {
        std::cout << "Class1 ";
    }
};

class Class2
{
public:
    void info() const
    {
        std::cout << "Class2 ";
    }
};

template<class T>
class VectorContainer
{
private:
    std::vector<T> data;
public:
    Iterator<T>* createIterator()
    {
        return new VectorIterator<T>(data);
    }
    void Add(T _data)
    {
        data.push_back(_data);
    }
};

template<class T>
class DequeContainer
{
private:
    std::deque<T> data;
public:
    Iterator<T>* createIterator()
    {
        return new DequeIterator<T>(data);
    }
    void Add(T _data)
    {
        data.push_back(_data);
    }
};

template<class T>
class ArrayContainer
{
private:
    std::array<T, 10> data;
public:
    Iterator<T>* createIterator()
    {
        return new ArrayIterator<T>(data);
    }
    void Add(T _data)
    {
        data.push_back(_data);
    }
};

template<class T>
class ListContainer
{
private:
    std::list<T> data;
public:
    Iterator<T>* createIterator()
    {
        return new ListIterator<T>(data);
    }
    void Add(T _data)
    {
        data.push_back(_data);
    }
};
#endif