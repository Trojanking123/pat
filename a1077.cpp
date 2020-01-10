#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
int main(void){
    string ans;
    string str;
    int n;
    cin >> n;
    getchar();
    getline(cin, ans);
    n--;
    int len1 ;
    int len2;

    while(n > 0){
        getline(cin, str);
        len1 = ans.size();
        len2 = str.size();
        //cout<<len1<<"|"<<len2<<endl;
        int i = 0;
        for(i = 0; i < min(len1, len2); i++){
            if(ans[len1-i - 1] != str[len2 - i - 1]) break;
        }
        //cout<<i<<endl;
        ans = ans.substr(len1-i);
        cout<<ans<<endl;
        n--;
    }
    if(ans != "") cout<<ans;
    else cout<<"nai";

    return 0;
}