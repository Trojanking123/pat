    #include<iostream>
    #include<vector>
    #include<cmath>
    #include<algorithm>
    #include<functional>

    using namespace std;

    vector<int> record, temp;
    int n, maxK, p;
    const int kMAX = 401;
    bool cmp(vector<int>& a, vector<int>& b){
        int suma = 0, sumb = 0;
        for(auto it = a.begin(); it != a.end(); it++){
            suma += *it;
        }
        for(auto it = b.begin(); it != b.end(); it++){
            sumb += *it;
        }
        if(suma != sumb) return suma < sumb;
        else{
            auto ita = a.begin();
            auto itb = b.begin();
            while(*ita  == *itb){
                ita++;
                itb++;
            }
            return *ita < *itb;
        }
    }

    void DFS(int index, int k, int res){
        if(k == maxK ){
            if(res == n)
            {
                if(cmp(record, temp) ){
                    record = temp;
                    /*
                    cout<<"record: ";
                    for(auto it = record.begin(); it != record.end(); it++){
                        printf(" %02d", *it);
                    }
                    cout<<"\n";
                    */
                }
            }
            return;
        }
        if(res > n || index >= kMAX) return;
        
        temp.push_back(index);

        DFS(index, k+1, res+pow(index, p));
        DFS(index+1, k+1, res + pow(index, p));
        
        temp.pop_back();
        DFS(index+1, k, res);
    }


    int main(void){
        cin >> n >> maxK >> p;
        DFS(1,0,0);
        sort(record.begin(), record.end(), greater<int>());
        if(record.size() == 0){
            printf("Impossible\n");
            return 0;
        }
        printf("%d = ", n);
        int i = 0;
        for(auto it = record.begin(); it != record.end(); it++){
            if(i == 0) printf("%d^%d", *it, p);
            else printf(" + %d^%d", *it, p);
            i++;
            
        }
        
    }
