#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=1e4+5,K=8,INF=MAXN+10;

ll dp[MAXN][1<<K];
ll c[MAXN];
vector<ii> g[MAXN];
ll f(ll x, ll i, ll mk){
	ll pinga=-1; auto &res=i==-1?pinga:dp[i][mk];
	if(res!=-1)return res;
	mk&=~(1<<c[x]);
	if(!mk)return res=0;
	res=INF;
	vector<vv>mem()
	// na que paja, aparte seguro da tlw
	for(int su=0;su=su-mk&mk;){
	}
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		
	}
	return 0;
}