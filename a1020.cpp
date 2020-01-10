#include<iostream>
#include<queue>


using namespace std;

const int kMAX = 30;
int post[kMAX];
int in[kMAX];

struct Node{
    Node(int x){
        //printf("value:%d\n",x);
        data = x;
        left = nullptr;
        right = nullptr;
        layer = 0;
    };
    int data;
    Node* left;
    Node* right;
    int layer;
};

Node* root = nullptr;

void create(Node* &root, int postL, int postR, int inL, int inR){
    //cout<<"@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@"<<endl;
    //printf("%d %d %d %d\n", postL, postR, inL, inR);
    if(postL > postR) return;
    if(postL == postR){
        root = new Node(post[postL]);
        return;
    }else{
        int p = post[postR];
        root = new Node(p);
        int i;
        for( i = inL; i <= inR; i++){
            if(in[i] == p) break;
        }
        int lenL = i-inL;
        int lenR = inR-i;
        create(root->left, postL, postL + lenL -1,  inL, inL+lenL-1);
        create(root->right, postR-lenR, postR-1, i+1, i+lenR);
    }
}

void BFS(Node* root){
    
    queue<Node*> q;
    
    q.push(root);
    
    root->layer++;
    
    while(!q.empty()){
        
        Node* top = q.front();
        if(top->layer == 1) printf("%d", top->data);
        else printf(" %d", top->data);
        q.pop();
        if(top->left){
            q.push(top->left);
            top->left->layer = top->layer+1;
        }
        if(top->right){
            q.push(top->right);
            top->right->layer = top->layer+1;
        }
    }
}

int main(void){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        scanf("%d", post+i);
    }
    for(int i = 0; i < n; i++){
        scanf("%d", in+i);
    }
    Node* root = nullptr;
    create(root,  0, n-1, 0, n-1);
    BFS(root);

    return 0;
}