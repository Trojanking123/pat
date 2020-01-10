#include<iostream>
#include<algorithm>
#include<string>
#include<map>
using namespace std;

bool isAlphaNumAndLowerCase(char& a){
    //printf("judge:%c\n", a);
    if((a >='0' && a <= '9') || (a >= 'a' && a <= 'z')  || (a >= 'A' && a <= 'Z')){
        if(a >= 'A' && a <= 'Z'){
            a -= 'A';
            a += 'a';
            
        }
        return true;
    }
    return false;
}


int main(void){
    string input;
    getline(cin, input);
    map<string, int> counter;
    //cout<<input<<endl;
    auto iter = input.begin();
    while(iter != input.cend()){
        while( iter < input.cend() && !isAlphaNumAndLowerCase(*iter)  ) iter++;
        //printf("iter:%c\n", *iter);
        auto temp = iter + 1;
        while(temp < input.cend() && isAlphaNumAndLowerCase(*temp)  ) temp++;
        //printf("temp:%d\n", temp-iter);
        if(temp > input.cend()) break;
        string str = input.substr(iter-input.begin(), temp-iter);
        //cout<<"substr:"<<str<<endl;
        counter[str]++;
        iter = temp;
    }
    int value = -1;
    string key = "\255";
    for(auto iter = counter.begin(); iter != counter.cend(); iter++){
        if(iter->second > value){
            value = iter->second;
            key = iter->first;
        }else if(iter -> second == value){
            key = key>iter->first ? iter->first : key;
        }
    }
    cout<<key<<" "<<value;
    


    return 0;
}