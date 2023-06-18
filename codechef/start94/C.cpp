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
typedef pair<ll,ll> ii;
const ll MAXN=1e5+5,MOD=1e9+7;

string a; ll n;
ll dp[MAXN][5];
string c="404";

ll f(ll i, ll p){
	ll &res=dp[i][p];
	if(res!=-1)return res;
	if(i==n){
		if(p==3)return res=1;
		return res=0;
	}
	res=f(i+1,p);
	if(a[i]=='*')res=(res*2)%MOD;
	if(p!=3&&(a[i]=='*'||a[i]==c[p]))res=(res+f(i+1,p+1))%MOD;
	//cout<<i<<" "<<p<<": "<<res<<"\n";
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n;
		fore(i,0,n+3)fore(j,0,5)dp[i][j]=-1;
		a.clear();
		cin>>a;
		cout<<f(0,0)<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
