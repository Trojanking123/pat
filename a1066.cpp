#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


struct Node{
    int value;
    Node* left;
    Node* right;
    int high;
    Node(){};
    Node(int x):value(x),left(nullptr), right(nullptr), high(1) {};
};


Node* root;
int v[50];
int n;

int getHeight(Node* root){
    if(root) return root->high;
    else return 0;
}

void updateHeight(Node* root){
    root->high = max( getHeight(root->left), getHeight(root->right)) + 1;
}

int getBalenceFactor(Node* root){
    return getHeight(root->left) - getHeight(root->right);
}

void L(Node*& root){
    Node* temp = root->right;
    root->right = temp->left;
    temp->left = root;
    //root = temp;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}

void R(Node*& root){
    Node* temp = root->left;
    root->left = temp->right;
    temp->right = root;
    //root = temp;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}

void insertWithBalence(Node*& root, int x){
    if(!root){
        root = new Node(x);
        return;
    }
    if(x < root->value){
        insertWithBalence(root->left, x);
        updateHeight(root);
        if(getBalenceFactor(root) == 2){
            if(getBalenceFactor(root->left) == 1) 
                R(root);
            else if(getBalenceFactor(root->left) == -1){
                L(root->left);
                R(root);
            }
        }
    }else{
        insertWithBalence(root->right, x);
        updateHeight(root);
        if(getBalenceFactor(root) == -2){
            if(getBalenceFactor(root->right) == -1) 
                L(root);
            else if(getBalenceFactor(root->right) == 1){
                R(root->right);
                L(root);
            }
        }
    }
}

void create(Node*& root){
    for(int i = 0; i < n; i++){
        insertWithBalence(root, v[i]);
        //printf("insert after:%p %d\n", root, root->value);
    }
}


int main(void){

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    create(root);
    printf("%d\n", root->value);

    return 0;
}