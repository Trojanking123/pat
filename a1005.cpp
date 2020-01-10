#include<iostream>
#include<stack>
#include<cmath>
using namespace std;

int get_length(int n){
    int i = 1;
    int base = 10;
    while(n/base != 0){
        base *= 10;
        i++;
    }
    return i;
}

string map[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int main(void){
    string num;
    cin >> num;
    int n = num.size();
    int total = 0;
    for(int i = 0; i < n; i++){
        total += num[i] - '0';
    }
    int len = get_length(total);
    int base = pow(10, len-1);
    for(int i = 0; i < len; i++){
        cout<<map[total/base];
        if(i != len -1){
            cout<<" ";
        }
        total = total % base;
        base /= 10;
        
    }

    return 0;
}