#include<iostream>
#include<vector>

#define FOR(n) for(int i = 0; i < n; i++)

using namespace std;
const int kMAX = 30;
int n;
int k;
int x;
int maxSqn = 0;
int array[kMAX];
vector<int> record, temp;

void DFS(int index, int nowk, int sum, int sqn){
    if(nowk == k && sum == x){
        if(sqn > maxSqn){
            maxSqn = sqn;
            record = temp;
        }
    }
    if(index == n || nowk > k){
        return;
    }
    temp.push_back(array[index]);
    
    DFS(index + 1, nowk + 1, sum + array[index], sqn + array[index] * array[index]);
    temp.pop_back();
    DFS(index+1, nowk, sum, sqn);
}

int main(void){
    



    return 0;
}