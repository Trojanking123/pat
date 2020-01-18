#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

const int kMAX = 100007;

int n;
double price ,rate;

struct Saler{
    int id;
    vector<int> child;
    double price;
};

Saler chain[kMAX];
double minp = 0x7fffffff;
int num = 0;

void DFS(int id, int deepth){
    chain[id].price  = pow(1+rate/100, deepth) * price;
    int size = chain[id].child.size();
    if(size == 0){
        if(chain[id].price < minp){
            minp = chain[id].price;
            num = 1;
        }else if(chain[id].price == minp){
            num++;
        }
    }
    
    
    for(int i = 0; i < size; i++){
        DFS(chain[id].child[i], deepth+1);
    }
}

int main(void){
    cin >> n >> price >> rate;
    for(int i = 0; i < n; i++){
        int k;
        cin >> k;
        for(int j = 0; j < k; j++){
            int temp;
            cin >> temp;
            chain[i].child.push_back(temp);
        }
    }
    DFS(0,0);

    printf("%.4f %d", minp, num);

    



    return 0;
}


/*

10 1.80 1.00
3 2 3 5
1 9
1 4
1 7
0
2 6 1
1 8
0
0
0

*/