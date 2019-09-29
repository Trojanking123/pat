
#include<cstdio>

int main(int argc, const char** argv) {
    int total = 0;
    int score[105] = {0}, temp;
    scanf("%d", &total);
    for(int i = 0; i < total; i++){
        scanf("%d", &temp);
        score[temp] += 1;
    }
    int n ;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &temp);
        if(i != n-1){
            printf("%d ", score[temp]);
        }else
        {
            printf("%d", score[temp]);
        }    
    }
    return  0;
}