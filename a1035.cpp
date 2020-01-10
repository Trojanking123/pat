#include<iostream>
#include<cstring>

using namespace std;

struct Team{
    char name[15];
    char pwd[15];
    bool modified = false;
}teams[1002];



int main(void){
    int n;
    int m = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> teams[i].name;
        cin >> teams[i].pwd;
        int len = strlen(teams[i].pwd);

        teams[i].modified = false;

        for(int j = 0; j < len; j++){
            if(teams[i].pwd[j] == '1'){
                teams[i].pwd[j] = '@';
                teams[i].modified = true;
              
            }else if(teams[i].pwd[j] == '0'){
                teams[i].pwd[j] = '%';
                teams[i].modified = true;
                
            }else if(teams[i].pwd[j] == 'l'){
                teams[i].pwd[j] = 'L';
                teams[i].modified = true;
               
            }else if(teams[i].pwd[j] == 'O'){
                teams[i].pwd[j] = 'o';
                teams[i].modified = true;
                
            }
            
        }
        if(teams[i].modified) m++;
    }
    if (m == 0){
        if(n == 1) cout<<"There is 1 account and no account is modified";
        else printf("There are %d accounts and no account is modified", n);
        return 0;
    }
    
    cout<< m<<endl;
    for(int i = 0; i < n; i++){
        if(teams[i].modified){
            cout<<teams[i].name<<" "<<teams[i].pwd<<endl;
        }
    }


    return 0;
}