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
const ll MAXN=105;

ll dp[MAXN][MAXN][MAXN];
ll a[MAXN];
ll n,x;
vector<ll>pos[MAXN];

ll f(ll l, ll r, ll k, ll b){
	ll &res=dp[l][r][k][2];
	if(res!=-1)return res;
	if(l>=r)return res=0;
	auto ps=lower_bound(ALL(pos[k]),l);
	auto pe=lower_bound(ALL(pos[k]),r);
	if(ps==pe)return res=1;
	ll s=*ps,e=*prev(pe);
	res=min(f(l,s,k)+f(s+1,r,k),f(l,e,k)+f(e+1,r,k));
	res=min({res,f(l+1,r,a[l])+1,f(l,r-1,a[r-1])+1});
	cout<<"["<<l<<","<<r<<") "<<k<<": "<<res<<"\n";
	//fore(i,0,x)if(i!=k)res=min(res,f(s,e+1,i)+1);
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n>>x;
		fore(i,0,n)cin>>a[i],a[i]--;
		fore(i,0,n+3)fore(j,0,n+3)fore(k,0,n+3)fore(l,0,2)dp[i][j][k][l]=-1;
		fore(i,0,x)pos[i].clear();
		fore(i,0,n)pos[a[i]].pb(i);
		ll res=n+5;
		fore(i,0,x)res=min(res,f(0,n,i,1));
		cout<<res<<"\n";
	}
	return 0;
}
