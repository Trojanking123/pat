#include<iostream>
#include<algorithm>
#include<cstring>


using namespace std;

const int kMAX = 20005;

int Next[kMAX];

char str[kMAX];

void getNext(char s[], int len){
    int i = 1;
    int j = -1;
    Next[0] = -1;
    for(; i < len; i++){
        while(j != -1 && s[i] != s[j-1]){
            j = Next[j];
        }
        if(s[i] == s[j+1]){
            j++;
        }
        Next[i] = j;
    }
    
}

bool kmp(char s[], char t[]){
    int n = strlen(s);
    int m = strlen(t);
    getNext(t, m);
    int j = -1;
    
    for(int i = 0; i < n; i++){
        while(j != -1 && s[i] != t[j+1]){
            j = Next[j];
        }
        if(s[i] == t[j+1]){
            j++;
        }
        if(j == m-1){
            return true;
        }
    }
    return false;
}


int main(void){
    char s[kMAX];
    char t[kMAX];
    cin >> s >> t;
    if(kmp(s,t)){
        cout<<"fuck yes\n";
    }



    return 0;
}
