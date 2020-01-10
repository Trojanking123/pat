#include<iostream>
#include<map>
#include<set>

using namespace std;
const int kMAXN = 500005;
int couple[kMAXN] = {0};
set<int> party;
set<int> single;

int main(void){
    for(int i = 0; i < kMAXN; i++){
        couple[i]=-1;
    }
    int n;
    cin>>n;
    for(int i = 0; i < n; i++){
        int a,b;
        scanf("%d %d", &a, &b);
        couple[a]=b;
        couple[b]=a;
    }    
    int m;
    int count = 0;
    cin >> m;
    while(m--){ 
        int p;
        scanf("%d", &p);
        party.insert(p);
    }
    for(auto it = party.begin(); it != party.end(); it++){
        int pair = couple[*it];
        if(party.find(pair) == party.end()) single.insert(*it),count++;
    }
    //cout<<"------"<<endl;
    printf("%d\n", count);
    int i = 0;
    for(auto it = single.begin(); it != single.end(); it++){
        if(i == 0) printf("%d", *it);
        else printf(" %d", *it);
        i++;
    }


    return 0;
}