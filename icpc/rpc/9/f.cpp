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
const ll MAXN=1e4+5;

// int d[MAXN][MAXN];

int main(){FIN;
	// mset(d,-1);
	ll n,l,k; cin>>n>>l>>k;
	vector<string> nom(n);
	vector<vv> a(n,vv(l));
	fore(i,0,n){
		cin>>nom[i];
		fore(j,0,l)cin>>a[i][j];
	}
	auto dis=[&](ll i, ll j)->ll{
		// auto &res=d[i][j];
		// if(res!=-1)return res;
		ll res=0;
		fore(ind,0,l)res+=abs(a[i][ind]-a[j][ind]);
		return res;
	};
	vv val(n);
	vv vis(n);
	
	ll rt=-1;
	fore(i,1,n)if(rt==-1||dis(i,0)>dis(rt,0))rt=i;
	
	fore(i,0,n)val[i]=dis(rt,i);
	vis[rt]=1;
	vv res={rt};
	
	auto agr=[&](ll s){
		vis[s]=1; res.pb(s);
		fore(i,0,n)if(!vis[i])val[i]=min(val[i],dis(i,s));
	};
	fore(_,0,k-1){
		// cerr<<"step "<<_+2<<"\n";
		// imp(val)
		ll mx=-1;
		fore(i,0,n)if(!vis[i]){
			if(mx==-1||val[i]>val[mx])mx=i;
		}
		agr(mx);
	}
	
	for(auto i:res)cout<<nom[i]<<"\n";
	return 0;
}
