#include <iostream>
#include <cstring>
using namespace std;

class SingleDog {
public:
    //constructor
    SingleDog(int id_, char* name_);

    //copy constructor
    SingleDog(const SingleDog &other);

    //desctructor
    ~SingleDog();

    //return the count of single dog
    static int getCount();

    //print some infomation
    void print() const {
        cout << "SingleDog " << id << ". My name is " << name << endl;
    }

private:
    const int id;
    char *name;
    static int count; // the count of single dog
};

int SingleDog::count = 0;

SingleDog::SingleDog(int id_, char* name_):id(id_) {
    name = (char *)malloc(1100 * sizeof(char));
    strcpy(this -> name, name_);
    count++;
}

SingleDog::SingleDog(const SingleDog &other):id(other.id) {
    name = (char *)malloc(1100 * sizeof(char));
    strcpy(this -> name, other.name);
    count++;
}

SingleDog::~SingleDog() {
    free(this -> name);
    count--;
}

int SingleDog::getCount(){return count;}

void printCount() {
    cout << "Number of SingleDog: " << SingleDog::getCount() << endl;
}


int main() {
    char name[20] = "wangwang";
    int num;
    cin >> num;
    SingleDog dog(0, name), *p;

    for (int i = 1; i <= num; ++i) {
        cin >> name;
        SingleDog a(i, name);

        if (i % 2 != 0) {
            p = new SingleDog(i, name);
            printCount();
            p->print();
            delete p;

        } else {
            SingleDog b(a);
            printCount();
            b.print();
        }
    }

    printCount();
    dog.print();

    return 0;
}

