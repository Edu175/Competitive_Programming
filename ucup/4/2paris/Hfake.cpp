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

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,d; cin>>n>>d;
		vv a(n);
		ll sum=0;
		fore(i,0,n)cin>>a[i],sum+=a[i];
		ll k=sum/n;
		fore(i,0,n)a[i]-=k;
		queue<ll> pos,neg;
		fore(i,0,n){
			if(a[i]>0)pos.push(i);
			if(a[i]<0)neg.push(i);
		}
		ll mx=0;
		fore(i,0,n)if(a[i]){
			ll sig=a[i]>0;
			auto &my=(sig?pos:neg);
			auto &otr=(sig?neg:pos);
			assert(my.front()==i);
			while(a[i]){
				auto j=otr.front();
				ll q=min(abs(a[i]),abs(a[j]));
				if(sig)a[i]-=q,a[j]+=q;
				else a[i]+=q,a[j]-=q;
				if(!a[j])otr.pop();
				assert(j>i);
				mx=max(mx,j-i);
			}
			my.pop();
		}
		ll res=(mx+d-1)/d;
		cout<<res<<"\n";
	}
	return 0;
}
