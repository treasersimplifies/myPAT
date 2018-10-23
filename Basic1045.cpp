#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

//int a[100000],m[100000];

int main(){
	int frontflag=-1;
	int behindflag=-1;
	int mcount=0;
	int N=0;
	cin >> N;
	int *a = new int[N];
	int *m = new int[N];

	for(int i=0;i<N;i++){
		cin >> a[i];
	}

	for(int i=0;i<N;i++){
		int j;
		for(j=0;j<i;j++){
			if(a[j]>a[i]){
				frontflag = -1; // not
				break;
			}
		}
		if(i==j) frontflag = j;
		for(j=i+1;j<N;j++){
			if(a[j]<a[i]){
				frontflag = -1;
				break;
			}
		}
		if(j==N) behindflag = j;
		if(frontflag!=-1&&behindflag!=-1){
			//cout << a[i];
			m[mcount]=a[i];
			mcount++;
			
		}
	}

	cout << mcount <<endl;
	for(int i=0;i<mcount;i++){
		cout << m[i];
		if(i<mcount-1)
			cout << " ";
	}

	return 0;

}
