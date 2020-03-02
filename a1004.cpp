#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

struct Node{
    vector<int> children;
    int id;
    int deepth;
};

const int kMAX = 105;
const int INF = 0x7f7f7f7f;

Node tree[kMAX];
int n, m;
int all[kMAX] = {0};
int counter = -1;

void BFS(int root){
    queue<int> q;
    tree[root].deepth = 0;
    int ans = 0;
    int last = 0;
    q.push(root);

    while( ! q.empty() ){
        int top = q.front();
        q.pop(); 
        counter = tree[top].deepth;
        if(tree[top].children.size() == 0){
            all[counter]++;
            
            continue;
        }

        for(int i = 0; i < tree[top].children.size(); i++){
            int child = tree[top].children[i];
            tree[child].deepth = tree[top].deepth+1;
            q.push(child);
        }
    }


}



int main(void){
    cin >> n >> m;
    if(n == 0) return 0;
    int i, k, temp;
    for(int g = 0; g < m; g++){
        cin >> i >> k;
        tree[i].id = i;
        for(int j = 0; j < k; j++){
            cin >> temp;
            tree[i].children.push_back(temp);
        }
    }
    
    
    BFS(1);
    //cout<<"counter:"<<counter<<endl; 
    printf("%d", all[0]);
    for(int i = 1; i < counter+1; i++){
        printf(" %d", all[i]);
    }
    
    return 0;
}