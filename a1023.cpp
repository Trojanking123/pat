#include<iostream>
#include<cstring>

using namespace std;

void reverse(char * num){
    int n = strlen(num);

    int i = 0;
    int j = n-1;
    while(i < j){
        int temp = num[i];
        num[i] = num[j];
        num[j] = temp;
        j--;
        i++;
    }
}

int count[10] = {};

int main(void){
    char num[25];
    char num2[25];

    cin >> num;
    int n = strlen(num);
    reverse(num);
    int carry = 0;
    for(int i = 0; i < n; i++){
        int res = (num[i] - '0')*2;
        num2[i] = '0' + res % 10 + carry;
        carry = res /10;
    }
    num2[n]='\0';
    for(int i = 0; i < n; i++){
        count[ num[i]-'0' ]++;
        count[ num2[i] -'0']--;
    }
    bool judge = true;
    for(int i = 0; i < 10; i++){
        if(count[i] != 0){
            judge = false;
            break;
        }
    }
    reverse(num2);
    if( judge && !carry){
        cout<<"Yes\n";
        cout<<num2;
        return 0;
    }
    cout<<"No\n";
    if(carry){
        cout<<"1";
        
    }
    cout<<num2;


    return 0;
}