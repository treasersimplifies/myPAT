#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef struct student {
    int ID;
    int DEgrade;
    int CAIgrade;
}student;

int cmp(student a, student b) {
    if ((a.DEgrade + a.CAIgrade) != (b.DEgrade + b.CAIgrade))
        return (a.DEgrade + a.CAIgrade) > (b.DEgrade + b.CAIgrade);
    else if (a.DEgrade != b.DEgrade)
        return a.DEgrade > b.DEgrade;
    else
        return a.ID < b.ID;
}

int main () {
    int N,L,H;
    cin >> N >> L >> H;
    vector<student> stuvec[4];
    student temp;
    int receive=0;
    
    for(int i =0;i<N;i++){
        cin>>temp.ID >> temp.DEgrade >> temp.CAIgrade;
        if(temp.DEgrade>=L && temp.CAIgrade>=L){
            receive++;
            if(temp.DEgrade>=H && temp.CAIgrade>=H)
                stuvec[0].push_back(temp);
            else if(temp.DEgrade>=H && temp.CAIgrade<H)
                stuvec[1].push_back(temp);
            else if(temp.DEgrade<H && temp.CAIgrade<H && temp.DEgrade> temp.CAIgrade)
                stuvec[2].push_back(temp);
            else
                stuvec[3].push_back(temp);
        }
        
    }
    for(int i=0;i<4;i++)
        sort(stuvec[i].begin(),stuvec[i].end(),cmp);
    
    cout << receive << endl;
    for(int i=0;i<4;i++)
        for(int j=0;j<stuvec[i].size();j++){
            cout << stuvec[i][j].ID << " " << stuvec[i][j].DEgrade << " " << stuvec[i][j].CAIgrade<<endl;
        }
    
    return 0;
}
