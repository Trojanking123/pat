#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

bool cmp(int a, int b){
    if( a>0 && b > 0 ) return a > b;
    else if(a < 0 && b < 0) return a < b;
    else return a > b;
};

int main(void){
    int posProduct = 0;
    int posCoupon = 0;
    int negProduct = 0;
    int negCoupon = 0;

    int n,m;
    vector<int> product;
    vector<int> coupon;
    int temp;

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> temp;
        coupon.push_back(temp);
        if(temp >= 0){
            posCoupon++;
        }else{
            negCoupon++;
        }
    }

    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> temp;
        product.push_back(temp);
        if(temp>=0){
            posProduct++;
        }else{
            negProduct++;
        }
    }

    sort(product.begin(), product.end(), cmp);
    sort(coupon.begin(), coupon.end(), cmp);
    int minPos = posProduct > posCoupon? posCoupon : posProduct;
    int minNeg = negProduct > negCoupon? negCoupon : negProduct;
    int ans = 0;
    //printf("---%d %d\n", minPos, minNeg);
    for(int i = 0; i < minPos; i++){
        ans += product[i]*coupon[i];
    }
    //printf("pos ans:%d\n",ans);
    for(int i = 0; i < minNeg; i++){
        ans += product[posProduct+i] * coupon[posCoupon+i];
    }

    printf("%d\n", ans);



    return 0;
}