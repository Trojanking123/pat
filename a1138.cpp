#include<iostream>


using namespace std;

const int kMAX = 50005;
int in[kMAX];
int pre[kMAX];
int n;
void getFirstPost(int il, int ir, int pl, int pr){
    if(pl == pr){
        printf("%d\n", pre[pl]);
        return;
    }
    int x = pre[pl];
    int i;
    for(i = il; i <= ir; i++){
        if(in[i] == x) break;
    }
    int lenL = i-il;
    int lenR = ir-i;
    if(lenL > 0) getFirstPost(il, i-1, pl+1, pl+lenL);
    else getFirstPost(i+1, ir, pl+lenL+1, pr);
    
}


int main(void){
    cin >> n;
    for(int i = 0; i < n; i++){
        scanf("%d", pre+i);
    }

    for(int i = 0; i < n; i++){
        scanf("%d", in+i);
    }

    getFirstPost(0, n-1, 0, n-1);





    return 0;
}