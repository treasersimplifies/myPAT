#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

//解释： P A T ， 以A为中心，对每一个A，位于其前面的P的数量*位于其后T的数量=对于这个A的所有PAT数量,
//对每个A做遍这种，就能得到总的PAT数量。

int main(){
	string in;
	cin >> in;
	int Count_P=0;
	int Count_T=0;
	int total=0;

	for(int i=0;i<in.length();i++)
		if(in[i]=='T')
			Count_T++;

	for (int i = 0; i < in.length(); i++)
	{
		if(in[i]=='P') Count_P++;
		if(in[i]=='T') Count_T--;
		if(in[i]=='A') total = (total + Count_P*Count_T%1000000007)%1000000007;
	}
	cout<<total;
	return 0;

}
