#include <iostream>

using namespace std;

int index(int num, int * array,int arraylen){
    for(int i = 0;i<arraylen;i++){
        if(array[i]==num)
            return i;
    }
    return -1;
}

void insertionSort( int * array, int N )
{ /* 插入排序 */
    int P, i;
    int Tmp;
    
    for ( P=0; P<N; P++ ) {
        Tmp = array[P]; /* 取出未排序序列中的第一个元素*/
        for ( i=P; i>0 && array[i-1]<Tmp; i-- )
            array[i] = array[i-1]; /*依次与已排序序列中元素比较并右移*/
        array[i] = Tmp; /* 放进合适的位置 */
    }
}

int main(){
    int len;
    cin >> len;
    const int clen = len;
    int a[clen];
    int flag[clen];// for callatz squeneces;
    int key[clen];
    int p = 0;

    for(int i =0;i<clen;i++)
        flag[i]=0;
    for(int i =0;i<clen;i++)
        key[i]=0;
    for(int i =0;i<clen;i++)
        cin >> a[i];
    
    for(int i=0;i<clen;i++){
        //if(i==0)j=1;
        
        for(int j=0;j<clen;j++){
            if(j==i)j++;
            int num = a[j];
            //cout << num;
            flag[j]=1;//index(num,a,clen)
            //cout << num;
            while(num!=1){
                if(num%2==0){
                    num = num/2;
                    flag[index(num,a,clen)]=1;
                    //cout << num;
                    
                }
                else
                {
                    num = (3*num+1)/2;
                    flag[index(num,a,clen)]=1;
                    //cout << num;
                }
            }
            //cout<<endl;
        }
        
        //cout<<endl;
        if(flag[i]==0){
            //cout<<a[i]<<endl;
            key[p]=a[i];
            p++;
        }
        for(int i =0;i<clen;i++)
            flag[i]=0;
    }
    
    insertionSort(key,p);
    for(int k =0;k<p-1;k++)
    	cout << key[k] << " ";
    cout << key[p];
    cout << endl;
    
    return 0;
}

/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int arr[10000];
bool cmp(int a, int b) {return a > b;}
int main() {
    int k, n, flag = 0;
    cin >> k;
    vector<int> v(k);
    for (int i = 0; i < k; i++) {
        cin >> n;
        v[i] = n;
        while (n != 1) {
            if (n % 2 != 0) n = 3 * n + 1;
            n = n / 2;
            if (arr[n] == 1) break; // hash table!!
            arr[n] = 1;             // flag all follow callatz numbers EXCEPT self!!!
        }
    }
    sort(v.begin(), v.end(), cmp);  
    for (int i = 0; i < v.size(); i++) {
        if (arr[v[i]] == 0) {
            if (flag == 1) cout << " ";
            cout << v[i];       // already sorted before!!!
            flag = 1;
        }
    }
    return 0;
}
*/
