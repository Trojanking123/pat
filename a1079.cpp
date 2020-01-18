#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

const int kMAX = 100007;

int n;
double price, rate;
double total;

struct Saler{
    int id;
    int sold;
    vector<int> child;
    Saler(int x):id(x),sold(0){
        ;
    }
    Saler():id(0),sold(0){
        ;
    }
};

Saler chain[kMAX];

void DFS(int id, int deepth ){
    if(chain[id].sold > 0){

        total += chain[id].sold * pow(1+rate/100, deepth) * price;
        return;
    }
    //auto temp = chain[id].child;
    int size = chain[id].child.size();
    for(int it = 0; it < size; it++){
        DFS( chain[id].child[it], deepth+1);
    }
}

int main(void){
    
    cin >> n >> price >> rate;

    for(int i = 0; i < n; i++){
        int k;
        cin  >> k;
        chain[i].id = i;
        if(k){
            int temp;
            for(int j = 0; j < k; j++){
                cin >> temp;
                chain[i].child.push_back(temp);
            }
        }else{
            int temp;
            cin >> temp;
            chain[i].sold = temp;
        }
    }

    DFS(0, 0);
    printf("%0.1f", total);



    return 0;
}

/*

10 1.80 1.00
0 3 2 3 5
1 1 9
2 1 4
3 1 7
4 0 7
5 2 6 1
6 1 8
7 0 9
8 0 4
9 0 3


*/