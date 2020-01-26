#include<iostream>
#include<vector>

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

int k1 = 0, k2 = 0;
vector<Node*> lev1;
vector<Node*> lev2;



void create(Node*& root, int s, int e){
    if(s > e) return;
    if(s == e){
        //printf("create node %d\n", pre[s]);
        root = new Node(pre[s]);
        return;
    }
    //printf("create node %d\n", pre[s]);
    root = new Node(pre[s]);
    int i;
    for(i = s+1; i <= e; i++){
        if(pre[i] > pre[s]) break;
    }
    create(root->left, s+1, i-1);
    create(root->right, i, e);
}

Node* findFirst(Node* root, int x, bool flag){
    if(root == nullptr) return nullptr;
    if(flag) lev1.push_back(root);
    else lev2.push_back(root);
    if(root->data == x) return root;
    if(root->data > x) return findFirst(root->left,  x, flag);
    else return findFirst(root->right, x, flag);
};

Node* lca(vector<Node*>& a, vector<Node*>& b){
    int sa = a.size();
    int sb = b.size();
    
    int len = (sa > sb) ? sb : sa;
    for(int i= 0; i < len; i++){
        if(a[i] != b[i]) return a[i-1];
    }
    if(sa < sb) return a[sa-1];
    if(sb < sa) return b[sb-1];
    if(sa == sb) return a[sa-1];
}



int main(void){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        scanf("%d", pre+i);
    }   

    Node* root;
    create(root, 0, m-1);
    
    for(int i = 0; i < n; i++){
        lev1.clear();
        lev2.clear();
        int x1, x2;
        scanf("%d %d", &x1, &x2);
        Node* first = findFirst(root, x1, 1);
        Node* second = findFirst(root, x2, 0);
        if(first){
            if(second){
                Node* a = lca(lev1, lev2);
                /*
                if(a->data == x1 && x1 == x2){
                    printf("LCA of %d and %d is %d.\n", x1, x2, a->data);
                    continue;
                }*/
                if(a->data == x1) printf("%d is an ancestor of %d.\n", a->data, x2);
                else if(a->data==x2) printf("%d is an ancestor of %d.\n", a->data, x1);
                else printf("LCA of %d and %d is %d.\n", x1, x2, a->data);
            }else{
                printf("ERROR: %d is not found.\n", x2);
            }
        }else{
            if(second){
                printf("ERROR: %d is not found.\n", x1);
            }else{
                printf("ERROR: %d and %d are not found.\n", x1, x2);
            }
        }
        

    }
    
    return 0;
}

/*
6 8
6 3 1 2 5 4 8 7
2 5
8 7
1 9
12 -3
0 8
99 99


LCA of 2 and 5 is 3.
8 is an ancestor of 7.
ERROR: 9 is not found.
ERROR: 12 and -3 are not found.
ERROR: 0 is not found.
ERROR: 99 and 99 are not found.


*/

