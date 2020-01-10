#include<iostream>
#include<set>


using namespace std;

typedef long long   LL;

set<LL> input;

int main(void){

    LL n = 0, temp, max = -1;
    cin >> n;
    for(LL i = 0; i < n; i++){
        cin >> temp;
        if(temp > 0) input.insert(temp);
        if(temp > max) max = temp;
    }
    
    for(LL i = 1; i <= max+10; i++){
        if(input.find(i) == input.cend()){
            printf("%ld\n", i);
            return 0;
        }
        
    }


    return 0;
}