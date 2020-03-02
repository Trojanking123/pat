#include<iostream>
#include<algorithm>
#include<vector>


using namespace std;

int n;
const int kMAX = 1005;
int pre[kMAX] = {0};

struct Node{
    int value;
    Node* left;
    Node* right;
    Node(){};
    Node(int x):value(x), left(nullptr), right(nullptr){};
};

bool create(Node*& root, int l, int r){
    if(l > r) return true;
    if(l == r){
        root = new Node(pre[l]);
        return true;
    }
    bool flag = pre[l] > pre[l+1];

    int i = l;
    for(i = l+1; i <= r; i++){
        if(flag){
            if(pre[i] >= pre[l]){
                break;
            }
        }else{
            if(pre[i] < pre[l]){
                break;
            }
        }
    }
    for(int j = i; j <= r; j++){
        if(flag && pre[j] < pre[l]){
            return false;
        }
        if( !flag && pre[j] >= pre[l]){
            return false;
        }
    }
    root = new Node(pre[l]);
    return create(root->left, l+1, i-1) && create(root->right, i, r);
    
}


vector<int> all;

void postOrder(Node* root){
    if(root == nullptr) return ;
    postOrder(root->left);
    postOrder(root->right);
    all.push_back(root->value);
}

int main(void){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> pre[i];
    }
    if(n == 0){
        printf("NO\n");
        return 0;
    }
    if(n == 1){
        printf("YES\n%d\n", pre[0]);
        return 0;
    }
    //bool flag = pre[0] > pre[1];
    Node* root = nullptr;
    //cout<<"bef create\n";
    bool ans = create(root, 0, n-1);
    //cout<<"after \n";
    if(!ans){
        printf("NO\n");
        return 0;
    }
    //if(!flag) reverse(root);
    postOrder(root);
    printf("YES\n");
    printf("%d", all[0]);
    for(int i = 1; i < all.size(); i++){
        printf(" %d", all[i]);
    }
    printf("\n");
    return 0;
}