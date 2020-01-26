#include<iostream>
#include<queue>
#include<vector>



using namespace std;

const int kMAX = 105;
int counter[kMAX] = {0};

struct Node{
    vector<int> child;
    int layer;
    Node(int x){
        //id = x;
        layer = 0;
    }
    Node(){};
};

Node tree[kMAX];

void BFS(int root){
    queue<int> q;
    q.push(root);
    tree[root].layer++;

    while(!q.empty()){
        int top = q.front();
        q.pop();
        int size = tree[top].child.size();
        counter[tree[top].layer]++;
        //printf("id:%02d layer:%02d counter:%02d\n ", top, tree[top].layer, counter[tree[top].layer]);
        for(int i = 0; i < size; i++){
            int cd = tree[top].child[i];
            tree[cd].layer = tree[top].layer + 1;
            q.push(cd);
        }
    }


}

int main(void){ 
    int n,m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int id, k;
        cin >> id >> k;
        //tree[id] = Node(id);
        for(int j = 0; j < k; j++){
            int temp;
            cin >> temp;
            tree[id].child.push_back(temp);
            
        }
    }

    int k = 0; 
    int max = -1;
    
    BFS(1);

    for(int i = 1; i < kMAX; i++){
        if(counter[i] > max ){
            max = counter[i];
            k = i;
        }
    }
    printf("%d %d", max, k);
    




    return 0;
}