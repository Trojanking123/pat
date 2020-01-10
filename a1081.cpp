#include<iostream>
#include<cmath>

using namespace std;

typedef long long LL;

struct Fraction{
    LL up;
    LL down;
};

Fraction get_frac(){
    Fraction a;
    cin >> a.up;
    getchar();
    cin>>a.down;
    return a;
}

LL gcd(LL a, LL b){
    return !b ? a : gcd(b, a % b);

}

Fraction fplus(Fraction a, Fraction b){
    Fraction ret;
    ret.up = a.up * b.down + a.down * b.up;
    ret.down = a.down * b.down;
    LL m = gcd(ret.up, ret.down);
    ret.up /= m;
    ret.down /= m;
    return ret;

};

void print(Fraction a){
    if(a.up == 0){
        cout<<0;
        return;
    }
    if(a.up < 0) cout<< '-';
    int i = (abs(a.up) / a.down);
    int k = (abs(a.up) % a.down);
    if(i) cout<<i;
    if(k){
        if(i) cout<<" ";
        cout<<k<<"/"<<a.down;
    }
};

int main(void){

    int n;
    cin >> n;
    
    Fraction a = get_frac();
    Fraction b;
    for(int i = 1; i < n; i++){
        b = get_frac();
        a = fplus(a, b);
    }
    print(a);
    
    
   

    return 0;
}