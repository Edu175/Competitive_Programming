#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define pb push_back
#define ALL(x) x.begin(),x.end();
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXN=5005;

vv g[MAXN];
ll c[MAXN];
void dfs(ll x, ll fa, ll d){
	c[d]++;
	for(auto y:g[x])if(y!=fa)dfs(y,x,d+1);
}

ll get(vv a){
	if(SZ(a)<3)return 0;
	ll sum=0;
	for(auto i:a)sum+=i;
	ll res=sum*sum*sum;
	for(auto i:a)res-=(sum-i)*i*i*3+i*i*i;
	// cout<<"get "; for(auto i:a)cout<<i<<" ";
	// cout<<": "<<sum<<": "<<res<<endl;
	assert(res%6==0);
	res/=6;
	return res;
}

int main(){
	JET
	ll n; cin>>n;
	fore(i,0,n-1){
		ll u,v; cin>>u>>v; u--,v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	ll res=0;
	fore(rt,0,n){
		vector<vv>ds(n);
		for(auto y:g[rt]){
			dfs(y,rt,0);
			fore(k,0,n){
				if(!c[k])break;
				ds[k].pb(c[k]);
			}
			fore(k,0,n){
				if(!c[k])break;
				c[k]=0;
			}
		}
		ll resi=0;
		for(auto a:ds)resi+=get(a);
		res+=resi;
		// cout<<rt<<": "; fore(i,0,n)cout<<c[i]<<" ";
		// cout<<": "<<resi<<"\n";
	}
	cout<<res<<"\n";
	return 0;
}

/*

7
1 2
5 7
2 5
2 3
5 6
4 5


get 1 1 1 : 3: 12
get 1 1 1 1 : 4: 32


*/