#include<iostream>
#include<cmath>
using namespace std;

typedef  long long int LL;

LL getLength(LL n){
    LL i = 0;
    while(n != 0) n/=10,i++;
    return i;
}

bool judge(LL n){
    LL len = getLength(n);
    LL base = pow(10,len/2);
    LL first = n/base;
    LL second = n % base;
    //cout<<first<<" "<<second<<endl;
    if( ! (first && second)) return false;
    return 0 == n % (first * second);
}

int main(void){
    LL n;
    cin >> n;
    for(LL i = 0; i < n; i++){
        LL temp;
        cin >> temp;
        if(judge(temp)) printf("Yes\n");
        else printf("No\n");
        
    }

    return 0;
}