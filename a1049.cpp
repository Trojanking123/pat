#include <iostream>

#include<algorithm>

using namespace std;



int main(void){
    long int total;

    int n;
    int left, right;
    int base = 1;
    int now = 0;
    cin >> n;
    while(n / base != 0){
        int remainder = n % (base * 10);
        now = (remainder / base);
        right = (remainder % base);
        left = n / (base * 10);
        if(now > 1){
            total += (left + 1) * base;
        }else if(now == 1){
            total += (left) * base + right + 1;
        }else{
            total += (left) * base;
        }
        base *= 10;

    }
    cout << total;


    return 0;
}