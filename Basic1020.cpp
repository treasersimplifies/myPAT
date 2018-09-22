#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct mooncake {
    float store;
    float totalworth;
    float singleprice;
}mooncake;

int cmp(mooncake a, mooncake b) {
   return a.singleprice > b.singleprice;
}

int main (){
    int types;
    float marketneeds;
    float totalstore=0.0;
    float thisstore=0.0;
    float profit=0.0;
    
    cin >> types >> marketneeds;
    
    vector<mooncake> mc(types);
    for(int i=0;i<types;i++){
        cin >> mc[i].store;
    }
    for(int i=0;i<types;i++)
        cin >> mc[i].totalworth;
    for(int i=0;i<types;i++)
        mc[i].singleprice = mc[i].totalworth/mc[i].store;
    
    sort(mc.begin(), mc.end(), cmp);
    /*
    for(int i=0;i<mc.size();i++){
        cout << mc[i].singleprice << " ";
    }cout<<endl;
    for(int i=0;i<mc.size();i++){
        cout << mc[i].store << " ";
    }cout<<endl;
    for(int i=0;i<mc.size();i++){
        cout << mc[i].totalworth << " ";
    }
    cout<<endl;*/
    
    for(int j=0;j<mc.size();j++){
        if(totalstore+mc[j].store>marketneeds){
            thisstore = marketneeds-totalstore;
            totalstore = marketneeds;
            profit += mc[j].singleprice*thisstore;
            break;
        }
        else{
            totalstore += mc[j].store;
            profit += mc[j].totalworth;
        }
    }
    printf("%.2f",profit);//cout << profit <<endl;
    return 0;
}
