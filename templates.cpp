#include<iostream>
using namespace std;



template<class myType>
myType add(myType a ,myType b){
    return a+b;
}
//int add(int x, int y);

int main()
{

    int x = 34;
    int y = 342;
    cout<<"The sum of "<<x<<" and "<<y<<" : "<<add(x,y)<<endl;
    return 0;
}
//int add(int x, int y){ return x+y;}