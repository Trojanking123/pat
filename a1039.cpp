#include <iostream>
#include<vector>
#include<map>
#include<queue>
#include<string>
#include<algorithm>

using namespace std;


const int kMax = 26 * 26 * 26 * 26;
vector<int> stu_course[kMax];

int to_int(char* s){
    const char * p = s;
    int ret = 0;
    ret += *(p+3)-'0';
    ret += (*(p+2)-'A')*26;
    ret += (*(p+1)-'A')*26*26;
    ret += (*(p+0)-'A')*26*26*26;
    return ret;
}
         
int main(void){
    
    int stu_num;
    int course_num;
    cin >> stu_num >> course_num;
    for(int i= 0; i < course_num; i++){
        int index;
        int enroll;
        cin >> index >> enroll;
        for(int j = 0; j < enroll; j++){
            char tt[5];
            cin >> tt;
            int name = to_int(tt);
            stu_course[name].push_back(index);
        }
        
    }
    for(int i = 0 ; i < stu_num; i++){
        char tt[5];
        cin >> tt;
        int name = to_int(tt);
        int len = stu_course[name].size();
        printf("%s %d", tt, len);
        auto& temp = stu_course[name];
        
        sort(temp.begin(), temp.end());
        for(int j = 0;  j < len ; j++){
            printf(" %d", temp[j]);
        }
        printf("\n");
            
    }
        
    return 0;        
}
    
    
    
    

