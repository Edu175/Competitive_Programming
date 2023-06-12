#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
const ll MAXN=1e6+5;
#define op min
#define NEUT MAXN;
int n,m;
vector<vector<ll>>a;

bool can(ll x){
	ll b[n][m];
	fore(i,0,n){
		fore(j,0,m)b[i][j]=(a[i][j]>=x);
	}
	ll sp[n+1][m+1];
	fore(i,0,n+1)sp[i][0]=0;
	fore(j,0,m+1)sp[0][j]=0;
	fore(i,1,n+1){
		fore(j,1,m+1){
			sp[i][j]=sp[i][j-1]+b[i-1][j-1];
		}
	}
	fore(i,1,n+1){
		fore(j,1,m+1){
			sp[i][j]+=sp[i-1][j];
		}
	}
	ll flag=0;
	fore(i,0,n-x+1){
		fore(j,0,m-x+1){
			ll sum=sp[i+x][j+x]-sp[i][j+x]-sp[i+x][j]+sp[i][j];
			if(sum>=x*x)flag=1;
		}
	}
	return flag;
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n>>m;
		a.resize(n);
		fore(i,0,n)a[i].resize(m);
		fore(i,0,n){
			fore(j,0,m)cin>>a[i][j];
		}
		ll l=1,r=min(n,m)+5;
		while(l<=r){
			ll m=(l+r)/2;
			if(can(m))l=m+1;
			else r=m-1;
		}
		cout<<r<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
