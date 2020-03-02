#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
 
using namespace std;
 
vector<string> courseMap[2510];
 
bool cmp(string , string);
 
int main() {
    int n, k;
    scanf("%d%d", &n, &k);
 
    for(int i = 0; i < n; ++i) {
        string sname;
        int cnum;
        cin >> sname;
 
        scanf("%d", &cnum);
        for(int j = 0; j < cnum; ++j) {
            int course;
            scanf("%d", &course);
            courseMap[course].push_back(sname);
        }
    }
 
    for(int i = 1; i <= k; ++i) {
        printf("%d %d\n", i, courseMap[i].size());
        sort(courseMap[i].begin(), courseMap[i].end(), cmp);
        for(vector<string>::iterator it = courseMap[i].begin(); it < courseMap[i].end(); ++it) {
            printf("%s\n", (*it).c_str());
        }
    }
 
    return 0;
}
 
bool cmp(string a, string b) {
    return a < b;
}

