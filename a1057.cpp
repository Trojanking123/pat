#include<iostream>
#include<vector>
#include<algorithm>
#include<set>


using namespace std;


int main(void){
    vector<int> stk;
    set<int> fm;
    int n;
    cin >> n;
    string op;
    for(int i = 0; i < n; i++){
        cin >> op;
        if(op == "Pop"){
            if(stk.size() == 0){
                printf("Invalid\n");
            }else{
                printf("%d\n", stk.back());
                stk.pop_back();
            }
        }else if(op == "Push"){
            int key;
            cin >> key;
            stk.push_back(key);
            fm.insert(key);
        }else{
            if(stk.size() == 0){
                printf("Invalid\n");
            }else{
                int s = (stk.size()+1)/2;
                auto it = fm.begin();
                for(int j = 0; j < s; j++){
                    it++;
                }
                
                printf("%d\n", *it);
            }
        }
    }






    return 0;
}

/*
17
Pop invalid
PeekMedian invalid
Push 3 
PeekMedian 3
Push 2 
PeekMedian 2
Push 1 
PeekMedian 2
Pop 1
Pop 2
Push 5 
Push 4
PeekMedian 5
Pop
Pop
Pop
Pop


1
2
3

*/