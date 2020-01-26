#include<iostream>
#include<map>
#include<string>


using namespace std;

const int kMAX = 25;
int n;

struct Node{    
    string data;
    string left;
    string right;
    
    
};
map<string, int> mp;
map<string ,int> id;
Node tree[kMAX];

void inorder(string root){
    
    int i = id[root];
    string l = tree[i].left;
    string r = tree[i].right;
    if(l != "-1"){
        printf("(");
        inorder(l);
        printf(")");
    }
    printf("%s", root.data());
    if(r != "-1"){
        printf("(");
        inorder(r);
        printf(")");
    }
    
}


int main(void){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> tree[i].data;    
        cin >> tree[i].left;
        cin >> tree[i].right;

        mp[tree[i].left]++;
        mp[tree[i].right]++;
        id[tree[i].data] = i;

    }
    string root;
    for(auto it = mp.begin(); it != mp.end(); it++){
        if(it->second == 0){
            root = it->first;
            break;
        }
    }
    cout<<root<<endl;
    inorder(root);


    return 0;
}

/*
8
* 8 7
a -1 -1
* 4 1
+ 2 5
b -1 -1
d -1 -1
- -1 6
c -1 -1

*/