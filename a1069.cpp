#include<iostream>
#include<algorithm>

using namespace std;


int to_num(char* a){
    int ret = 0;
    int base = 1;
    for(int i = 0; i < 4; i++){
        ret += base * (a[3-i] - '0');
        base *= 10;
    }
    return ret;

}

void to_char(int n, char* a){
    int base = 1000;
    for(int i = 0; i < 4; i++){
        a[i] = n/base + '0';
        n = n % base;
        base /= 10;

        
    }

}

bool cmp1(int a, int b){
    return a > b;
}

bool cmp2(int a, int b){

    return a < b;
}


int main(void){

    int n = 0;
    cin >> n;

    char b2s[5] = {0};
    char s2b[5] = {0};

    to_char(n, b2s);
    if(b2s[0] == b2s[3]){
        printf("%04d - %04d = 0000", n, n);
        return 0;
    }

    if (n == 6174){
        printf("7641 - 1467 = 6174");
        return 0;
    }

    while(n != 6174){
        to_char(n, b2s);
        to_char(n, s2b);
        sort(b2s, b2s+4, cmp1);
        sort(s2b, s2b+4, cmp2);
        int b = to_num(b2s);
        int s = to_num(s2b);
        n = b - s;
        printf("%04d - %04d = %04d\n", b, s, n);
    }



    return 0;
}