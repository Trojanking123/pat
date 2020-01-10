#include<iostream>

using namespace std;

int count[10001] = {0};
int array[100001];


int main(void){

    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> array[i];
        count[array[i]]++;
    }
    for(int i = 0; i < n; i++){
        if(count[array[i]] == 1){
            cout<<array[i];
            return 0;
        }
    }
    
    cout<<"None";


    return  0;
}