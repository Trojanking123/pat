#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
const int kMAX = 105;
int n, m, s;
int weight[kMAX] = {0};
vector<int> ancient[kMAX];
vector<int> tree[kMAX];
vector<int> path;
vector<vector<int>> all;
int sum = 0;
void DFS(int root){
    path.push_back(weight[root]);
    sum += weight[root];
    if(tree[root].size() == 0 && sum == s){
        all.push_back(path);
    }
    for(int i = 0; i < tree[root].size(); i++){
        DFS(tree[root][i]);
    }
    path.pop_back();
    sum -= weight[root];
}


bool cmp(vector<int>& a, vector<int>& b){
    int min = a.size() > b.size() ? b.size() : a.size();
    for(int i = 0; i < min; i++){
        if(a[i] != b[i]) return a[i] > b[i];
    }
    return a.size() > b.size();
}

int main(void){
    cin >> n >> m >> s;
    for(int i = 0; i < n; i++){
        cin >> weight[i];
    }
    int id, k, temp;
    for(int i = 0; i < m; i++){
        cin >> id >> k;
        for(int j = 0; j < k; j++){
            cin >> temp;
            tree[id].push_back(temp);
        }
    }

    DFS(0);

    sort(all.begin(), all.end(), cmp);

    for(int i = 0; i < all.size(); i++){
        printf("%d", all[i][0]);
        for(int j =1; j < all[i].size(); j++){
            printf(" %d", all[i][j]);
        }
        printf("\n");
    }

    return 0;
}