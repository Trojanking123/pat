#include<iostream>
#include<algorithm>
#include<string>


using namespace std;

struct fn{
    string str;
    int len;
    int point = 0;
    int k;
} f1, f2;

void init( fn& f){
    int i = 0; 
    f.len = f.str.length();
    while(f.str[i] != '.' && i != f.len ) i++;
    f.point  = i;

}

void strip0(string& str){
    int i = 0;
    while(str[i] == '0')i++;
    str.erase(0,i);
    int n = str.length();
    i = n-1;
    while(str[i] == '0')i--;
    str.erase(i+1, n-i+1);
}

void deal(fn& f, int n){
    string s;
    int k = 0;
    int i = 0;
    while(f.str[i] == '0' or f.str[i] == '.') i++;
    k = f.point - i;
    if(k<0) k++;
    if(f.point != f.len){
        f.str.erase(f.point, 1);
    }
    
    strip0(f.str);
    f.len = f.str.length();
    
    if(n < f.len){
        s = f.str.substr(0, n);
        f.str = "0."+s;
    }else
    {
        for(int i = 0; i < (n-f.len); i++){
            f.str += '0';
        }
        f.str = "0."+ f.str;
    }
    f.k = k;

}

void print(fn& f){
    cout<<f.str<<"*10^"<<f.k;
}

bool is_equal(fn& a, fn& b){
    if(a.str == b.str && a.k == b.k) return true;
    return false;
}

void adjust(fn& f){
    int n = f.str.length();
    bool j = false;
    for(int i = 0; i < n; i++){
        if(f.str[i] != '0' && f.str[i] != '.'){
            j = true;
        }
    }
    if( !j){
        f.k = 0;
    }
}

int main(void){
    int n;

    fn a;
    fn b;
    cin >> n;
    cin>> a.str;
    cin>>b.str;
    init(a);
    init(b);

    deal(a, n);
    deal(b, n);
    adjust(a);
    adjust(b);
    if(is_equal(a, b)){
        printf("YES ");
        print(a);
    }else{
        printf("NO ");
        print(a);
        printf(" ");
        print(b);
    }
    
    return 0;
}