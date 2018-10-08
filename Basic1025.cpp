#include <iostream>
#include <algorithm>
//邻接表法
using namespace std;
int main(){
	int firstaddr,N, K;
	cin >> firstaddr >> N >> K;

	int data[100000],next[100000],address;
	for(int i=0;i<N;i++){
		cin >> address;
		cin >> data[address] >> next[address];
	}

	int list[100000];//N<100000
	int temp=firstaddr;
	int len=0;
	while(temp!=-1){
		list[len++]=temp;
		temp=next[temp];
	}

	for(int i=0;i<len/K;i+=1)
		reverse(begin(list)+i*K,begin(list)+i*K+K);

	for(int i=0;i<len-1;i++)
		printf("%05d %d %05d\n", list[i], data[list[i]], list[i + 1]);//cout<< list[i] << " " << data[list[i]] << " " << list[i+1] <<endl;
	
	printf("%05d %d -1", list[len - 1], data[list[len - 1]]);
	return 0;
}