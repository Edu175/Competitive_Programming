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
const ll MAXN=505,INF=1e9+5;

ll n,l,k;
ll a[MAXN],v[MAXN];
ll dp[MAXN][MAXN][MAXN];

ll f(ll i, ll s, ll c){
	ll &res=dp[i][s][c];
	if(res>=0)return res;
	if(c>k)return res=INF;
	if(i==n)return res=0;
	ll d=a[i+1]-a[i];
	/*return */res=min(v[i]*d+f(i+1,i,c),v[s]*d+f(i+1,s,c+1));
	cout<<i<<" "<<s<<" "<<c<<": "<<v[i]*d+f(i+1,i,c)<<" "<<v[s]*d+f(i+1,s,c+1)<<" "<<res<<"\n";
	return res;
}
int main(){FIN;
	mset(dp,-1);
	cin>>n>>l>>k;
	fore(i,0,n)cin>>a[i];
	a[n]=l;
	fore(i,0,n)cin>>v[i];
	cout<<f(0,0,0)<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
