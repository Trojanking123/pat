#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

const int kMAX = 105;

struct Node{
    int left;
    int right;
    int data;
};

Node tree[kMAX];
int value[kMAX];

int k = 0;

int n;

void DFS(int root){
    if( root == -1 ) return;
    DFS(tree[root].left);
    tree[root].data = value[k++];
    DFS(tree[root].right);
}

void level(int root){
    queue<int> q;
    q.push(root);
    while(!q.empty()){
        int top = q.front();
        q.pop();
        int l = tree[top].left;
        int r= tree[top].right;
        if( l != -1) q.push(l);
        if(r != -1) q.push(r);
        if(top == 0) printf("%d", tree[top].data);
        else printf(" %d", tree[top].data);
    }
}


int main(void){
    cin >> n;
    for(int i = 0; i < n; i++){
        int l,r;
        cin >> l >> r;
        tree[i].left = l;
        tree[i].right = r;
        
    }
    for(int i = 0; i < n; i++){
        cin >> value[i];
    }
    sort(value, value+n);
    
    
    DFS(0);

    level(0);

    return 0;
}

/*
58 25 82 11 38 67 45 73 42


*/