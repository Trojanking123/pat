#include<cstdio>
#include<cstring>
int main(void){
    int eva[62] = {0};
    int store[62] = {0};

    bool yes = true;

    char input[1005];
    scanf("%s", input);

    for(int i = 0; i < strlen(input); i++){
        if(input[i] >= '0' && input[i] <= '9'){
            store[input[i] - '0']++;
        }else if (input[i] >= 'a' && input[i] <= 'z')
        {
            store[input[i]- 'a' + 10]++;
        }else if (input[i] >= 'A' && input[i] <= 'Z')
        {
            store[input[i]- 'A' + 36]++;
        }
    }


    scanf("%s", input);

   
    for(int i = 0; i < strlen(input); i++){
        if(input[i] >= '0' && input[i] <= '9'){
            eva[input[i] - '0']++;
        }else if (input[i] >= 'a' && input[i] <= 'z')
        {
            eva[input[i]- 'a' + 10]++;
        }else if (input[i] >= 'A' && input[i] <= 'Z')
        {
            eva[input[i]- 'A' + 36]++;
        }
    }

    for(int i = 0 ; i < 62; i++){
        store[i] -= eva[i];
        //printf("%d %d || \n", i, store[i]);
        if(store[i] < 0){
            yes = false;
        }
    }
    int total = 0;
    if(!yes){
        for(int i = 0 ; i < 62; i++){
            if(store[i] < 0) total += store[i];
        }
        printf("No %d", -total);
    }else
    {
        for(int i = 0 ; i < 62; i++){
            total += store[i];
        }
        printf("Yes %d",total);
    }
    

    return 0;
}