#include<iostream>
#include<string>
#include<map>
#include<cmath>
#include<set>

using namespace std;

bool isPrime(int n){
    int temp = sqrt(n);
    for(int i = 2; i <= temp; i++){
        if(n % i == 0)  return false;
    }
    return true;
}

int main(void){
    
    
    int k,n;
    cin >> k;
    map<string,int > members;
    set<string> checked;
    for(int i = 0; i < k; i++){
        string temp;
        cin >> temp;
        members[temp] = i+1;
    }
    cin >> n;
    for(int i = 0; i < n; i++){
        string temp;
        cin >> temp;
        int rank = members[temp];
        //cout<<temp<<" rank: "<<rank<<endl;
        if(checked.find(temp) != checked.end()){
            //cout<<temp<<" "<<endl;
            printf("%s: Checked\n", temp.c_str());
        }else{
            checked.insert(temp);
            if(rank == 1) {
                //cout<<temp<<": Mystery Award"<<endl;
                printf("%s: Mystery Award\n", temp.c_str());
            }else if(rank == 0){
                checked.erase(temp);
                //cout<<temp<<": Are you kidding?"<<endl;
                printf("%s: Are you kidding?\n", temp.c_str());
            }else if(isPrime(rank)){
                cout<<temp<<": Minion"<<endl;
            }else{
                //cout<<temp<<": Chocolate"<<endl;
                printf("%s: Chocolate\n", temp.c_str());
            }
            
        }
        
    }
    
    
    return 0;
}