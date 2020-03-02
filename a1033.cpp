#include<cstdio>
#include<algorithm>

using namespace std;

struct station{
    double price;
    int dis;
}  sta[501];

bool cmp(station a, station b){
    if(a.dis < b.dis){
        return true;
    }
    return false;
}

int get_next_station(station * s, int now, int n, int could){
    int next = now+1;
    double p = 1000000;
    int ret = -1;
    while(s[next].dis <= (s[now].dis + could)){
        if(s[next].price < p){
            p = s[next].price;
            ret = next;
        }
        next++;
    }
    return ret;
}

double cal_gas(station* s, int now, int next, int unit){
    double dis = s[next].dis - s[now].dis;
    return (dis / unit);
}

int main(void){
    int cap;
    int distance;
    int unit;
    int n;
    
    scanf("%d %d %d %d", &cap, &distance, &unit, &n);
    for(int i = 0; i < n; i++){
        scanf("%lf %d", &(sta[i].price), &(sta[i].dis));
    }
    sort(sta, sta+n, cmp);

    int now = 0;
    double cost = 0;
    double oil = 0;
    int moved = 0;
    double could = cap*(double)unit;
    while(now < n){
        int next = get_next_station(sta, now, n, could);
        if(next == -1){
            printf("The maximum travel distance = %0.2f", moved + could);
            return 0;
        }else if(next == n-1){
            double k = cal_gas(sta, now, next, unit);
            if(k > oil){
                cost += (k - oil)* sta[now].price;
            }
            printf("0.2%f", cost);
            return 0;

        }else if(sta[next].price > sta[now].price){
            cost += (cap - oil) * sta[now].price;
            oil = cap - cal_gas(sta, now, next, unit);
            now = next;
            moved = sta[now].dis;

        }else{
            double k = cal_gas(sta, now, next, unit);
            if(k > oil){
                cost += (k-oil) * sta[now].price;
                moved = sta[next].dis;
                now = next;
                oil = 0;

            }else{
                oil -= k;
                now = next;
                moved = sta[next].dis;
            }
        }
    }
    return 0;
}