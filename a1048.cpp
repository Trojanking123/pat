#include<cstdio>

int main(void){

    int n = 0;
    int bill = 0;
    int coin[1005] = {0};
    int temp;
    scanf("%d %d", &n, &bill);
    for(int i = 0; i < n; i++){
        scanf("%d", &temp);
        coin[temp]++;
    }



    

    for(int i = 0; i < bill; i++){
      
        if( coin[i] && coin[ bill-i ]){

            if( (i == bill -i) && (coin[i] < 2) ){
                continue;
            } 
            printf("%d %d", i , bill -i);
            return 0;
            
            
        }
    }
    printf("No Solution");
    return 0;
}