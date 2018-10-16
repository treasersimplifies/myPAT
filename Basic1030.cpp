#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
//int < 4*10^9 ?
int main(){
	int N;
	long long p;
	//long a[1000000000];
	cin >> N >> p;
	vector<int> V(N);// MUST be after "cin >> N >> p;"
	//cout << N ;
	
	for(int i=0;i<N;i++){
		cin >> V[i];
		//cout << V[i];
	}

	sort(V.begin(),V.end());

	long m=0;//min
	long M=0;//max
	int maxnum=0;
	int i=0;
	int j=0;
	for(i=0;i<N;i++){
		m=V[i];
		M=m;
		for(j=i;j<N;j++){
			if(V[j]<=m*p)
				M=V[j];
			else
				break;
		}
		if(maxnum<j-i)
			maxnum=j-i;
	}
	cout << maxnum;
	return 0;
}
