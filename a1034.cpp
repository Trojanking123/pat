#include<iostream>
#include<map>
#include<string>

using namespace std;

const int kMAX = 2005;
const int INF = 100000000;

map<string, int> s2i;
map<int, string> i2s;
map<string, int> gang;
int G[kMAX][kMAX] = {0};
int weight[kMAX] = {0};
bool vis[kMAX] = {false};

int num = 0;
int n;
int k;

int getID(string s){
    if(s2i.find(s) != s2i.end()) return s2i[s];
    s2i[s] = num;
    i2s[num] = s;
    return num++;
}

void DFS(int id, int& head, int& member, int& total){
    member++;
    vis[id] = true;
    if(weight[id] > weight[head]) head = id;
    for(int i = 0; i < num; i++){
        if(G[id][i] > 0){
            total += G[id][i];
            G[id][i] = 0;
            G[i][id] = 0;
            if(vis[i] == false){
                DFS(i, head, member, total);
            }
        }
    }
}

void Traval(){
    for(int i = 0; i < num; i++){
        if(vis[i] == false){
            int head = i;
            int member = 0;
            int total = 0;
            DFS(i, head, member, total);
            if(member > 2 && total > k){
                gang[i2s[head]] = member;
            }
        }
        
    }
}


int main(void){
    int w;
    string str1, str2;
    cin >> n;
    cin >> k;
    for(int i = 0; i < n; i++){
        cin >> str1;
        cin >> str2;
        cin >> w;
        int id1 = getID(str1);
        int id2 = getID(str2);
        G[id1][id2] += w;
        G[id2][id1] += w;
        weight[id1] += w;
        weight[id2] += w;
    
    }
    Traval();
    printf("%d\n", gang.size());
    for(auto it = gang.begin(); it != gang.end(); it++){
        printf("%s %d\n", it->first.data(), it->second);
    }

    return 0;
}