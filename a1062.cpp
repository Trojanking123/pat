#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct Student{
    int id;
    int virtue;
    int talen;
    int tag;
    Student():tag(0){};
};

vector<Student> stu;


bool cmp(Student& a, Student& b){
    if(a.tag != b.tag) return a.tag < b.tag;
    if(a.talen+a.virtue != b.talen+b.virtue) return a.talen+a.virtue > b.talen+b.virtue;
    if(a.virtue != b.virtue) return a.virtue > b.virtue;
    return a.id < b.id;
}

int main(void){
    int n, l, h;
    cin >> n >> l >> h;

    for(int i = 0; i < n; i++){
        Student temp;
        scanf("%d %d %d", &temp.id, &temp.virtue, &temp.talen);
        if(temp.virtue >= l && temp.talen >= l) {
            if(temp.talen >= h && temp.virtue >= h){
                temp.tag =1;
            }
            else if(temp.talen < h && temp.virtue >= h ) temp.tag = 3;
            else if(temp.talen < h && temp.virtue < h && temp.talen <= temp.virtue) temp.tag = 4;
            else if(temp.virtue >= temp.talen) temp.tag = 5;
            else temp.tag = 6;
            if(temp.tag) stu.push_back(temp);
        }
    }    
    //cout<<"@@@@@@@@@@@@@@@@@@@\n";
    printf("%d\n", stu.size());

    sort(stu.begin(), stu.end(), cmp);
    for(int i = 0; i < stu.size(); i++){
        printf("%08d %d %d\n", stu[i].id, stu[i].virtue, stu[i].talen);
    }
    return 0;
}