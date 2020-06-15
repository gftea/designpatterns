#include <iostream>
using namespace std;

class Product
{
public:
    Product()
    {
        _cnt = 0;
    }
    virtual void setPartA()
    {
        cout << "Product set part A" << endl;
        _cnt += 1;
    }
    virtual void setPartB()
    {
        cout << "Product set part B" << endl;
        _cnt += 2;
    }

    virtual bool isCompleteProduct()
    {
        return _cnt >= 2 ? true : false;
    }

private:
    int _cnt; //count the number of parts are built
};

class Builder
{
public:
    virtual void buildProduct() = 0;
    virtual void buildPartA() = 0;
    virtual void buildPartB() = 0;
};

class ConcreteBuilder : public Builder
{
public:
    ConcreteBuilder()
    {
        _product = 0;
    }

    virtual void buildProduct()
    {
        _product = new Product;
    }
    virtual void buildPartA()
    {
        _product->setPartA();
    }

    virtual void buildPartB()
    {
        _product->setPartB();
    }

    virtual Product *getResult()
    {
        return _product;
    }

private:
    Product *_product;
};

class Director
{
public:
    void construct(Builder *builder)
    {
        // construct process is independent of how the parts are built
        builder->buildProduct();
        builder->buildPartA();
        builder->buildPartB();
    }
};

int main(int argc, const char *argv[1])
{
    ConcreteBuilder *aBuilder = new ConcreteBuilder;
    Director *aDirector = new Director;
    aDirector->construct(aBuilder);
    Product *aProduct = aBuilder->getResult();
    cout << "Is it a complete product: " << aProduct->isCompleteProduct() << endl;
}