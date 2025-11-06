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

ll ask(ll i, ll x){
	cout<<"? "<<i+1<<" "<<x<<endl;
	ll ret; cin>>ret;
	return ret;
}

int main(){//FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv ind(n-1); iota(ALL(ind),0);
		ll B=__lg(n)+1;
		ll res=0;
		fore(j,0,B){
			vv oc(2);
			fore(i,1,n+1)if((i&((1<<j)-1))==res)oc[i>>j&1]++;
			
			// imp(oc)
			
			vector<vv> prox(2);
			for(auto i:ind)prox[ask(i,1<<j)].pb(i);
			ll w=SZ(prox[0])==oc[0];
			res+=w<<j;
			ind=prox[w];
			// imp(ind)
		}
		assert(res);
		// if(!res)res+=1<<(B-1);
		cout<<"! "<<res<<endl;
	}
	return 0;
}
