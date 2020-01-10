#include<iostream>
#include<algorithm>

using namespace std;

struct Node{
    int addr;
    int key;
    int next;
    bool flag;
}nodes[100001];

bool cmp(Node a, Node b){
    return !a.flag || !b.flag ? a.flag > b.flag : a.key < b.key;
}

int main(void){
    int start, n;
    cin >> n >> start;
    
    int taddr, tkey, tnext;
    for(int i = 0; i < n; i++){
        cin >> taddr >> tkey >> tnext;
        nodes[taddr] = {taddr, tkey, tnext, false};
    }

    int cnt = 0;
    for(int i = start; i != -1; i = nodes[i].next){
        nodes[i].flag = true;
        cnt++;
    }
    if(cnt == 0){
        printf("0 -1\n");
        return 0;
    }

    sort(nodes, nodes+100001, cmp);
    printf("%d %05d\n", cnt, nodes[0].addr);

    
    for(int i = 0; i < cnt; i++){
        printf("%05d %d ", nodes[i].addr, nodes[i].key);
        if(i != cnt -1) printf("%05d\n", nodes[i+1].addr);
        else printf("-1\n");
    }
    return 0;
}