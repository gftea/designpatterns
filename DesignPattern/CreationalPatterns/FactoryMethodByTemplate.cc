#include <iostream>
using namespace std;

class Product
{
public:
    virtual void show() = 0;
};

class ConcreteProductA : public Product
{
public:
    virtual void show()
    {
        cout << "concrete product A" << endl;
    }
};

class ConcreteProductB : public Product
{
public:
    virtual void show()
    {
        cout << "concrete product B" << endl;
    }
};

class Creator
{
public:
    void display()
    {
        Product *aProduct = makeProduct();
        aProduct->show();
    };

    //factory methods
    virtual Product *makeProduct() = 0;
};

template <class TheProduct>
class StandardCreator : public Creator
{
public:
    virtual Product *makeProduct()
    {
        return new TheProduct;
    }
};

int main(int argc, const char *argv[1])
{
    Creator *aCreator;
    aCreator = new StandardCreator<ConcreteProductA>;
    aCreator->display();
    aCreator = new StandardCreator<ConcreteProductB>;
    aCreator->display();
}