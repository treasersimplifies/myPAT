//typical input : 3 4 -5 2 6 1 -2 0
// means : 3x^4 -5x^2 +6x -2
//typical output: 12 3 -10 1 6 0
// means : 12x^3 +3x^2 -10x + 6
#include <iostream>
using namespace std;

int main () {
	int a,b;
	int flag=0;

	while(cin >> a >>b){
		if(b){
			if(flag)
				cout<<" ";
			cout << a*b <<" "<< b-1;
			flag=1;
		}
	}
	if(flag == 0)
		cout<<"0 0";

	return 0;
}