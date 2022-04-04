#include <iostream>
using namespace std;

int main(){
    // const int i;

    const int i=10;
    int const i2=10;
    // i++

    //constant reference from a non const int
    int j=12;
    const int & k=j;
    // k++;
    j++;

    //constant reference form a const int
    int const j2=12;
    int const &k2 =j2;
    // j2++;
    // k2++;

    //reference from a const int
    int const j3=123;
    // int &k3=j3;

}