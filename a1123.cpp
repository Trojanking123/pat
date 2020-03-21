#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

struct Node{
    int value;
    Node* left;
    Node* right;
    int high;
    Node(){};
    Node(int d):value(d),left(nullptr),right(nullptr), high(1){};
};

Node* root;

int getHeight(Node* root){
    if(root) return root->high;
    return 0;
}

void updateHeight(Node* root){
    if ( ! root) return;
    root->high = max( getHeight(root->left), getHeight( root->right) ) + 1;
}

int getBalanceFactor(Node* root){
    return getHeight(root->left) - getHeight(root->right);
}

void L(Node*& root){
    Node* temp = root->right ;
    root->right = temp->left;
    temp->left = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}

void R(Node*& root){
    Node* temp = root->left;
    root->left = temp->right;
    temp->right = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}

void insertWithBalance(Node*& root, int x){
    if( !root ){
        root = new Node(x);
        return;
    }

    if (x < root->value){
        insertWithBalance(root->left, x);
        updateHeight(root);
        if (getBalanceFactor(root) == 2){
            if (getBalanceFactor(root->left) == 1){
                R(root);
            }else if (getBalanceFactor(root->left) == -1){
                L(root->left);
                R(root);
            }
        }
    }else{
        insertWithBalance(root->right, x);
        updateHeight(root);

        if (getBalanceFactor(root) == -2){
            if (getBalanceFactor(root->right) == -1){
                L(root);
            }else if (getBalanceFactor(root->right)  == 1){
                R(root->right);
                L(root);
            }
        }
    }
}


const int kMAX = 25;

int v[20];


void create(Node*& root, int* v, int n){
    for(int i = 0; i < n; i++){
        insertWithBalance(root, v[i]);
    }
}

bool isCompleteTree(Node* root, vector<int>& all){
    bool flag = false;
    bool res = true;
    queue<Node*> q;
    q.push(root);
    Node* top;
    while( !q.empty() ){
        top = q.front();
        q.pop();
        all.push_back(top->value);
        if (top->left){
            if (flag){
                res = false;
            }
            q.push(top->left);

        }else{
            flag = true;
        }

        if (top->right){
            if (flag){
                res = false;
            }
            q.push(top->right);
        }else{
            flag = true;
        }

    }
    return res;
}




int main(void){

    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    Node* root = nullptr;

    create(root, v, n);
    
    vector<int> all;

    bool ret = isCompleteTree(root, all);
    
    printf("%d", all[0]);

    for(int i = 1; i < all.size(); i++){
        printf(" %d", all[i]);
    }
    printf("\n");

    if (ret) printf("YES\n");
    else printf("NO\n");

    return 0;
}