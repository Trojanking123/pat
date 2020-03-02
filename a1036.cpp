#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

struct Student{
    string name;
    string id;
    char gender;
    int grade;
};

bool cmpFH(Student& a, Student& b){
    if(a.gender != b.gender) return a.gender < b.gender;
    else return a.grade > b.grade;
}



int main(void){
    int n;
    vector<Student> all;

    cin >> n;
    for(int i = 0; i < n; i++){
        Student stu;
        cin >> stu.name >> stu.gender >> stu.id >> stu.grade;
        all.push_back(stu);
    }
    sort(all.begin(), all.end(), cmpFH);

    Student fh = all.front();
    Student ml = all.back();

    bool flag = false;
    if(fh.gender != 'F'){
        printf("Absent\n");
        flag = true;
    }else{
        printf("%s %s\n", fh.name.data(), fh.id.data());
    }

    if(ml.gender != 'M'){
        printf("Absent\n");
        flag = true;
    }else{
        printf("%s %s\n", ml.name.data(), ml.id.data());
    }
    if(flag){
        printf("NA\n");
    }else{
        printf("%d\n", fh.grade-ml.grade);
    }

    return 0;
}