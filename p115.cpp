#include<cstdio>

const int maxn = 20;
int array[maxn];
bool hash_table[maxn] = {false};
int count = 0;

int abs(int n){
    if(n > 0) return n;
    else
    {
        return -n;
    }
    
}

bool func(int n){
    bool judge = true;
    for(int i = 1; i <= n; i++){
        for(int j = i+1; j <= n; j++ ){
            if(abs(j-i) == abs(array[i] - array[j])){
                judge = false;
            }
        }
    }
    return judge;
}

void gen(int index, int n){
    if(index > n){
        bool judge = true;
        for(int i = 1; i <= n; i++){
            for(int j = i+1; j <= n; j++ ){
                if(abs(j-i) == abs(array[i] - array[j])){
                    judge = false;
                }
            }
        }
        if(judge) count++;
        return;
    }



    for(int i = 1; i <= n; i++){
        if(hash_table[i] == false){
             array[index] = i;
             hash_table[i] = true;
             gen(index+1, n);
             hash_table[i] = false;
        }
    }

}


int main(void){
    int n;
    scanf("%d", &n);
    gen(1, n);
    printf("%d", count);
    return 0;
}