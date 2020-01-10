#include<iostream>
#include<vector>

using namespace std;

struct Node{
    int addr;
    int data;
    int next;
}nodes[100000];

int main(void){
    int start, n, k;
    cin >> start >> n >> k;
    for(int i = 0; i < n; i++){
        int addr;
        cin >> addr;
        nodes[addr].addr = addr;
        cin >> nodes[addr].data >> nodes[addr].next;
    }

    //cout<<"input okkkkkkkkkkk"<<endl;
    
    int former = -1;
    int tempEnd = start;
    int tempStart = start;


    while(tempEnd != -1){
        int kk = k;
        while(tempEnd != -1 && kk > 0) {
            tempEnd = nodes[tempEnd].next;
            kk--;
        }
        if(kk > 0) break;

        int now = nodes[tempStart].addr;
        while(nodes[now].next != tempEnd){
            int temp = nodes[now].next;
            nodes[now].next = nodes[nodes[now].next].next;
            nodes[temp].next = tempStart;
            tempStart = temp;
        }
        if(former >= 0) nodes[former].next = tempStart;
        else start = tempStart;
        former = nodes[now].addr;
        tempEnd = nodes[now].next;
        tempStart = nodes[now].next;
    }

    tempStart = start;
    while(tempStart != -1){
        printf("%05d %d", nodes[tempStart].addr, nodes[tempStart].data);
        if( nodes[tempStart].next != -1) printf(" %05d\n", nodes[tempStart].next);
        else printf(" -1\n");
        tempStart = nodes[tempStart].next;
    }
    


    return 0;
}

/*

00100 6 3
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218


*/
