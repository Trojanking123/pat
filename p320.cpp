#include<iostream>
#include<algorithm>

using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    int height;
    Node(int x){
        data = x;
        left = nullptr;
        right = nullptr;
        height = 1;
    }
};

int getHeight(Node* root){
    return root->height;
}
int getBalanceFactor(Node* node){
    return node->left->height - node->right->height;
}
void updateHeight(Node* node){
    node->height = node->left->height + node->right->height;
}

Node* search(Node* root, int x){
    if(root == nullptr) return nullptr;
    if(x == root->data) return root;
    if(x > root->data) return search(root->right, x);
    else return search(root->left, x);
}
void LR(Node* &root){
    Node* temp = root->right;
    root->right = temp->left;
    temp->left = root;
    updateHeight(root);
    updateHeight(temp);

    root = temp;
}

void RR(Node* &root){
    Node* temp = root->left;
    root->left = temp->left;
    temp->right = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}

void insert(Node* root, int v){
    if(root == nullptr ){
        root = new Node(v);
        return;
    }
    if(v < root->data){
        insert(root->left, v);
        updateHeight(root);
        if(getBalanceFactor(root) == 2){
            if(getBalanceFactor(root->left) == 1){
                RR(root); //LL
            }else if(getBalanceFactor(root->left) == -1){
                LR(root->left);  // LR
                RR(root);
            }
        }else if(getBalanceFactor(root) == -2){
            if(getBalanceFactor(root->right) == -1){
                LR(root); // RR
            }else if(getBalanceFactor(root->right) == 1){
                RR(root->right); // RL
                LR(root);
            }
        }
    }
}




int main(void){




    return 0;
}