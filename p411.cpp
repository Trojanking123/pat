#include<iostream>
#include<algorithm>
#include<vector>


using namespace std;

struct Edge{
    int u;
    int v;
    int weight;
    Edge(){};
    Edge(int a,int b, int c):u(a),v(b),weight(c){};
};

int n, m;
const int kMAX = 205;
const int INF = 0x7f7f7f7f;
int father[kMAX];

Edge edges[kMAX];

int findFather(int x){
    if(x == father[x]) return x;
    else{
        int r = findFather(father[x]);
        father[x] = r;
        return r;
    }

}

bool cmp(Edge a, Edge b){
    return a.weight < b.weight;
}


int kruskal(void){
    int ans = 0;
    int num = 0;
    for(int i = 0; i < n; i++){
        father[i] = i;
    }
    sort(edges, edges + m, cmp);
    for(int i = 0; i < m; i++){
        int u = edges[i].u;
        int v = edges[i].v;
        int fu = findFather(u);
        int fv = findFather(v);
        if(fu != fv){
            father[fu] = fv;
            ans += edges[i].weight;
            num++;
            if(num == n-1) break;
        }
    }
    if(num != n-1) return -1;
    return ans;

}


int main(void){ 
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }
    int ans = kruskal();

    cout<<ans<<endl;


    return 0;
}