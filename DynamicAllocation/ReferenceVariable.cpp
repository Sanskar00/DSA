#include <iostream>
using namespace std;

void increment(int &n){
    n++;
}

int&  f(int n){
    int a=n;
    return a;
}

int main(){
    int i=10;
    int &j=i;
    // int &j j should be initialize

    increment(i);
    cout<<i<<endl;

    i++;
    cout<<j<<endl;
    j++;
    cout<<i<<endl;

    int k=100;
    j=k;
    cout<<i<<endl;


}