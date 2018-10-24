#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;


int main(){
	// int frontflag=-1;
	// int behindflag=-1;
	int max=0;
	int mcount=0;
	int N=0;
	cin >> N;
	int *a = new int[N];
	int *m = new int[N];
	int *f = new int[N];

	for(int i=0;i<N;i++){
		cin >> a[i];
		m[i]=a[i];
	}
	//Fast Version: By sorted array, the same position as raw array to decide the main element.
	sort(m,m+N);
	for(int i=0;i<N;i++){
		if(a[i]==m[i]&&a[i]>max)
			f[mcount++]=a[i];
		max = a[i]>max?a[i]:max;
	}
	cout << mcount <<endl;
	for(int i=0;i<mcount;i++){
		cout << f[i];cout << endl;
		if(i < mcount -1)
			cout << " ";
	}

	cout << endl;
	return 0;

}
