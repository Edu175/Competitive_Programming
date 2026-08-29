#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		ll mx=n*n/2;
		ll _k=k;
		if(k%2||k<2*(n-1)||k>mx){
			cout<<"-1\n";
			continue;
		}
		assert(mx%2==0);
		k/=2,mx/=2;
		k-=n-1; mx-=n-1;
		// cerr<<"k mx "<<k<<" "<<mx<<"\n";
		vv mv(n);
		ll u=n-2-1;
		fore(i,0,n-1)if(i&1){
			mv[i]=u; u-=2;
		}
		// show(mv)
		// cerr<<"n "<<n<<"\n";
		// cout<<endl;
		assert(accumulate(ALL(mv),0ll)==mx);
		vv fre;
		vv ans(n,-1);
		ll c=0;
		fore(i,0,n){
			ll q=min(k,mv[i]);
			k-=q;
			if(!q)fre.pb(i);
			else ans[i+q-c]=i,c++;
			// cerr<<i<<": "<<
		}
		ll po=0;
		fore(i,0,n)if(ans[i]==-1)ans[i]=fre[po++];
		fore(i,0,SZ(ans)-1)cout<<ans[i]+1<<" "<<ans[i+1]+1<<"\n";
		
		// for(auto i:ans)cerr<<i+1<<" ";;cerr<<"\n";
		
		auto sted=ans; sort(ALL(sted));
		vv id(n); iota(ALL(id),0);
		assert(sted==id);
		vv pos(n); fore(i,0,n)pos[ans[i]]=i;
		ll sum=0;
		fore(i,0,n)sum+=abs(pos[i]-pos[(i+1)%n]);
		assert(sum==_k);
	}
	return 0;
}
