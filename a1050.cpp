#include<iostream>
#include<cstring>
#include<string>
using namespace std;

char s1[10001];
char s2[10001];

bool isSubchar(char a, int len, char * s){
    for(int i = 0; i < len; i++){
        if(s[i] == a){
            return true;
        }
    }
    return false;
}

int main(void){
    
    scanf( "%[^\n]", s1 );
    int temp = getchar();
    scanf( "%[^\n]", s2 );

    
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int step = 0;
    for(int i = 0; i < len1; i++){
        if(isSubchar(s1[i], len2, s2)){
            step++;
        }else{
            s1[i-step] = s1[i];
        }
    }
    s1[len1-step] = '\0';
    cout<<s1;

    return 0;
}