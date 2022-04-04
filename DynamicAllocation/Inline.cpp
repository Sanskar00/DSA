#include <iostream>
using namespace std;

// int max(int a, int b){
//     return (a>b)?a:b;
// }

inline int max(int a, int b){
    return (a>b)?a:b;
}

int main(){
    int a,b;
    cin>>a>>b;

    int c=max(a,b);
    
    int z= max(a,b);

    cout<<z<<c<<endl;
}