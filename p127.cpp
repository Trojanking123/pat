#include<cstdio>
#include<iostream>
using namespace std;


int binarysearch(int a[], int left, int right, int x){
    int mid = -1;
    while(left <= right){
        mid = left + (right - left)/2;
        if(a[mid] == x){
            return mid;
        }else if(a[mid] > x){
            right = mid-1;
        }else{
            left = mid + 1;
            
            
        }
    }
    return mid;
}


int lower_bound(int a[], int left, int right, int x){
    int mid;
    while(left < right){
      
            mid = left+(right-left)/2;
            if(a[mid] >= x){
                right = mid;
            }else{
                left = mid + 1;
            }
        
    }

    return left;
}

int upper_bound(int a[], int left, int right, int x){
    int mid;
    while(left < right){
        mid = left + (right - left)/2;
        if(a[mid] > x){
            right = mid;

        }else{
            left = mid+1;
        }

    }
    return right;
}

int main(void){

    int a[6]= { 1,5,7,9,9,10};
    cout<<lower_bound(a, 0, 6, 9);
    cout<<upper_bound(a,0,6, 9);
    return 0;
}