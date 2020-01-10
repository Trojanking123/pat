#include<iostream>
#include<string>
#include<set>
#include<vector>

using namespace std;

int claim[105];
int res[105]={0};
int main(void){
    set<vetcor<int>> liars;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        claim[i] = temp;
    }
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            memset(res, 0, 105*sizeof(int));
            
        }
    }


    return 0;
}