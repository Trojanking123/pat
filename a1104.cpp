#include<iostream>

using namespace std;

int main(void){

    int n;
    cin >> n;
    double total = 0;
    double temp;
    int i = 0;
    while(i < n){
        cin >> temp;
        total += temp *(i + 1)*(n-i);
        i++;
    }
    printf("%.2lf", total);


    return 0;
}