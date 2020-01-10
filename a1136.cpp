#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

bool isPalindrome(string str){
    int len = str.size();
    const char* s = str.c_str();
    for(int i = 0; i < len/2; i++){
        if(s[i] != s[len-i-1]) return false;
    }
    return true;
}
string strplus(string& a, string& b){
    string ret;
    int carry = 0;
    int len = a.size();
    for(int i = 0; i < len; i++){
        int sum = (a[i]-'0' + b[i]-'0' + carry);
        ret += (sum % 10 +  '0') ;
        carry = sum/10;
    }
    if(carry) ret += '1';
    return ret;
}


int main(void){
    string input;
    cin >> input;
    string after_reverse = input;
    reverse(after_reverse.begin(), after_reverse.end());
    
    for(int i = 0; i < 10; i++){
        
        if(isPalindrome(input)){
            printf("%s is a palindromic number.\n", input.c_str());
            return 0;
        }
        printf("%s + %s = ", input.c_str(), after_reverse.c_str());
        after_reverse = strplus(input, after_reverse);
        input = after_reverse;
        reverse(input.begin(), input.end());
        printf("%s\n", input.c_str());
    }
    printf("Not found in 10 iterations.\n");

    return 0;
}