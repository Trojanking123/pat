#include<iostream>
#include<algorithm>

using namespace std;

int main(void){
    int n;
    int i = 0;
    int start = 0;
    int next = 0;
    int total = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin>>next;
        if(next > start){
            total += (next - start) * 6 + 5;
        }else if(next < start){
            total += (start -next) * 4 + 5;
        }else{
            total += 5;
        }
        start = next;
    }

    cout<<total;


    return 0;
}