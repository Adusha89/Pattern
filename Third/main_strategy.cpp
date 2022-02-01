#include <iostream>
#include <vector>
#include <algorithm>

class SortStrategy {
public:
    virtual void Sort(std::vector<int>&) = 0;
};

class SortSTL: public SortStrategy{
public:
    void Sort(std::vector<int> &_numbers) override {
        std::cout << "STLSort Strategy" << std::endl;
        sort(_numbers.begin(), _numbers.end());
    }
};

class SortBubble: public SortStrategy{
public:
    void Sort(std::vector<int> &_numbers) override {
        std::cout << "BubbleSort Strategy" << std::endl;
        size_t size = _numbers.size();
        int temp;
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (_numbers[j] > _numbers[j + 1]) {
                    temp = _numbers[j];
                    _numbers[j] = _numbers[j + 1];
                    _numbers[j + 1] = temp;
                }
            }
        }
    }
};

class SortInsertion: public SortStrategy{
public:
    void Sort(std::vector<int> &_numbers) override {
        std::cout << "InsertionSort Strategy" << std::endl;
        size_t size = _numbers.size();
        int temp, item;
        for (int counter = 1; counter < size; counter++)
        {
            temp = _numbers[counter];
            item = counter - 1;
            while (item >= 0 && _numbers[item] > temp)
            {
                _numbers[item + 1] = _numbers[item];
                _numbers[item] = temp;
                item--;
            }
        }
    }
};

class Data{
protected:
    SortStrategy* sortStrategy;
public:
    virtual void useStrategy() = 0;
    virtual void setStrategy(SortStrategy*) = 0;
    virtual ~Data() {}
};


class VectorData: public Data{
private:
    std::vector<int> _numbers;
    SortStrategy* sortStrategy;
public:
    VectorData(){
        for (int i = 0; i < 100'000; ++i) {
            _numbers.push_back(rand()%100);
        }
    }

    void printData(int begin, int end) {
        for(int i = begin; i < end; ++i){
            std:: cout << _numbers[i] << " ";
        }
        std::cout << std::endl;
    }

    void useStrategy() override {
        sortStrategy->Sort(_numbers);
    }

    void setStrategy(SortStrategy *strategy) override {
        sortStrategy = strategy;
    }

};


int main() {
    srand( time( nullptr) );
    VectorData vd;

    SortSTL* ss = new SortSTL;
    SortBubble* sb = new SortBubble;
    SortInsertion* si = new SortInsertion;

    vd.setStrategy(ss);
    vd.useStrategy();

    vd.setStrategy(sb);
    vd.useStrategy();

    vd.setStrategy(si);
    vd.useStrategy();


    return 0;
}
