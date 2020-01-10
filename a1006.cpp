#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

struct Time{
    int hour;
    int mimute;
    int second;
};
struct Record{
    string id;
    Time in;
    Time out;
};

bool cmp(Time& a, Time& b){
    if(a.hour != b.hour){
        return a.hour < b.hour;
    }else if(a.mimute != b.mimute){
        return a.mimute < b.mimute;
    }else{
        return a.second < b.second;
    }
}

vector<Record> records;

bool First(Record& a, Record& b){
    return cmp(a.in, b.in);
}

bool Latter(Record& a, Record& b){
    return !cmp(a.out, b.out);
}

int main(void){
    int m;
    cin >> m;
    for(int i = 0; i < m; i++){
        Record r;
        cin >> r.id;
        scanf(" %d:%d:%d %d:%d:%d", &r.in.hour, & r.in.mimute, &r.in.second, &r.out.hour, &r.out.mimute, &r.out.second);
        records.push_back(r);
    }
    sort(records.begin(), records.end(), First);
    cout<<records[0].id;
    sort(records.begin(), records.end(), Latter);
    cout<<" "<<records[0].id<<endl;
    return 0;
}