#include <bits/stdc++.h> 
#define pb push_back 
#define fst first 
#define snd second 
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i) 
#define SZ(x) ((int)x.size()) 
#define ALL(x) x.begin(),x.end() 
#define mset(a,v) memset((a),(v),sizeof(a)) 
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std; typedef long long ll; 
int main(){FIN;
	ll n,m,q; cin>>n>>m>>q;
	char a[n][m];
	ll ic=0;
	map<pair<ll,ll>,ll> ord;
	fore(i,0,n){
		fore(j,0,m){
			cin>>a[i][j];
			if(a[i][j]=='*')ic++;
			ord[{i,j}]=n*j+i;
		}
	}
	ll res=0;
	fore(i,0,n){
		fore(j,0,m){
			if(a[i][j]=='*'&&ord[{i,j}]>=ic)res++;
		}
	}
	//cout<<ic<<"\n"<<res<<"\n";
	while(q--){  
		ll x,y; cin>>x>>y;
		if(a[x-1][y-1]=='*'){
			ic--;
			if(a[ic%n][ic/n]=='.')res--;
			a[x-1][y-1]='.';
			if(ord[{x-1,y-1}]<ic)res++;
		}
		else{
			if(a[ic%n][ic/n]=='.')res++;
			a[x-1][y-1]='*';
			ic++;
			if(ord[{x-1,y-1}]<ic)res--;
		}
		cout<<res<<"\n";
	}
	return 0; 
}
