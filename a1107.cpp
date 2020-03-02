#include<iostream>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;

const int kMAX = 1005;

int father[kMAX] = {0};
map<int, int> counter;
int n;

int findFather(int v){
    if(v == father[v]) return v;
    else {
        int f = findFather(father[v]);
        father[v] = f;
        return f;
    }
}


int main(void){
    cin >> n;
    for(int i = 0; i <= 1000; i++){
        father[i] = i;
    }
    vector<int> hobbies;
    for(int i = 0; i < n; i++){
        int k, temp;
        scanf("%d:", &k);
        //printf("get k:%d\n", k);
        hobbies.clear();
        for(int j = 0; j < k; j++){
            cin >> temp;
            hobbies.push_back(temp);
        }
        int f;
        bool flag = false;
        for(int j = 0; j < hobbies.size(); j++){
            int tmp = findFather(hobbies[j]);
            if(counter.find(tmp) != counter.end()){
                flag = true;
                f = tmp;
                break;
            }
        }
        if(!flag) f=hobbies[0];
        //printf("%d father:%d\n",k, f );
        for(int j = 0; j < hobbies.size(); j++){
            father[hobbies[j]] = f;
        }
        counter[f]++;
    }
    
    vector<int> sum;

    for(auto it = counter.begin(); it != counter.end(); it++){
        sum.push_back(it->second);
    }
    sort(sum.begin(), sum.end(), greater<int>());

    printf("%d\n",sum.size());
    printf("%d", sum[0]);
    for(int i = 1; i < sum.size(); i++){
        printf(" %d", sum[i]);
    }

    return 0;
}