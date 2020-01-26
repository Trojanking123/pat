#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;
int n, m;
const int kMAX = 10005;


struct Node{
    int data;
    Node* left;
    Node* right;
    Node(){};
    Node(int x):data(x),left(nullptr),right(nullptr){};
};

Node* tree[kMAX];
int pre[kMAX];
int in[kMAX];


void create(Node*& root, int il, int ir, int pl, int pr){
    if(il > ir) return;
    if(il == ir){
        root = new Node(pre[pl]);
        return;
    }
    int x = pre[pl];
    root = new Node(x);
    int i;
    for(i = il; i <= ir; i++){
        if(in[i] == x) break;
    }
    int lenL = i-il;
    create(root->left, il, i-1, pl+1, pl+lenL);
    create(root->right, i+1, ir, pl+lenL+1, pr);

}

int k1 = 0, k2 = 0;
deque<Node*> lev1;
deque<Node*> lev2;

Node* DFS(Node* root,int x , bool flag){
    if(! root) return nullptr;
    if(root->data == x) return root;

    Node* ret_l =  DFS(root->left, x, flag);
    Node* ret_r =  DFS(root->right, x, flag);
    if(ret_l) {
        if(flag) lev1.push_back(ret_l);
        else lev2.push_back(ret_l);
    }
    if(ret_r){
        if(flag) lev1.push_back(ret_r);
        else lev2.push_back(ret_r);
    }
    if(ret_l || ret_r) return root;
    else return nullptr;

}

Node* lca(deque<Node*>& a, deque<Node*>& b){
    int sa = a.size();
    int sb = b.size();
    
    int len = (sa > sb) ? sb : sa;
    for(int i= 0; i < len; i++){
        if(a[i] != b[i]) return a[i-1];
    }
    if(sa < sb) return a[sa-1];
    if(sb < sa) return b[sb-1];
    
}

void find(Node* root, int a, int b){
    lev1.clear();
    lev2.clear();

    Node* reta = DFS(root, a, true);
    Node* retb = DFS(root, b, false);
    if(!reta && retb) printf("ERROR: %d is not found.\n", a);
    if(!retb && reta) printf("ERROR: %d is not found.\n", b);
    if(!reta && !retb) printf("ERROR: %d and %d are not found.\n", a,b);
    if(reta && retb){
            if(a==b){
        printf("%d is an ancestor of %d.\n", a, b);
        return;
    }
        lev1.push_back(reta);
        lev2.push_back(retb);
        reverse(lev1.begin(), lev1.end());
        reverse(lev2.begin(), lev2.end());
        Node* ast = lca(lev1, lev2);
        if(ast->data != a && ast->data != b) printf("LCA of %d and %d is %d.\n", a, b, ast->data);
        if(ast->data == a && ast->data != b) printf("%d is an ancestor of %d.\n", a, b);
        if(ast->data != a && ast->data == b) printf("%d is an ancestor of %d.\n", b, a);
        if(ast->data == a && ast->data == b) printf("%d is an ancestor of %d.\n", a, b);

    }
}



int main(void){
    cin >> m >> n;
    for(int i = 0; i < n; i++){
        cin >> in[i];
    }
    for(int i = 0; i < n; i++){
        cin >>pre[i];
    }
    Node* root;
    create(root, 0, n-1, 0, n-1);
    //cout<<"create 0k\n";

    for(int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        find(root, a, b);
        
    }

    return 0;
}

/*
6 8
7 2 3 4 6 5 1 8
5 3 7 2 6 4 8 1
2 6
8 1
7 9
12 -3
0 8
99 99


*/