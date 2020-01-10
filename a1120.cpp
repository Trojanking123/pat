#include<iostream>
#include<set>

using namespace std;

int getSum(int n){
    int base = 10;
    int ret = 0;
    while(n != 0){
        ret += (n % base);
        n /= base;
    }
    return ret;
}


int main(void){
    int n;
    set<int > ids;
    cin >> n;
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        ids.insert(getSum(temp));
    }

    cout<<ids.size()<<endl;
    auto iter = ids.begin();
    
    printf("%d", *iter);
    iter++;
    for(; iter != ids.end(); iter++){
        printf(" %d", *iter);
    }

    return 0;
}