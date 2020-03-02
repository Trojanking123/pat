#include<iostream>
#include<algorithm>
#include<map>


using namespace std;
int n, m;
const int kMAX  = 1e5+5;
int value[kMAX];
map<int, int> se;
int proc(){
    int ans = 0;
    for(int i = 0; i < n; i++){
        int sum = 0;
        int j;
        for(j = i; j < n; j++){
            sum += value[j];
            if(sum > m) break;
            if(sum == m){
                se[i] = j;
                ans++;
                continue;
            }
        }
    }
    return ans;
}

int main(void){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> value[i];
    }
    int ans = proc();
    if(ans){
        for(auto it = se.begin(); it != se.end(); it++){
            printf("%d->%d\n",it->first+1, it->second+1);
        }
    }
    return 0;
}