#include<iostream>
#include<queue>

using namespace std;

struct Node{
    int id;
    int left;
    int right;
    int flag;
};

const int kMAX = 11;
Node tree[kMAX];
int ml = 0;

void reverse(int root){
    if(root == -1) return;
    int temp = tree[root].left;
    tree[root].left = tree[root].right;
    tree[root].right = temp;
    reverse(tree[root].left);
    reverse(tree[root].right);
}
void inorder(int root){
    if(root == -1) return;
    inorder(tree[root].left);
    if(root == ml) printf("%d", root);
    else printf(" %d", root);
    inorder(tree[root].right);
}

void level(int root){
    queue<int> q;
    q.push(root);
    while( !q.empty() ){
        int top = q.front();
        if(tree[top].flag) printf(" %d", top);
        else printf("%d", top);
        q.pop();
        if(tree[top].left != -1) q.push(tree[top].left);
        if(tree[top].right != -1) q.push(tree[top].right);
    }
    
}


int main(void){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        tree[i].flag = 0;
    }

    for(int i = 0; i < n; i++){
        tree[i].id = i;
        char temp;
        cin >> temp;
        
        if(temp != '-'){
            tree[i].left = temp-'0';
            tree[tree[i].left].flag++;
        }else{
            tree[i].left = -1;
        }
        cin >> temp;
        if(temp != '-'){
            tree[i].right = temp-'0';
            tree[tree[i].right].flag++;
        }else{
            tree[i].right = -1;
        }

    }
    //cout<<"input ok\n";

    int root;
    for(int i = 0; i < n; i++){
        if(tree[i].flag == 0){
            root = i;
            break;
        }
    }
    

    reverse(root);
    level(root);
    printf("\n");
    int temp = root;
    while(tree[temp].left != -1) temp = tree[temp].left;
    ml = temp;
    inorder(root);

    return 0;
}

/*
8
0 1 -
1 - -
2 0 -
3 2 7
4 - -
5 - -
6 5 -
7 4 6



3 7 2 6 4 0 5 1
6 5 7 4 3 2 0 1


*/