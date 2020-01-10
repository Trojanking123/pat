#include<cstdio>
#include<algorithm>

using namespace std;

int array[100001];

int main(void){
    
    int num, max;
    int p;
    scanf("%d %d", &num, &p);
   
    for(int i = 0; i < num; i++){
        scanf("%d", array+i);
       
    }

    sort(array, array+num);

    long long  min = array[0];
    max = array[num-1];

    int left = 0;
    int right = num-1;
    long long x = min*p;
    
 

    while(left < right){
        int mid = left + (right - left)/2;
        if(array[mid] <= x) left = mid;
        else right = mid-1;
    }

    printf("%d", array[right]);

    return 0;
}