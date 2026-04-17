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
const ll MAXN=27;

ll dp[MAXN];
vector<pair<ll,ll>>a(MAXN);
ll n, k;
ll f(ll mk){
	ll &res=dp[mk];
	if(res!=-1)return res;
	
}

int main(){FIN;
	ll n,k; cin>>n>>k;
	vector<pair<ll,ll>>a(k);
	fore(i,0,k)cin>>a[i].fst>>a[i].snd,a[i].fst--,a[i].snd--;
	mset(dp,-1);
	
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
