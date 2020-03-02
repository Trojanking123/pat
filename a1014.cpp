#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<string>


using namespace std;
const int kMAXQ = 20;
const int kMAXC = 1005;

int n, m, k, query;
int counter = 0;

queue<int> q[kMAXQ];

int start[kMAXC] = {0};
int finish[kMAXC] = {0};
int tm[kMAXC] = {0};

void init(){
    for(int i = 0; i < k && i < n*m; i++){
        counter++;
        int num = i % n;
        
        if(q[num].size() == 0){
            start[i] = 0;
            finish[i] = tm[i];
        }else{
            int last = q[num].back();
            start[i] = finish[last];
            finish[i] = start[i] + tm[i];
        }
        q[num].push(i);
    }
}

void proc(){
    init();
    if(counter == k) return;

    while(counter < k){
        vector<int> qid;
        int min = INT32_MAX;
        for(int i = 0; i < n; i++){
            if(q[i].size() == 0) continue;
            int id = q[i].front();
            if(finish[id] < min){
                qid.clear();
                qid.push_back(i);
            }else if(finish[id] == min){
                qid.push_back(i);
            }
        }
        int last;
        for(int i = 0; i < qid.size(); i++){
            last = q[qid[i]].front();
            q[qid[i]].pop();
        }
        //int last = finish[qid[0]];
        printf("last out q:%d\n", last);
        qid.clear();
        
        min = INT32_MAX;
        for(int i = 0; i < n; i++){
            if(q[i].size() < min){
                qid.clear();
                qid.push_back(i);
                min = q[i].size();
            }else if(q[i].size() == min){
                qid.push_back(i);
            }
        }
        printf(" min q size:%d\n", min);
        for(int i= 0; i < qid.size() && counter < k; i++){
            if(q[qid[i]].size() == 0){
                start[counter] == last;
                finish[counter] = last+tm[counter];
            }else{
                start[counter] = finish[q[qid[i]].back()];
                finish[counter] = start[counter] + tm[counter];
            }
            q[qid[i]].push(counter);
            counter++;
            
        }

    }

}
void print(int* a, int n){
    cout<<"vector: ";
    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    cout<<"\n";
}

string getTime(int id){
    int hour = finish[id]/60;
    int minute = finish[id] % 60;
    hour += 8;
    char ans[50];
    if(8+start[id]/60 >= 17) return "Sorry";
    sprintf(ans, "%02d:%02d", hour, minute);
    return string(ans);
}

int main(void){

    cin >> n >> m >> k >> query;
    for(int i = 0; i < k; i++){
        cin >> tm[i];
    }
    proc();
    print(start, k);
    print(finish, k);

    for(int i = 0; i < query; i++){
        int tmp;
        cin >> tmp; 
        string s = getTime(tmp-1);
        printf("%s\n", s.data());
    }






    return 0;
}
/*
2 2 7 5
1 2 6 4 3 534 2
3 4 5 6 7

  
6 4
3 534 
6 
3 534
    2


*/