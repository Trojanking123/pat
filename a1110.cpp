
#include<iostream>
#include<vector>
#include<queue>
#include<string>

using namespace std;

const int kMAX = 22;
bool ROOT[kMAX] = {false };

struct Node{
    int data;
    int left;
    int right;
    Node():left(-1),right(-1),data(-1){};
};

Node nodes[kMAX];

int n;
int root;

int main(void){
    cin >> n;
    for(int i = 0; i < n; i++){
        string  a,b;
        
        cin >> a >> b;
        if(a != "-") {
            int t;
            sscanf(a.data(), "%d", &t);
            nodes[i].left = t;
            ROOT[t] = true;
        }
        if(b != "-") {
            int t;
            sscanf(b.data(), "%d", &t);
            nodes[i].right = t;
            ROOT[t] = true;
        }
        nodes[i].data = i;

    }
    for(int i = 0; i < n; i++){
        if( ! ROOT[i] ){
            root = i;
            break ;
        }
    }

    queue<Node> q ;

    q.push(nodes[root]);
    bool flag = false ;
    bool result = true ;
    Node top;
    while( ! q.empty() ){
        top = q.front();
        q.pop();
        
        if(flag){
            if(top.left == -1 && top.right == -1){
                //cout<<"last right"<< top.data <<endl;
                continue;
            }else{
                //cout<<"last wrong"<< top.data <<endl;
                result = false;
                break;
            }
        }else{
            if(top.left == -1 && top.right != -1){
                result = false;
                //cout<<"direct wrong"<< top.data <<endl;
                break;
            }else if(top.left != -1 && top.right == -1){
                flag = true;
                q.push(nodes[top.left]);
                //cout<<"last start"<< top.data <<endl;
            }else if(top.left == -1 && top.right == -1){
                flag = true;
                //cout<<"last right"<< top.data <<endl;
            }else{
                q.push(nodes[top.left]);
                q.push(nodes[top.right]);
                //cout<<"all right"<< top.data <<endl;
            }
        }
        
       /*
        if(top.left != -1){
            if(flag ){
                result = false;
                break;
            }
            q.push(nodes[top.left]);
        }else{
            flag = true;
        }
        if(top.right != -1){
            if(flag){
                result = false;
                break;
            }
            q.push(nodes[top.right]);
        }else{
            flag = true;
        }
        */
    }

    if(!result){
        printf("NO %d\n", root);
    }else{
        printf("YES %d\n", top.data);
    }







    return 0;
}