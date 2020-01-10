#include<cstdio>
#include<algorithm>

using namespace std;

class mooncake{
public:
    double amount;
    double sale;
    double price;
};

mooncake inventory[1001];

bool cmp(mooncake a, mooncake b){
    return a.price>b.price;
}

int main(void){
    int n, demond;
    scanf("%d %d", &n, &demond);
    for(int i = 0; i < n; i++){
        scanf("%lf", &inventory[i].amount);
    }

    for(int i = 0; i < n; i++){
        scanf("%lf", &inventory[i].sale);
        inventory[i].price = inventory[i].sale/inventory[i].amount;
    }

    sort(inventory, inventory+n, cmp);
    
    double profit = 0;

    for(int i = 0; i < n; i++){
        if(inventory[i].amount <= demond){
            demond -= inventory[i].amount;
            profit += inventory[i].sale;
        }else{
            profit += inventory[i].price*demond;
            demond = 0;
            break;
        }
    }
    printf("%.2f", profit);

    return 0;
}