#include<iostream>
#include<string>
#include<set>

using namespace std;

string input[1005];

int main(void){
    int m, step, start, ignore = 0;
    set<string> checked;
    cin >>m>>step>>start;
    if(m < step+start ){
        printf("Keep going...\n");
        return 0;
    }

    for(int i = 0; i < m; i++){
        string temp;
        cin >> temp;
        input[i] = temp;
    }
    //cout<<"--------------"<<endl;
    for(int i = start; i <= m; i+= step){

        while(checked.find(input[i-1]) != checked.end() && i <= m){
            i++;
        }

        
        printf("%s\n", input[i-1].c_str());
        checked.insert(input[i-1]);
        
    }
    
    return 0;
}