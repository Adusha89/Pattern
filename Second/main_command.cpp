#include <iostream>
#include <vector>



class Document{
public:
    std::vector<std::string> data;

    Document() {
        data.reserve(100);
    }

    void Insert(int line, const std::string& str){
        if(line <= data.size()){
            data.insert(data.begin() + line, str);
        }
        else{
            std::cerr << "Error!" << std::endl;
        }
    }

    void Remove(int line){
        if (line <= data.size())
            data.erase(data.begin() + line);
        else{
            std::cerr << "Error!" << std::endl;
        }
    }

    std::string& operator[] (int x){
        return data[x];
    }

    void Show(){
        for (int i = 0; i < data.size(); ++i) {
            std::cout << i+1 << ". " << data[i] << std::endl;
        }
    }
};

class Command{
protected:
    Document* doc;
public:
    virtual ~Command() {};
    virtual  void Execute() = 0;
    virtual void Back() = 0;

    void setDocument(Document* _doc){
        doc = _doc;
    }
};

class InsertCommand : public Command{
    int line;
    std::string str;
public:
    InsertCommand(int line, const std::string &str) : line(line), str(str) {}

    void Execute() override{
        doc -> Insert(line, str);
    }

    void Back() override{
        doc ->Remove(line);
    }
};


class Invoker{
    std::vector<Command*> DoneCommands;
    Document doc;
    Command* pCommand;

public:
    Invoker() : pCommand(nullptr) {}
    ~Invoker(){
        for(Command* ptr: DoneCommands){
            delete ptr;
        }
    }

    void Insert(int line, std::string str){
        pCommand = new InsertCommand(line,str);
        pCommand->setDocument(&doc);
        pCommand->Execute();
        DoneCommands.push_back(pCommand);
    }

    void Undo(){
        if (DoneCommands.size() != 0){
            pCommand = DoneCommands.back();
            DoneCommands.pop_back();
            pCommand->Back();
            delete pCommand;
        }
        else{
            std::cerr << "No any commands" << std::endl;
        }
    }

    void Show(){
        doc.Show();
    }
};

int main(){
    std::vector<std::string> strings = {"first","second","third","fourth","fifth","sixth","seventh"};
    Invoker inv;

    for (int i = 0; i < strings.size(); ++i) {
        inv.Insert(i, strings[i]);
    }

    inv.Show();

    for (int i = 0; i < strings.size(); ++i) {
        inv.Undo();
    }

    inv.Show();

    return 0;
};




