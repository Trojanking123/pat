#include<iostream>
#include<cstring>
using namespace std;

int to_int(char* a){
    bool pos;
    if(a[0] == '+') pos = true;
    else pos = false;
    a = a+1;
    int n = strlen(a);
    char* end = a + n;
    int ret = 0;
    int base = 1;
    while(end != a){
        end = end -1;
        ret += base*(*end - '0');
        base *= 10;
    }
    if(!pos) ret = -ret;
   
    return ret;
}


char str[10010];

int main(void){
    cin >> str;
    int len = strlen(str);
    int e = 0;
    while(*(str+e) != 'E') e++;
    bool epos;
    if(*(str+e+1) == '+') epos = true;
    else epos = false;
    int exponent = to_int(str + e + 1);

    if(str[0] == '-')cout<<'-';
    if(exponent < 0){
        cout<<"0.";
        for(int i = 0; i < -exponent-1; i++){
            cout<<'0';
            
        }
        cout<<str[1];
        for(int i= 3; i < e; i++){
            cout<<str[i];
        }

    }else if(exponent > 0){
        int point_part = e-3;


        cout<<str[1];
        
        if(exponent < point_part){
            for(int i = 3; i < e; i++) {
                if(i == exponent + 3) cout<<'.';
                cout<<str[i];
            }
            
        }else if(exponent > point_part){
            for(int i = 3; i < e; i++) cout<<str[i];
            for(int i = 0; i < exponent - point_part; i++) cout<<'0';
        }else {
            for(int i = 3; i < e; i++) cout<<str[i];
        }
    }else{
        for(int i = 1; i < e; i++) cout << str[i];
    }
    return 0;
}