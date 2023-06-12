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
const ll MAXN=3e5+5,INF=2e12*MAXN;

ll n, a[MAXN];
ll s=1e12,r=1e12+1;
ll dp[MAXN][5];
ll f(ll i, ll b){
	ll &res=dp[i][b];
	if(res!=-1)return res;
	if(i==n)return res=0;
	if(b==0){
		if(a[i]){
			res=f(i+1,1);
			if(i)res=min(res,s+f(i+1,2));
			res=min(res,r+f(i+1,0));
		}
		else{
			res=f(i+1,0);
		}
	}
	if(b==1){
		if(a[i]){
			res=min(f(i+1,2),r+f(i+1,1));
		}
		else{
			res=min(s+f(i+1,1),r+f(i+1,1));
		}
	}
	if(b==2){
		if(a[i]){
			res=f(i+1,2);
		}
		else{
			res=r+f(i+1,2);
		}
	}
	return res;
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		string s; cin>>s;
		n=SZ(s);
		fore(i,0,n+3){
			fore(j,0,5)dp[i][j]=-1;
		}
		fore(i,0,n)a[i]=s[i]-'0';
		cout<<f(0,0)<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
