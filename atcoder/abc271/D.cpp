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
const ll MAXN=105;

ll n;
ll a[MAXN],b[MAXN];
ll dp[MAXN][10005];

ll f(ll i,ll s){
	ll &res=dp[i][s];
	if(res>=0)return res;
	//cout<<i<<" "<<s<<"\n";
	if(n==i)return res=s==0;
	return res=max(f(i+1,s-a[i]),f(i+1,s-b[i]));
}
vector<ll> res;
void build(ll i,ll s){
	//cout<<i<<" "<<s<<"\n";
	if(i==n)return;
	//cout<<i+1<<" "<<s-a[i]<<"="<<dp[i+1][s-a[i]]<<"\n";
	//cout<<i+1<<" "<<s-b[i]<<"="<<dp[i+1][s-a[i]]<<"\n";
	if(dp[i+1][s-a[i]]>=dp[i+1][s-b[i]])res.pb(0),build(i+1,s-a[i]);
	else res.pb(1),build(i+1,s-b[i]);
}

int main(){FIN;
	ll s;cin>>n>>s;
	mset(dp,-1);
	fore(i,0,n)cin>>a[i]>>b[i];
	if(f(0,s)){
		//cout<<"\n";
		cout<<"Yes\n";
		build(0,s);
		//cout<<"\n\n";
		//imp(res);
		fore(i,0,n){
			if(res[i])cout<<'T';
			else cout<<'H';
		}
		cout<<"\n";
	}
	else cout<<"No\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
