#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

typedef long int L;

struct pfactor {
    long int factor = 0;
    long int times = 0;
} pf[22];

int main(void){
    L  n;
    cin>> n;
    int pnum = 0;
    L temp = n;
    
    L i = 2;
    
    if( n == 1){
        printf("1=1");
        return 0;
    }

    while(n != 1){
        if(n % i == 0){
            pf[pnum].factor = i;
            //pf[pnum].times = 1;
            do{
                n = n / i;
                pf[pnum].times += 1;
            }while(n % i == 0);
            pnum++;
        }
        i++;
        
    }

    printf("%ld=", temp);
    for(int j = 0; j < pnum; j++){
        cout<<pf[j].factor;
        if(pf[j].times != 1){
            printf("^%ld", pf[j].times); 
        }
        if(j != pnum - 1){
            printf("*");
        }

    }

    return 0;
}