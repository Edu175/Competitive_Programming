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
const ll MAXN=1e6+5,MOD=1e9+7,MAXL=5005;

ll tr[MAXN][30],qidx=0,d[MAXN],p[MAXN];
ll add(ll x, char c){
	ll &res=tr[x][c-'a'];
	if(res==-1)res=++qidx;
	d[res]=d[x]+1;
	return res;
}
ll n;
vector<char>a(MAXL);
ll dp[MAXL];
ll f(ll i){
	if(i>n)return 0;
	ll &res=dp[i];
	if(res!=-1)return res;
	if(i==n)return res=1;
	res=0;
	ll x=0;
	fore(j,i,n){
		x=tr[x][a[j]-'a'];
		if(x==-1)break;
		if(p[x])res=(res+p[x]*f(i+d[x]))%MOD;
	}
	return res;
}
int main(){FIN;
	mset(tr,-1);
	mset(dp,-1);
	mset(p,0);
	string s; cin>>s;
	n=SZ(s);
	fore(i,0,n)a[i]=s[i];
	ll k; cin>>k;
	string b[k];
	fore(i,0,k)cin>>b[i];
	d[0]=0;
	fore(i,0,k){
		ll x=0;
		for(auto j:b[i])x=add(x,j);
		p[x]++;
	}
	cout<<f(0)<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home

