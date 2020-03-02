#include<iostream>
#include<algorithm>
#include<vector>


using namespace std;


int main(void){
    vector<int> vec;
    int n,m;
    scanf("%d", &n);
    int temp;
    for(int i = 0; i < n; i++){
        scanf("%d", &temp);
        vec.push_back(temp);
    }
    scanf("%d", &m);
    for(int i = 0; i < m; i++){
        scanf("%d", &temp);
        vec.push_back(temp);
    }
    sort(vec.begin(), vec.end());
    
    n = vec.size();
    if(n%2){
        
        printf("%d\n",vec[n/2]);

    }else{
        printf("%d\n",vec[n/2-1]);
    }
    


    return 0;
}