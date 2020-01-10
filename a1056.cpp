/*
11 3
0  1  2  3  4  5  6  7  8  9  10
25 18 0  46 37 3  19 22 57 56 10
1  1  1  2d 1  1  1  2b 2a 2c 1 
         3b             3a
                        4a        
6 0 8 7 10 5 9 1 4 2 3

5 5 5 2 5 5 5 3 1 3 5
5 5 5 2 5 5 5 3 1 3 5
*/


#include<iostream>
#include<queue>
#include<vector>

using namespace std;

struct Mice{
    int weight=0;
    int rank=0;
};

int rankCounter[100000000] = {0};

int getActualRank(int rank){
    int ret = 0;
    for(int i = 0; i < rank; i++) ret+= rankCounter[i];
    return ret - rank + 1;
}

int main(void){

    int n, m, maxRank = 0;
    cin >> n >> m;
    vector<Mice> mices(n+1);
    queue<int> round;
    for(int i = 0; i < n; i++){
        cin >>mices[i].weight;
    }
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        round.push(temp);
    }
    round.push(-1);

    while(round.size() != 2){
        int maxWeght = -1;
        int maxID = -1;

        int i = 0;
        int id;
        while((id=round.front()) != -1 && i < m){
            round.pop();
            if(mices[id].weight > maxWeght){
                maxWeght = mices[id].weight;
                maxID = id;
            }
            i++;
        }
        

        mices[maxID].rank++;
        round.push(maxID);
        if(id == -1) {
            maxRank++;
            round.pop();
            round.push(-1);
        }
    }
    //cout<<maxRank<<endl;
    for(int i = 0; i < n; i++){
        //if(i == 0) printf("%d", maxRank - mices[i].rank + 1);
        //else printf(" %d", maxRank - mices[i].rank + 1);
        mices[i].rank = maxRank - mices[i].rank + 1;
        rankCounter[mices[i].rank]++;
    }
    for(int i = 0; i < n; i++){
        if(i == 0) printf("%d", mices[i].rank + getActualRank(mices[i].rank));
        else printf(" %d", mices[i].rank + getActualRank(mices[i].rank) );
    }
    return 0;
}
