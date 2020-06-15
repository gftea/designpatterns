#include <iostream>
using namespace std;

/*
Product A and B have different interfaces
*/
class AbstractProductA
{
public:
    virtual void walk() = 0;
};

class ProductA1 : public AbstractProductA
{
public:
    virtual void walk()
    {
        cout << "walk: Product A1" << endl;
    }
};
class ProductA2 : public AbstractProductA
{
public:
    virtual void walk()
    {
        cout << "walk: product A2" << endl;
    }
};

class AbstractProductB
{
public:
    virtual void jump() = 0;
};

class ProductB1 : public AbstractProductB
{
public:
    virtual void jump()
    {
        cout << "jump: product B1" << endl;
    }
};
class ProductB2 : public AbstractProductB
{
public:
    virtual void jump()
    {
        cout << "jump: product B2" << endl;
    }
};

class AbstractFactory
{
public:
    virtual AbstractProductA *createProductA() = 0;
    virtual AbstractProductB *createProductB() = 0;
};

class Factory1 : public AbstractFactory
{
public:
    virtual AbstractProductA *createProductA()
    {
        return new ProductA1;
    }
    virtual AbstractProductB *createProductB()
    {
        return new ProductB1;
    }
};

class Factory2 : public AbstractFactory
{
public:
    virtual AbstractProductA *createProductA()
    {
        return new ProductA2;
    }
    virtual AbstractProductB *createProductB()
    {
        return new ProductB2;
    }
};

/* 
client codes
*/
int main(int argc, const char *argv[1])
{
    AbstractFactory *aFactory = new Factory1;
    AbstractProductA *aProductA = aFactory->createProductA();
    aProductA->walk();
    AbstractProductB *aProductB = aFactory->createProductB();
    aProductB->jump();

    aFactory = new Factory2;
    aProductA = aFactory->createProductA();
    aProductA->walk();
    aProductB = aFactory->createProductB();
    aProductB->jump();
}