#include<iostream>
#include<cmath>

using namespace std;

struct Pair{
    int value;
    //int index;
}input[10001];

bool hashh[20001] = {false};

int get_prime(int n){
    if(n <= 2) return 2;
    int t = sqrt(n);
    while(1){
        bool prime = true;
        for(int i = 2; i <= t; i++){
            if(n % i == 0) prime = false;
        }
        if(prime) return n;
        n++;
    }
}

int get_index( bool* hash, int prime, int value){
    int k = value % prime;
    
    int i = 1;
    while(hash[k] == true && k < prime){
        //cout<<"probe k:"<<k<<endl;
        k = (value + i*i) % prime;
        i++;
        
    }
    if(k >= prime) return -1;
    hash[k] = true;
    return k;
}

int main(void){
    int m,n;
    cin >> m >> n;
    int prime = get_prime(m);
    
    //printf("priem:%d\n", prime);
    for(int i = 0; i < n; i++){
        cin >> input[i].value;
        int temp = get_index(hashh,  prime, input[i].value);
        if(temp != -1){
            printf("%d", temp);
        }else{
            printf("-");
        }
        if(i != n-1){
            printf(" ");
        }else{
            printf("\n");
        }
    }
    


    return 0;
}