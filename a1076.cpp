#include<iostream>
#include<vector>
#include<queue>
#include<cstring>

using namespace std;

const int kMAX = 1008;
int n;
int l;
struct Node{
    int data;
    int layer;
    Node():layer(0){};
    Node(int x):data(x), layer(0){};
};

vector<Node> Adj[kMAX];
bool inq[kMAX] = {false};

int BFS(int u){
    int forwards = 0;
    queue<Node> q;
    Node start(u);
   
    q.push(start);
    inq[u] = true;
    while( !q.empty()){
        Node top = q.front();
        q.pop();
        int s = Adj[top.data].size();
        for(int i = 0; i < s; i++){
            Node next = Adj[top.data][i];
            next.layer = top.layer + 1;
            if(inq[next.data] == false && next.layer <= l){
                q.push(next);
                inq[next.data] = true;
                forwards++;
            }
        }
    }
    return forwards;
}

int main(void){
    cin >> n >> l;
    for(int i = 1; i <= n; i++){
        int k = 0;
        cin >> k;
        for(int j = 0; j < k; j++){
            int temp ;
            cin >> temp;
            Adj[temp].push_back( Node(i) );
        }
    }
    int k;
    cin >> k;
    for(int i = 0; i < k; i++){
        memset(inq, false, sizeof(inq));
        int x;
        cin >> x;
        int ret = BFS(x);
        printf("%d\n", ret);
    }


    return 0;
}