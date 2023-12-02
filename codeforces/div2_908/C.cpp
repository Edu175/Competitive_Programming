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

const ll K=19;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,c; cin>>n>>c;
		vector<ll>a(n);
		fore(i,0,n)cin>>a[i];//,a[i]--;
		vector<vector<ll>> to(K,vector<ll>(n));
		fore(i,0,n){
			if(a[i]>n)to[0][i]=-1;
			else {
				to[0][i]=(i-a[i]+n)%n;
			}
		}
		fore(k,1,K)fore(i,0,n){
			if(to[k-1][i]==-1)to[k][i]=-1;
			else to[k][i]=to[k-1][to[k-1][i]];
		}
		ll x=n-1;
		for(ll k=K-1;k>=0;k--)if(c>=(1ll<<k)){
			if(x!=-1)x=to[k][x];
			c-=1ll<<k;
		}
		if(x==-1)cout<<"No\n";
		else cout<<"Yes\n";
	}
	return 0;
}
