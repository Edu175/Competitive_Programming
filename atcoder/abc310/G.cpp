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
const ll MAXN=2e5+5,MOD=998244353;

ll n;
ll a[MAXN],b[MAXN];
ll K=18;
ll BL[K][1ll<<K];
ll c[MAXN],w[MAXN],d[MAXN];

void binary_lifting(){
	fore(i,0,n)BL[0][i]=b[i];
	fore(k,1,K)fore(i,0,n)BL[k][i]=BL[k-1][BL[k-1][i]];
}
int main(){FIN;
	ll m; cin>>n>>m;
	fore(i,0,n)cin>>a[i],a[i]--;
	fore(i,0,n)cin>>b[i];
	binary_lifting();
	
	return 0;
}
