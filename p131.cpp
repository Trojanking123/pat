#include<cstdio>
#include<iostream>
using namespace std;

int pow(int x){
    return x*x;
}

int isIntegerPow(int x){
    int mid = x/2;
    int i = 1;
    while(i <= mid){
        if(pow(i) == x) return i;
        i++;
    }
    return 0;
}

int get_up(int x){
    while(1){
        int t = isIntegerPow(x);
        if(t) return t;
        x++;
    }
}

int get_down(int x){
    while(x >= 1){
        int t = isIntegerPow(x);
        if(t) return t;
        x--;
    }
    return 1;
}

double f(double x){
    return x * x;
}

const double eps = 1e-10;

double square(int x){
    double up = get_up(x);
    double down = get_down(x);
    double mid = 0;
    cout<<up<<endl;
    cout<<down<<endl;
    while(up - down  > eps){
        mid = (up + down)/2;
        if(f(mid) > (double)x){
            up = mid;
        }else{
            down = mid;
        }
        //cout<<mid<<endl;
    }
    return mid;


}



int main(void){
    int x;
    cin >> x;
    //square(x);
    printf("%0.15lf", square(x));

    return 0;
}