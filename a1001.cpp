#include<iostream>
#include<string>
#include<stack>

using namespace std;

int main(void){
    int a,b;
    cin>>a;
    cin>>b;
    stack<int> stk;
    int res = a+b;
    int base = 1;
    bool positive;
    if(res == 0){
        cout<<0;
        return 0;
    }
    if(res > 0){
        positive = true;
    }else{
        positive = false;
        res = -res;
    }
    while(res / base != 0){
        int temp = res % (base * 10);
        int now = temp/base;
        stk.push(now);
        base *= 10;
    }
    if(!positive) cout<<'-';
    int n= stk.size();
    int remainder = n % 3;
    for(int i = 0;  !stk.empty(); i++){
        cout<<stk.top();
        stk.pop();
        
        if((i+1)%3 == remainder && !stk.empty()){
            cout<<",";
        }
    }

    return 0;
}