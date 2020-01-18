#include<iostream>

using namespace std;

const int kMAX = 100007;
int n;
double price, rate;

struct Saler{
    double price;
    int id;
    int fa;
    Saler():id(0),fa(0),price(0.0){
        ;
    }
};

Saler chain[kMAX];

double getPrice(int id){
    if(chain[id].fa == -1){
        chain[id].price = price;
        return price;
    }
    int fid = chain[id].fa;
    if(chain[id].price > 0.0 ) {
        return chain[id].price;
    }else{
        chain[id].price = getPrice(fid) * (1 + rate/100);
        return chain[id].price;
    }
}

int main(void){
    cin >> n >> price >> rate;
    for(int i = 0; i < n; i++){
        int fid;
        cin >> fid;
        chain[i].fa = fid;
        chain[i].price = -1.0;
    }
    int num  = 0;
    double max = -1;
    for(int i = 0; i < n; i++){
        double temp;
        temp = getPrice(i);
        if(temp > max){
            max = temp;
            num = 1;
        }else if(temp == max){
            num++;
        }
    }
    printf("%0.2f %d\n", max, num);
    return 0;
}

/*
9 1.80 1.00
1 5 4 4 -1 4 5 3 6
0 1 2 3  4 5 6 7 8

*/