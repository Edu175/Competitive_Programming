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
const ll MAXN=1e5+5,INF=1e11;

ll dp[MAXN][5];
ll n,q;
ll a[MAXN];
ll f(ll i, ll c){
	ll &res=dp[i][c];
	if(res!=-1)return res;
	if(i==n){
		if(c)return res=INF;
		else return res=0;
	}
	ll go0=a[i]-a[i]*q/100+f(i+1,c);
	ll go1=-1;
	if(c)go1=a[i]+f(i+1,c-1);
	else go1=f(i+1,2);
	res=min(go0,go1);
	//cout<<i<<" "<<c<<": "<<go0<<" "<<go1<<": "<<res<<"\n";
	return res;
}
int main(){FIN;
	cin>>n>>q;
	fore(i,0,n)cin>>a[i];
	sort(a,a+n);
	mset(dp,-1);
	cout<<f(0,0)<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
