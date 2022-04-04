#include <iostream>
using namespace std;

int main(){
    int const i=10;

    // int *p=&i;

    int const *p=&i;

    // (*p)++;

    int j=12;
    int const *p2=&j;
    cout<<*p2<<endl;
    j++;
    
}