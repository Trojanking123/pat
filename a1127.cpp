#include<iostream>
#include<queue>


using namespace std;
int n;
const int kMAX = 35;
int in[kMAX];
int post[kMAX];

int res[kMAX];
int k = 0;


struct Node{
    int data;
    Node* left;
    Node* right;
    int layer;
    Node(int x):data(x),left(nullptr),right(nullptr),layer(0){
        ;
    }
};

void create(Node*& root, int il, int ir, int pl, int pr){
    if(il > ir) return;
    if(il == ir){
        root = new Node(in[ir]);
        return;
    }
    
    int x = post[pr];
    root = new Node(x);
    int i;
    for(i = il; i <= ir; i++){
        if(in[i]==x) break;
    }
    int lenL = i-il;
    int lenR = ir-i;
    create(root->left, il, i-1, pl, pl+lenL-1);
    create(root->right, i+1, ir, pr-lenR, pr-1);
    return;
    
}
void zigzag(Node* root){
    deque<Node*> q;
    Node* last = root;
    q.push_back(root);
    bool flag = true;
    while(!q.empty()){
        if(flag){
            Node* temp = q.back();
            res[k++] =temp->data;
            q.pop_back();
            //cout<<" R -> L:"<<temp->data<<endl;
            if(temp->right) q.push_front(temp->right);
            if(temp->left) q.push_front(temp->left);
            
            if(temp == last){
                if(!q.empty()) last = q.back();
                else break;
                
                flag = !flag;
            }
            
        }else{
            Node* temp = q.front();
            res[k++] = temp->data;
            //cout<<" L -> R:"<<temp->data<<endl;
            q.pop_front();
            if(temp->left) q.push_back(temp->left);
            if(temp->right) q.push_back(temp->right);
            if(temp == last){
                if(!q.empty()) last = q.front();
                else break;
                flag = !flag;
            }

        }
    }
}




int main(void){
    Node* root;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> in[i];
    }
    for(int i = 0; i < n; i++){
        cin >> post[i];
    }
    //cout<<"input ok\n";
    create(root, 0, n-1, 0, n-1);
    //cout<<"create ok\n";
    zigzag(root);
    //cout<<"zigzag ok\n";
    printf("%d", res[0]);
    for(int i =1; i < n; i++){
        printf(" %d", res[i]);
    }
    return 0;
}