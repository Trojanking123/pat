#include<cstdio>
#include<iostream>


#define FOR(n) for(int i =0; i < n; i++)

using namespace std;

const int kMAX = 30;
int n;
int V;
int maxValue;
int w[kMAX];
int c[kMAX];

void DFS(int index, int sumW, int sumC){
    if(index == n){
        
        return;
    }

    DFS(index+1, sumW, sumC);
    if(sumW + w[index] <= V){
        if(sumC + c[index] > maxValue){
            maxValue = sumC + c[index];
        }
        DFS(index+1, sumW + w[index], sumC + c[index]);
    }

    DFS(index+1, sumW+w[index], sumC+c[index]);
}



int main(void){
    cin >> n >> V;
    for(int i = 0; i < n; i++){
        cin >> w[i];
    }
    FOR(n){
        cin >> c[i];
    }
    DFS(0, 0, 0);
    cout<<maxValue<<endl;



    return 0;
}