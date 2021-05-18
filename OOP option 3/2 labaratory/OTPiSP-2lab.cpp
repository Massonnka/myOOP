#include <iostream>
#include <list>

using namespace std;

class	Cadr {
public:
    int man;
    Cadr(int x) {
        man = x;
        cout << "the number of card created " << this->man << endl;
    };
    ~Cadr() {
        cout << "Cadr deleted" << endl;
    };
};

class Admin :public Cadr{
public:
    int slevel;
    Admin(int a, int x) : Cadr(x) {
        slevel = a;
        cout << "An Admin is created with a level of work " << this->slevel << endl;
    }
    ~Admin() {
        cout << "Deleted Admin element";
    }
};

class Worker :public Cadr {
public:
    int staj;
    Worker(int s, int x) :Cadr(x) {
        staj = s;
        cout << "An experienced Worker item is being created "<< this->staj << endl;
    };
    ~Worker(){
        cout << "Deleted Worker element" << endl;
    };
};

class Engineer :public Worker {
public:
    int expe;
    Engineer(int f, int s, int x) :Worker(s, x) {
        expe = f;
        cout << "Created element engineer with experience " << this->expe << endl;
    }
    ~Engineer() {
        cout << "Deleted engineer element" << endl;
    }
};

int main()
{
    typedef unique_ptr<Cadr> TList;
    list <TList> list1;

    list1.push_back(TList( new Worker(25,10)));
    list1.push_back(TList( new Engineer(10, 25, 50)));
    list1.push_back(TList( new Admin(15, 100)));

    for (TList const& lst : list1) {
        cout <<lst->man<<endl;
    }
}
