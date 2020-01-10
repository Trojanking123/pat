#include<iostream>
#include<cmath>



using namespace std;

bool isPrime(int n){
    int k = sqrt(n);
    bool ret = true;
    for(int i = 2; i <= k; i++){
        if(n % i == 0){
            ret = false;
        }
    }

    return ret;
}

int str_to_num_by_radix(string str, int radix){
    int len = str.size();
    int total = 0;
    int base = 1;
    for(int i = len-1; i >= 0; i--){
        total += (str[i]-'0') *base;
        base *= radix;
    }
    return total;
}


int reverse_by_radix(int n, int radix){
    string s = "";
    while(n != 0){
        s += n % radix + '0';
        n = n / radix;
    }
    return str_to_num_by_radix(s, radix);
    
}


int main(void){
    
    int num, radix;
    
    while(1){
        cin >> num;
        if(num < 0 ){
            break;
        }
        
        cin >> radix;

        if(num == 1){
            cout<<"No\n";
            continue;
        }

        if(isPrime(num) && isPrime(reverse_by_radix(num, radix))){
            cout<<"Yes\n";
        }else{
            cout<<"No\n";
        }
        
        

    }




    return 0;
}