#include <iostream>
#include <cstring>

using namespace std;

class Generator{
private:
    static size_t seq;
public:
    static size_t getNext(){
        return ++seq;
    }
};

size_t Generator::seq = 0;


class Account{
private:
    char* name;
    size_t ID;
public:
    Account(const char* name){
        this->name = new char[strlen(name)+1];
        strcpy(this->name, name);
        this ->ID = Generator::getNext();
    }
    friend ostream& operator<<(ostream& os, const Account& acc){
        return os << acc.name << acc.ID << endl;
    }
    ~Account(){
        delete [] name;
    }
};
int main(){
    Generator g;
    Generator t;
    cout << g.getNext() << endl;
    cout << t.getNext() << endl;
    Account stoyan("Stoyan");
    Generator::getNext();
    Account niki("Niki");
    cout << stoyan << niki;
    return 0;
}