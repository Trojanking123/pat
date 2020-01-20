#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

priority_queue<int, vector<int>, greater<int> > q;

int main(void){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        q.push(temp);
    }
    int ans = 0;
    while(q.size() > 1){
        int x = q.top();
        q.pop();
        int y = q.top();
        q.pop();
        ans += x+y;
        q.push(x+y);
    }
   

    printf("%d\n", ans);



    return 0;
}