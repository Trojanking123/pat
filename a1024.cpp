#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

struct bigint{
    int num[200]={0};
    int len;
};

void input(bigint &a){
    string s;
    cin >> s;
    int len = s.size();
    for(int i = 0; i < len; i++){
        a.num[len-i-1] = s[i]-'0';
    }
    a.len = len;

}

void bigplus(bigint &a, const bigint& b){
    int carry = 0;
    for(int i = 0; i < max(a.len, b.len); i++){
        int temp = a.num[i] + b.num[i] + carry;
        a.num[i] = temp % 10;
        carry = temp / 10;
    }
    if(carry){
        a.num[max(a.len, b.len)] = 1;
    }
    a.len = max(a.len, b.len) + carry;
}

void print(bigint &a){
    for(int i = 0; i < a.len; i++){
        cout<<a.num[a.len - i -1];
    }
    cout<<endl;
}

bool isPalindromic(bigint& a){
    for(int i= 0; i < a.len/2; i++){
        if(a.num[i] != a.num[a.len-i-1]) return false;
    }
    return true;
}

void reverseBigint(bigint& a, bigint& b){
    for(int i = 0; i < a.len; i++){
        b.num[a.len-i-1] = a.num[i];
    }
    b.len = a.len;
}


int main(void){

    bigint m;
    int k;
    input(m);
    cin >> k;

    for(int i = 0; i < k; i++){
        if(isPalindromic(m)){
            print(m);
            cout<<i<<endl;
            return 0;
        }
        bigint temp;
        reverseBigint(m, temp);
        bigplus(m, temp);
    }
    print(m);
    cout<<k<<endl;

    return 0;
}