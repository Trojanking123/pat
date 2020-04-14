#include<iostream>
#include<algorithm>
#include<vector>


using namespace std;

const int INF = 0x3f3f3f3f;
const int kMAX = 202;

int G[kMAX][kMAX] = {0};

int n, e;
int k, m;
vector<int> s;
int judge[kMAX] = {0};

int main(void){
    fill(G[0], G[0] + kMAX*kMAX, INF);
    cin >> n >> e;
    for( int i = 0; i < e; i++){
        int a, b;
        cin >> a >> b;
        G[a][b] = 1;
        G[b][a] = 1;
    }
    cin >> k;
    while(k > 0){
        k--;
        cin >> m;
        s.clear();
        fill(judge, judge+kMAX, 0);
        for(int i = 0; i < m; i++){
            int temp;
            cin >> temp;
            judge[temp]++;
            s.push_back(temp);
        }
        if(m != n + 1 || s[0] != s[m-1]){
            printf("NO\n");
            continue;
        }
        bool flag = false;
        for(int i = 0; i < m-1; i++){
            if( G[s[i]][s[i+1]] != 1 ){
                flag = true;
                break;
            }
        }
        if(flag){
            printf("NO\n");
            continue;
        }
        flag = false;
        for(int i = 1; i <= n; i++){
            if(judge[i] != 1 && i != s[0]){
                flag = true;
                break; 
            }
        }
        if(flag){
            printf("NO\n");
            continue;
        }
        printf("YES\n");

        
    }
    return 0;
}