#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int getZero(string& s){
    int ans = 0;
    while( ans < s.size() && s[ans] == '0') ans++;
    return ans;
}
int getFirst(vector<string>& all){
    int num = 0;
    int max = -1;
    int ans = -1;
    for(int i = 0; i < all.size(); i++){
        int temp = getZero(all[i]);
        if(temp == 0) continue;
        if(temp > max){
            max = temp;
            ans = i;
        }else if(temp == max){
            ans = all[ans] < all[i] ? ans : i;
        }
    }
    return ans;
}

int main(void){
    
    vector<string> all;
    int n;
    string ans;
    cin >> n;
    string temp;
    for(int i = 0; i < n; i++){
        cin >> temp;
        all.push_back(temp);
    }
    int numZero;
    int f = getFirst(all);
    if(f != -1){
        numZero = getZero(all[f]);
        string t = all[f].substr(numZero);
        ans += t;
        all.erase(all.begin()+f);
    }
    sort(all.begin(), all.end());
    for(int i = 0; i < all.size(); i++){
        //ans +='|';
        ans += all[i];
    }
    printf("%s\n", ans.data());

    return 0;
}
/*
22932321321487

22932132143287

*/