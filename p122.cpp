#include<cstdio>
#include<algorithm>

using namespace std;

const int maxn = 110;

struct Intervel{
    int x;
    int y;
} I[maxn];

bool cmp(Intervel a, Intervel b){
    if(a.x != b.x) return a.x>b.x;
    else return a.y<b.y;
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d %d", &I[i].x, &I[i].y);
    }

    sort(I, I+n, cmp);

    int ans = 1;
    int lastx = I[0].x;
    for(int i =1; i < n; i++){
        if(I[i].y <= lastx){
            lastx = I[i].x;
            ans++;
        }
    }
    printf("%d", ans);

    return 0;
}