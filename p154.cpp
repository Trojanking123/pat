#include<iostream>

using namespace std;


int gcd(int a, int b){
    return !b ? a : gcd(b, a % b);

}

int lcm(int a, int b){
    return (a * b)/ gcd(a, b);
}

int main(void){

    int a, b;
    cin >> a;
    cin >> b;
    cout << lcm(a, b);


    return 0;
}