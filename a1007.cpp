#include<iostream>


using namespace std;

//typedef long long LL;

int smax  = -10e12;
const int kMAX = 10005;
int start = kMAX, ed = kMAX;
int n;
int array[kMAX];
int ts;

void DFS(int last, int k, int sum){
    if(k == n) return;
    if(last){
        DFS(last, k+1, sum+array[k]);
        if(sum > smax){
            smax = sum;
            start = ts;
            ed = k;
        }else if(sum == smax){
            if(ts < start){
                start = ts;
                ed = k;
            }else if(ts == start){
                if(ed < k){
                    ed = k;
                }
            }
        }
        return;
    }else{
        DFS(last, k+1, sum);
        ts = k;
        DFS(1, k+1, sum+array[k]);
    }
}


int main(void){

    
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> array[i];
    }
    DFS(0,0, 0);
    if(smax < 0){
        printf("%d %d %d\n", 0, 0, n-1);
        return 0;
    }
    printf("%d %d %d\n", smax, start, ed-1);
    return 0;
} 