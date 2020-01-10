#include<stdio.h>
#include<map>
#include<string>
using namespace std;
map<int, int>mp;
int main(){
int i, j, m, n;
int temp, ans;
scanf("%d%d",&m,&n);
int sum=m*n/2;
for(i=0;i<n;i++){
	for(j=0;j<m;j++){
		scanf("%d",&temp);
		mp[temp]++;
        if(mp[temp]>sum){ans=temp;}
	}
}
printf("%d\n",ans);
return 0;
}
