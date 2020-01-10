#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int kMAXLEN = 1000005;
struct Node{        
    int addr;
    int data;
    int next;
    int order;
}nodes[kMAXLEN];

const int kMAXN = 10007;
bool isExsist[kMAXN] = {false};

bool cmp(Node a, Node b){
    return a.order < b.order;
}

int abs(int n){
    if(n < 0) return -n;
    return n;
}

int main(void){
    memset(isExsist, false, sizeof(isExsist));
    for(int i = 0; i < kMAXLEN; i++){
        nodes[i].order = 2*kMAXLEN+1;
    }
    int start, n;
    cin >> start >> n;
    int nn = n;
    while(nn--){
        int addr;
        scanf("%d", &addr);
        nodes[addr].addr = addr;
        scanf("%d %d", &nodes[addr].data, &nodes[addr].next) ;
        
    }
    int tempaddr = start;
    int countInvalid = 0;
    int countValid = 0;
    //cout<<"input ok"<<endl;
    while(tempaddr != -1){

        if(isExsist[ abs(nodes[tempaddr].data) ]){
            nodes[tempaddr].order = kMAXLEN + countInvalid++;
        }else{
            nodes[tempaddr].order = countValid++;
            isExsist[ abs(nodes[tempaddr].data) ] = true;
        }
        tempaddr = nodes[tempaddr].next;
    }

    sort(nodes, nodes+kMAXLEN, cmp);
    
    int count = countValid + countInvalid;
    for(int i = 0; i < count; i++){
		if(i != countValid - 1 && i != count -1){
			printf("%05d %d %05d\n", nodes[i].addr, nodes[i].data, nodes[i + 1].addr);
		}
		else{
			printf("%05d %d -1\n", nodes[i].addr, nodes[i].data);
		}
	}

    
    return 0;
}
