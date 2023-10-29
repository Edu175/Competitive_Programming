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
const ll MAXN=3e5+5;

ll x,y,z,n;
ll a[MAXN];
ll dp[MAXN][3];

ll f(ll i, ll c){
	ll &res=dp[i][c];
	if(res!=-1)return res;
	if(i==n)return res=0;
	if(a[i]==c)return res=min(x+f(i+1,c),z+y+f(i+1,c^1));
	else return res=min(y+f(i+1,c),z+x+f(i+1,c^1));
}

int main(){FIN;
	cin>>x>>y>>z;
	string s; cin>>s;
	n=SZ(s);
	fore(i,0,n)a[i]=(s[i]=='A');
	mset(dp,-1);
	cout<<f(0,0)<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
