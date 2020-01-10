#include<iostream>
#include<set>
#include<vector>

using namespace std;
const int kMAX = 100005;

vector<int> danger[kMAX];
set< int > ship;

int main(void){
   
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int a,b;
        scanf("%d %d", &a, &b);
        danger[a].push_back(b);
        danger[b].push_back(a);
    }
    //cout<<"---input ok----"<<endl;
    for(int i = 0; i < m; i++){
        int k;
        ship.clear();
        cin >> k;
        //cout<<"k: "<<k<<endl;
        for(int j = 0; j < k; j++){
            int id;
            scanf("%d", &id);
            ship.insert(id);
        }
        //cout<<"---k  input ok----"<<endl;
        bool flag = false;
        for(auto it = ship.begin(); it != ship.end(); it++){
            auto pair = danger[*it];
            for(auto p = pair.begin(); p != pair.end(); p++){
                if(ship.find(*p) != ship.end()){
                    flag = true;
                    break;
                }
            }
            if(flag) break;
            
        }
        if(flag) printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}