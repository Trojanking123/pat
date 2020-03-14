#include<iostream>
#include<vector>
#include<set>

using namespace std;


const int kMAX = 10004;
int father[kMAX];
int counter[kMAX];

int n;
int k;

int kmax = -1;

int findFather(int x){
    while(x != father[x]){
        x = father[x];
    }
    return x;
}

void Union(int a, int b){
    a = findFather(a);
    b = findFather(b);
    father[a] = b;
    counter[b] += counter[a];
    //printf("father of %d is %d now, counter of %d is %d now\n", a, b, b, counter[b]);
}

int main(void){
    for(int i = 0; i < kMAX; i++){
        father[i] = i;
        counter[i] = 1;
    }
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> k;
        vector<int> birds;

        for(int j = 0; j < k; j++){
            int temp;
            cin >> temp;
            birds.push_back(temp);
        }
    
        bool flag = false;
        int f;
        for(int p = 0; p < birds.size(); p++){
            f = findFather(birds[p]);
            //printf("%d %d %d\n", birds[p], f, father[birds[p]]);
            if(f != birds[p] ){
                flag = true;
                break;
            }
        }
        if(!flag){
            //cout<<"new tree\n";
            for(int p = 1; p < birds.size(); p++){
                Union( birds[p], birds[0]);
            }
        }else{
            //cout<<"old tree\n";
            for(int p = 0; p < birds.size(); p++){
               
                if(findFather( birds[p]) != f ){
                    Union(birds[p], f);
                }
            }
        }
            
        
        //cout<<"down\n";

        
    }

    int q;
    vector<bool> store ;
    set<int> all;

    cin >> q;
    for(int i = 0; i < q; i++){
        int a, b;
        cin >> a >> b;
        int fa = findFather(a);
        int fb = findFather(b);
        if( fa == fb ){
            store.push_back(true);
            all.insert(fa);
            
        }else{
            store.push_back(false);
            all.insert(fa);
            all.insert(fb);
        }
    }
    int total = 0;
    for(auto it = all.begin(); it != all.end(); it++){
        total += counter[*it];
    }
    printf("%d %d\n", all.size(), total);
    for(int i = 0; i < store.size(); i++){
        if(store[i]){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }




    return 0;
}