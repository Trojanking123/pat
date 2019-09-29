#include<cstdio>
#include <cstring>
#include<algorithm>

using namespace std;

char in[100005];

int main(void){
    char err[258];
    char hash[256] = {false};
    fgets(err, 256, stdin);
    scanf("%s",in);
    int lenerr = strlen(err);
    int lenin= strlen(in);
    for(int i = 0; i < lenerr; i++){
        if(err[i] == '+'){
            for(char c = 'A'; c <= 'Z'; c = c+1){
                hash[c] = true;
                 
            }
        }else{
            if(err[i] <= 'Z' && err[i] >='A'){
                hash[err[i]] = true;
                hash[err[i]-'A'+'a'] = true;
            }else{
                hash[err[i]] = true;
            }
            
        }
    }
    int move = 0;
    for(int i = 0; i < (lenin-move); ){
        if( hash[in[i+move]] ){
            move++;
            continue;
        }else{
            in[i] = in[i+move];
            i++;
        }
    }
    in[lenin-move] = '\0';
    printf("%s\n",in);

    return 0;
}