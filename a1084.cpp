#include<cstdio>
#include <cstring>
#include<algorithm>

using namespace std;

int main(void){
    char typein[90],typeout[90];
    int countin[128] = {0};
    int countout[128] = {0};
    scanf("%s%s",typein, typeout);
    
    int lenin = strlen(typein);
    int lenout = strlen(typeout);
    bool flag[128] = {false};
    int j = 0;
    for(int i = 0; i < lenin; ){
        if(typein[i] == typeout[j]){
            i++;
            j++;
        }else{
            char c = typein[i];
            if(c <= 'z' && c >= 'a'){
                if(flag[c-'a'] != true){
                    flag[c-'a'] = true;
                    printf("%c",c-'a'+'A');
                }
                
            }else if(c <= 'Z' && c >= 'A'){
                if(flag[c-'A']  != true){
                    flag[c-'A']  = true;   
                    printf("%c",c);
                }
                           
            }else if(c <= '9' && c>='0'){
                if(flag[c-'0'+26] != true){
                    flag[c-'0'+26] = true;
                    printf("%c",c);
                }
            }else{
                if(flag[36] != true){
                    flag[36] = true;
                    printf("%c",'_');
                }
                flag[36] = true;
            }
            i++;
        }
    }
    
    
    printf("\n");

    return 0;
}