#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

const int kMAX = 25;

struct Node{
    string data;
    int left;
    int right;
    int height;
    Node(){};
    Node(string x, int l, int r):data(x), left(l), right(r), height(1){};
};

Node tree[kMAX];
bool vis[kMAX] = {false};
bool isRoot[kMAX] = {false};
int n;


void inOrder(int root){
    if(root == -1) return;
    int l = tree[root].left;
    int r = tree[root].right;
    
    if(l != -1){
        if(!isRoot[l] ) printf("(");
        inOrder(l);
        if(!isRoot[l] ) printf(")");
    }
    printf("%s", tree[root].data.data());
    if( r != -1){
        if(!isRoot[r] ) printf("(");
        inOrder(r);
        if(!isRoot[r] ) printf(")");
    }
    
}

int main(void){
    cin >> n;
    for(int i = 0; i < n; i++){
        string x;
        int l,r;
        cin >> x >> l >> r;
        tree[i+1] = Node(x, l, r);
        if(l != -1) vis[l] = true;
        if(r != -1) vis[r] = true;
        if(l == -1 && r == -1) isRoot[i+1] = true;
    }
    int root;
    for(int i = 1; i <= n; i++){
        if(vis[i] == false){
            root = i;
            break;
        }
    }

    inOrder(root);

    return 0;
}