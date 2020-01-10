#include<iostream>
#include<algorithm>
#include<string>


using namespace std;

string low[13] = { "tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string high[13] = {"tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};

string to_mars(string str){
    if(str=="0") return "tret";
    int num = 0;
    int base = 1;
    for(int i = str.size()-1; i >= 0; i--){
        num += (str[i]-'0') * base;
        base *= 10;
    }
    string ret;
    if(num / 13) ret += high[num/13];
    if(num%13){
        if(num / 13) ret += " ";
        ret += low[num % 13];
    }
    
    return ret;
}

int get_num(string str, int flag){
    //cout<<str<<endl;
    if(flag){
        for(int i = 0; i < 13; i++){
            if(str == high[i]) return i;
        }
    }else{
        for(int i = 0; i < 13; i++){
            if(str == low[i]) return i;
        }
    }
    return -1;
}


int to_earth(string str){
    if(str == "tret") return 0;
    int k = 0;
    k = get_num(str,1);
    if(k  > 0) return k*13;
    
    if(str.size() == 3) return get_num(str, 0);
    else{
        int h = get_num(str.substr(0,3), 1);
        return h*13+get_num(str.substr(4,3), 0);
    }
}

int main(void){
    
    int n;
    string str;
    cin >> n;
    getchar();
    for(int i = 0; i < n; i++){
        
        getline(cin, str);
        //cin >> str;
     
        if(str[0] >='0' && str[0] <= '9'){
            printf("%s\n", to_mars(str).c_str());
        }else{
            printf("%d\n", to_earth(str));
        }
    }
    
   

    return 0;
}