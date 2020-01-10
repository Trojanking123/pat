#include<iostream>
#include<string>
#include<cstring>

using namespace std;



bool check(const char* str){
	int i, diancount=0, len=strlen(str);
	for(i=0;i<len;i++){
		if(str[i]=='-')continue;
		if(str[i]=='.'){
			diancount++;
			if(diancount>1||i+3<len)return false;
			continue;
		}
		if(str[i]>'9'||str[i]<'0')return false;
	}
	return true;
}

bool isLegal(string str){

    return check(str.c_str());
}

double to_double(string str){
    double ret;
    sscanf(str.c_str(), "%lf", &ret);
    return ret;

}

int main(void){
    int n;
    int legal = 0;
    double total= 0;
    string str;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> str;
        if( !isLegal(str) ) {
            printf("ERROR: %s is not a legal number\n", str.c_str());
            continue;
        }
        double ret = to_double(str);
        if(ret < -1000 || ret > 1000) {
            printf("ERROR: %s is not a legal number\n", str.c_str());
            continue;
        }
        legal++;
        total += ret;
        //cout<<ret<<endl;
    }
    if(legal > 0){
        if(legal == 1){
            printf("The average of 1 number is %.2lf\n", total/legal);
        }else{
            printf("The average of %d numbers is %.2lf\n", legal, total/legal);
        }
        
    }else{
        printf("The average of 0 numbers is Undefined\n");
    }
    return 0;
}