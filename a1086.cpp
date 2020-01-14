#include<iostream>
#include<string>
#include<stack>

using namespace std;

struct Node{
    Node(int v){
        data = v;
        //printf("new %d\n", v);
        right = nullptr;
        left = nullptr;
    }
    int data;
    Node* right;
    Node* left;
};

const int kMAX = 30;
int in[kMAX];
int pre[kMAX];
stack<int> stk;


void create(Node* &root, int preL, int preR, int inL, int inR){
    //cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"<<endl;
    //printf("%d %d %d %d\n", postL, postR, inL, inR);
    if(preL > preR) return;
    if(preL == preR){
        root = new Node(pre[preL]);
        return;
    }else{
        int p = pre[preL];
        root = new Node(p);
        int i;
        for( i = inL; i <= inR; i++){
            if(in[i] == p) break;
        }
        int lenL = i-inL;
        int lenR = inR-i;
        create(root->left, preL+1, preL + lenL,  inL, inL+lenL-1);
        create(root->right, preR-lenR+1, preR, i+1, i+lenR);
    }
}
int temp = 1;
void posrOrder(Node* root){
    if(root == nullptr) return;
    posrOrder(root->left);
    posrOrder(root->right);
    if(temp == 1) printf("%d", root->data);
    else printf(" %d", root->data);
    temp++;
}


int main(void){
    int n;
    cin >> n;
    string op;
    int idxIn = 0;
    int idxPre = 0;
    for(int i = 0; i < 2*n; i++){
        cin >> op;
        if(op == "Push"){
            int temp;
            cin >> temp;
            stk.push(temp);
            pre[idxPre++] = temp;
        }else{
            int top = stk.top();
            stk.pop();
            in[idxIn++] = top;
        }
    }

   

    Node* root;
    create(root, 0, n-1, 0, n-1);
    posrOrder(root);
    return 0;
}