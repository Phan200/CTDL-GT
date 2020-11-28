#include<bits/stdc++.h>
using namespace std;
int T,v,e,chuaxet[1111];
vector<vector<int> >a;
void DFS(int u){
	chuaxet[u]=0;
	for(int i=0;i<a[u].size();i++){
		if(chuaxet[a[u][i]]){
			DFS(a[u][i]);
		}
	}
}
int KiemTra(){
	for(int i=1;i<=v;i++){
		if(chuaxet[i]==1){
			return 1;
		}
	}
	return 0;
}
string KiemTraLienThongManh(){
	memset(chuaxet,1,sizeof(chuaxet));
	for(int i=1;i<=v;i++){
        if(chuaxet[i]){
		DFS(i);
		if(KiemTra()) return "NO";
		else memset(chuaxet,1,sizeof(chuaxet));
	}}
	return "YES";
}
int main(){
	cin>>T;
	while(T--){
		cin>>v>>e;
		a.clear();a.resize(1111);
		for(int i=1;i<=e;i++){
			int x,y;cin>>x>>y;
			a[x].push_back(y);
		}
		cout<<KiemTraLienThongManh()<<endl;
	}
	return 0 ;
}
 