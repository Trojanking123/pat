#include<iostream>
#include<stack>
#include<vector>


using namespace std;

int main(void){

    int m, n, k;
    cin >> m >> n >> k;
    
    vector<int >v(n+1);

    while(k--){
        stack<int> s;
        for(int i = 1; i <= n; i++){
            
            cin >> v[i];
        }
        int cur = 1;
        for(int i = 1; i <= n; i++){
            s.push(i);
            if(s.size() > m ) break;
            while( !s.empty() && s.top() == v[cur]) {
                cur++;
                s.pop();
            }
        }
        if(cur == n+1){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }


    return 0;
}