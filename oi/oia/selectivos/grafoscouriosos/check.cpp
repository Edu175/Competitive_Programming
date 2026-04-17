#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oia=b; i<oia;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(a) {for(auto messi:a)cout<<messi<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;

int main(){
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll flag; cin>>flag;
		ll possible=n%4<=1;
		if(flag!=possible){
			cout<<"FAILED\n";
			continue;
		}
		if(!flag){
			cout<<"OK not possible\n";
			continue;
		}
		vector<ll>a(n);
		fore(i,0,n)cin>>a[i];
		vector<vector<char>>g(n,vector<char>(n));
		fore(i,0,n)fore(j,0,n)cin>>g[i][j];
		auto g2=g;
		/*fore(i,0,n){
			fore(j,0,n)cout<<g2[i][j];
			cout<<"\n";
		}
		cout<<"\n";*/
		fore(i,0,n)fore(j,0,n)g2[i][j]=g[a[i]][a[j]];
		flag=1;
		fore(i,0,n)fore(j,0,n)if(i!=j&&g[i][j]-'0'!=((g2[i][j]-'0')^1))flag=0;
		/*fore(i,0,n){
			fore(j,0,n)cout<<g[i][j];
			cout<<"\n";
		}
		cout<<"\n";
		fore(i,0,n){
			fore(j,0,n)cout<<g2[i][j];
			cout<<"\n";
		}
		cout<<"\n";*/
		if(!flag)cout<<"WA not valid graph\n";
		else cout<<"OK valid\n";
	}
	return 0;
}
