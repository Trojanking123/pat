#include<iostream>

using namespace std;

const int kMAX = 100;
int heap[kMAX];

int n = 10;

void downAdjust(int low, int high){
    int i = low;
    int j = i * 2;
    while(j <= high){
        if(j+1 <= high && heap[j+1] > heap[j]){
            j += 1;
        }
        if(heap[j] > heap[i]){
            swap(heap[i], heap[j]);
            i = j;
            j = i * 2;
        }else{
            break;
        }
    }
}
void upAdjust(int low, int high){
    int i  = high;
    int j = i / 2;
    while( j >= low ){
        if(heap[i] >= heap[j] ){
            swap(heap[i], heap[j]);
            i = j;
            j = i / 2;
        }else{
            break;
        }
        
    }

}

void insert(int x){
    heap[++n] = x;
    upAdjust(1, n);
}

void createHeap(){
    for(int i = 0; i < n; i++){
        downAdjust(i, n);
    }
}

void deleteHeap(){
    heap[1] =  heap[n--];
    downAdjust(1, n);
}

void heapSort(){
    for(int i = n; i > 1; i--){
        swap(heap[i], heap[1]);
        downAdjust(1, i-1);
    }
}


int main(void){




    return 0;
}