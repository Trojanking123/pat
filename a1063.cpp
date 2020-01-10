#include<iostream>
#include<algorithm>
#include<set>

using namespace std;

int get_intersection(set<int>& a, set<int>& b){
    int total = 0;
 

    for(auto itera = a.begin(); itera != a.end(); itera++){
        if(b.find(*itera) != b.cend() ) total++;
    }

    return total;
}

const int SIZE = 50;

int main(void){
    set<int> array[SIZE];
    int m;
    int input;
    int queries;
    cin >> m;
    for(int i = 0; i < m; i++){
        int temp;
        cin >> temp;
        for(int j = 0; j < temp; j++){
            cin >> input;
            array[i].insert(input);
        }
    }
 
    cin >> queries;

    int unique;

    for(int i = 0; i < queries; i++){
        int a,b;
        cin >>a >>b;
        a = a- 1;
        b--;
        unique = get_intersection(array[a], array[b]);
        double rate =    (unique * 1.0) / (array[a].size() + array[b].size() - unique);
        //printf("uni:%d | total:%d\n", unique, total);
        printf("%.1lf%%\n", rate*100);
    }
    return 0;
}