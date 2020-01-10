

#include<iostream>
#include<map>
#include<set>
#include<string>
#include<sstream>

using namespace std;
map<string, set<int>> keywords;
map<string, set<int>> publishers;
map<string, set<int>> authors;
map<string, set<int>> titles;
map<string, set<int>> years;
map<string, set<int>> obj;

int main(void){
    //std::ios::sync_with_stdio(false);
    //ios_base::sync_with_stdio(0);
    //cin.tie(NULL);
    int n;
    cin >> n;
    getchar();
    for(int i = 0; i < n; i++){
        string  title, author, keywordss, publisher, year, kw ;
        int id;
        //getline(cin, id);
        scanf("%d", &id);
        getchar();
        getline(cin, title);
        getline(cin, author);
        getline(cin, keywordss);
        getline(cin, publisher);
        getline(cin, year);
        
        //cout<<id<<endl;
        //cout<<year<<endl;

        titles[title].insert(id);
        authors[author].insert(id);
        stringstream ss(keywordss);
        while(ss >> kw ) keywords[kw].insert(id);
        publishers[publisher].insert(id);
        years[year].insert(id);
    }
    
    int m;
    cin >> m;
    getchar();
    for(int i = 0; i < m; i++){
        char tp;
        string  query, temp, key;
        cin >> temp;
        getchar();
        getline(cin, key);
        query = temp+" "+key;

        tp = temp[0];

        //cout<<tp<<endl;
        switch (tp)
        {
        case '1':
            obj = titles;
            break;

        case '2':
            obj = authors;
            break;
        case '3':
            obj = keywords;
            break;
        case '4':
            obj = publishers;
            break;
        case '5':
            obj = years;
            break;
        
        default:
            cout<<"fuck wrong"<<endl;
            break;
        }
        printf("%s\n", query.c_str());
        //cout<<"key:"<<key<<endl;
        if(obj.find(key) != obj.end()){
            auto res = obj[key];
            
            for(auto i = res.begin(); i != res.end(); i++){
                printf("%07d\n", (*i));
            }
        }else{
            printf("Not Found\n");
        }

    }

    return 0;
}



