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

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll>a(n),p(n);
		fore(i,0,n)cin>>a[i],a[i]--,p[a[i]]=i;
		vector<vector<ll>>res;
		while(1){
			ll fl=1;
			fore(i,0,n)if(a[i]!=i)fl=0;
			if(fl)break;
			vector<ll>op,us(n);
			fore(i,0,n){
				ll x=i;
				while(a[x]!=x&&!us[p[x]]&&!us[x]){
					ll y=a[x]; y=a[y];
					ll px=p[x];
					p[a[x]]=px,p[x]=x;
					op.pb(x),op.pb(px);
					swap(a[x],a[px]);
					us[x]=us[px]=1;
					x=y;
				}
			}
			res.pb(op);
		}
		cout<<SZ(res)<<"\n";
		for(auto v:res){
			cout<<SZ(v)<<" ";
			for(auto i:v)cout<<i+1<<" ";
			cout<<"\n";
		}
	}
	return 0;
}
