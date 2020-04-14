#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int kMAX = 205;

int G[kMAX][kMAX] = {0};
bool inclip[kMAX] = {false};

int n, e;

bool isClique(vector<int>& v){
    int s = v.size();
    for(int i = 0; i < s; i++){
        for(int j = i+1; j < s; j++){
            if(G[v[i]][v[j]] != 1){
                return false;
            }
        }
    }
    return true;
}

bool isConnected(int a, vector<int>& v){
    int s = v.size();
    for(int i = 0; i < s; i++){
        if (! G[a][v[i]]){
            return false;
        }
    }
    return true;

}

bool isMaxClique(vector<int>& v){
    int s = v.size();
    for(int i = 1; i <= n; i++){
        if( ! inclip[i]){
            bool flag = isConnected(i, v);
            if(flag) return false;
        }
    }
    return true;
}

int main(void){
    cin >> n >> e;

    for( int i = 0; i < e; i++){
        int a,b;
        cin >> a >>  b;
        G[a][b] = 1;
        G[b][a] = 1;
    }
    int query;
    cin >> query;
    for(int i = 0; i < query; i++){
        int num;
        cin >> num;
        vector<int> clique;
        fill(inclip, inclip+kMAX, false);
        for(int j = 0; j < num ; j++){
            int temp;
            cin >> temp;
            inclip[temp] = true;
            clique.push_back(temp);
        }
        if(isClique(clique)){
            if(isMaxClique(clique)){
                printf("Yes\n");
            }else{
                printf("Not Maximal\n");
            }
        }else{
            printf("Not a Clique\n");
        }


    }
    
    return 0;
}