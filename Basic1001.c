
#include <iostream>
using namespace std;

int main(){
    int n=0;
    int steps=0;
    
    cin >> n ;
    for(steps=0;n!=1;steps++){
        if(n%2==0){
            n = n/2;
        }
        else
        {
            n = (3*n+1)/2;
        }
    }
    cout << steps;
    
    return 0;
}
