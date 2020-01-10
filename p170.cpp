#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>

using namespace std;


template<int N>
class bigint{
public:
    bigint(char* a){
        int n = strlen(a);
        int i = 0;
        for(int i = 0; i < n; i++){
            data[i] = a[n - i -1] - '0'; 
        }
        len = n;
    }
    bigint(string str){
        bigint(str.c_str());
    }

    bigint(){
        ;
    }

    bigint( bigint & bg){
        cout<<"copy ref\n";
        len = bg.len;
        for(int i = 0; i < len; i++){
            data[i] = bg.data[i];
        }
    }

    bigint(bigint && bg){
        cout<<"rvalue ref\n";
        len = bg.len;
        data = bg.data;
    }

    friend istream& operator >>(istream& in, bigint& bi){
        string s;
        in >> s;
        const char *a = s.c_str();
        int n = strlen(a);
        int i = 0;
        for(int i = 0; i < n; i++){
            bi.data[i] = a[n - i -1] - '0'; 
        }
        bi.len= n;

        return in;
    }

    friend ostream& operator <<(ostream& ou,  bigint & bi){
        for(int i = 0; i < bi.len; i++){
            ou<< bi.data[bi.len - i - 1];
        }
        
        return ou;
    }

    bigint & operator + (const bigint& bi){
        const int k = N > bi.N ? N : bi.N ;+
        bigint<k> a;
        cout<< bi.N;
        return a;
    }




private:
    int data[N];
    int len;

};


int main(void){
    char s[50] = "123456";
    bigint<100> a(s);
    bigint<100> b(a);
    cout<<a+b;
    cout<<b;
    

    return 0;
}