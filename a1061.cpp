#include<iostream>
#include<string>
#include<map>
using namespace std;

char find_first( const char* s1, const char* s2, bool capital, bool second, int& i){
    i = 0;
    while(s1[i] != 0 && s2[i] != 0){
        char t = s1[i];
        if(s1[i] == s2[i] ){
            if(second ){
                second = false;
                continue;
            }
            if(capital){
                if( s1[i] >= 'A' && s1[i] <= 'Z') return s1[i];
            }else if((t>='a' && t<='z') || (t>='0' && t<= '9') || (t>='A' && t<= 'Z'))
            {
                return s1[i];
            }
            
        }
        i++;
    }
    return 0;
}


map<char, string> day= {
    {'A',"MON" },
    {'B',"TUE"},
    {'C',"WED"},
    {'D',"THU"},
    {'E',"FRI"},
    {'F',"STA"},
    {'E',"SUN"}
    
};

int get_hour(int a){
    if(a >= 0 && a <= 9){
        return a;
    }else{
        return a-'A' + 11;
    }
}



int main(void){
    string s1;
    string s2;
    string s3;
    string s4;

    cin>>s1;
    cin >> s2;
    cin >> s3;
    cin >> s4;

    int i = 0;
    char d = find_first(s1.c_str(), s2.c_str(), true, false, i);
    cout<<day[d]<<" ";
    int h = find_first(s1.c_str(), s2.c_str(), true, true, i);
    h = get_hour(h);
    find_first(s3.c_str(), s4.c_str(), false, false, i);
    printf("%02d:%02d",h,i);




    return 0;
}