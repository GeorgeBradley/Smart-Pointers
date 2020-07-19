// Smart Pointers.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <vector>
#include <memory>

class Test 
{
private:
    int iNumber;
public:

    Test():Test(0) {

    }
    Test(int iNumber) :iNumber(iNumber) {

    }
    int Get_Num()const 
    {
        return iNumber;
    }
    ~Test() {

    }
};

std::unique_ptr<std::vector<std::shared_ptr<Test>>>get() 
{

    std::unique_ptr <std::vector <std::shared_ptr<Test>>>vec = std::make_unique<std::vector<std::shared_ptr<Test>>>();
    return vec;
        
}
void fill(std::unique_ptr<std::vector<std::shared_ptr<Test>>>& vec, int iHowManyNumbers) {

   
    int iNumber = 0;
    for (int iCount = 0; iCount < iHowManyNumbers; iCount++)
    {
        
        std::cout << iCount + 1 << ". Enter a number: ";
        std::cin >> iNumber;
        std::shared_ptr<Test> temp = std::make_shared<Test>(iNumber);
        vec->push_back(temp);
    }
}
void display(std::unique_ptr<std::vector<std::shared_ptr<Test>>>&vec) 
{
    for (auto v : *vec)
    {
        std::cout << v->Get_Num() << std::endl;
    }
}
int main()
{


    int iNumber = 0;
    std::unique_ptr<std::vector<std::shared_ptr<Test>>>ptrVecTest = get();
    std::cout << "How many numbers do you want to enter?: ";
    std::cin >> iNumber;
    fill(ptrVecTest, iNumber);
    display(ptrVecTest);
   
}
