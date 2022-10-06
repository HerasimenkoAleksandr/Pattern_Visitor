
#include <iostream>
using namespace std;

class ConcreteComponent1;
class ConcreteComponent2;

class Visitor {
public:
    virtual void VisitConcreteComponent( ConcreteComponent1* obj) = 0;
    virtual void VisitConcreteComponent( ConcreteComponent2* obj)  = 0;
};


class Component {
public:
    virtual ~Component() {}
    virtual void Accept(Visitor* visitor) = 0;
};

class ConcreteComponent1 : public Component {
    
public:
    void Accept(Visitor* visitor)  override {
        visitor->VisitConcreteComponent(this);
    }
   
   string ExclusiveMethodOfConcreteComponent() {
        return"Special Method Of ConcreteComponent1";
    }
};

class ConcreteComponent2 : public Component {
   
public:
    void Accept(Visitor* visitor) override {
        visitor->VisitConcreteComponent(this);
    }
    string SpecialMethodOfConcreteComponent() const {
        return "Special Method Of ConcreteComponent2";
    }
};


class ConcreteVisitor1 : public Visitor {
public:
    void VisitConcreteComponent( ConcreteComponent1* obj)  override {
        cout << obj->ExclusiveMethodOfConcreteComponent() << " + ConcreteVisitor1\n";
    }

    void VisitConcreteComponent( ConcreteComponent2* obj)  override {
        std::cout << obj->SpecialMethodOfConcreteComponent() << " + ConcreteVisitor1\n";
    }
};

class ConcreteVisitor2 : public Visitor {
public:
    void VisitConcreteComponent(ConcreteComponent1* obj)  override {
        cout << obj->ExclusiveMethodOfConcreteComponent() << " + ConcreteVisitor2\n";
    }

    void VisitConcreteComponent(ConcreteComponent2* obj)  override {
        std::cout << obj->SpecialMethodOfConcreteComponent() << " + ConcreteVisitor2\n";
    }
};

void ClientCode( Component* obj, Visitor* obj2) {
    
    obj->Accept(obj2);
}

int main() 
{

    Component* A = new ConcreteComponent1();
    Visitor* B = new ConcreteVisitor1();
    cout << "the first component accepts all the actions of the first visitor: " << endl;
    ClientCode(A, B);
    cout << endl;
    A = new ConcreteComponent2();
     B = new ConcreteVisitor1();
    cout << "the second component accepts all the actions of the first visitor: " << endl;
    ClientCode(A, B);

    cout << endl;
    A = new ConcreteComponent1();
    B = new ConcreteVisitor2();
    cout << "the first component accepts all the actions of the second visitor: " << endl;
    ClientCode(A, B);


    return 0;
}


