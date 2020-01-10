#include<cstdio>
#include<algorithm>
#include<cstring>


typedef long long LL;

using namespace std;

const int MAX_RADIX = 4294967295;

long long convert(char * a, int radix){
    int size = strlen(a);
    long long ret = 0;
    int i = size -1;
    long long base = 1;
    while(i >= 0){
        if(a[i] >= 'a' && a[i] <= 'z') ret += base * (a[i]-'a' + 10);
        else ret += base * (a[i] - '0');
        base *= radix;
        i--;
    }
    return ret;
}

int get_min_radix(char *a){
    int max = 0;
    int size = strlen(a);
    for(int i = 0; i < size; i++){
        if(a[i] >= max) max = a[i];
        //printf("--%d\n", max);
    }
    if(max >= 'a' && max<= 'z') return max-'a'+11;
    return max-'0' + 1;
}

int bs(char* a, int left, int right, LL x){
    LL temp = 0;
    while(left <= right){
        int mid = (left + right) /2;
        LL temp = convert(a, mid);
        //printf("left:%d right:%d radix:%d value:%ld\n",left, right, mid, temp);
        if(temp == x){
            return mid;
        }else if(temp < x){
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }

    return -1;
}






int main(void){

    char n1[15] = {0};
    char n2[15] = {0};
    LL x;

    int tag = 0;
    int radix = 0;
    int min_radix = 0;
    int ret;

    scanf("%s %s", n1, n2);
    scanf("%d %d", &tag, &radix);

    //printf("%d %d\n", get_min_radix(n1),  get_min_radix(n2));

    if(tag == 1){
        x = convert(n1, radix);
        min_radix = get_min_radix(n2);
        ret = bs(n2, min_radix, MAX_RADIX, x);
    }else{
        x = convert(n2, radix);
        min_radix = get_min_radix(n1);
        ret = bs(n1, min_radix, MAX_RADIX, x);
    }
    
    

    if(ret == -1){
        printf("Impossible");
    }else{
        printf("%d", ret);
    }

    return 0;
}