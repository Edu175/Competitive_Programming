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
	ll n; cin>>n;
	ll m=n/2,m2=n-m;
	ll sum=0;
	vv a(n);
	fore(j,0,2){
		fore(i,0,n){
			ll v; cin>>v;
			if(!j)sum+=v;
			a[i]+=v;
		}
	}
	vv ini,fin;
	fore(mk,0,1ll<<m2){
		ll s=0;
		fore(i,0,n)if(mk>>i&1)s+=a[i];
		ini.pb(s);
	}
	fore(mk,0,1ll<<m){
		ll s=0;
		fore(i,0,n)if(mk>>i&1)s+=a[i+m2];
		fin.pb(s);
	}
	sort(ALL(ini));
	sort(ALL(fin));
	// cout<<sum<<": ";
	// imp(a)
	// imp(ini)
	// imp(fin)
	ll M=1ll<<m;
	vv ans;
	vv l(M),r(M);
	auto val=[&](ll i, ll w){
		return abs(sum-(fin[i]+ini[(w?r[i]:l[i])]));
	};
	// cout<<M<<" "<<SZ(fin)<<endl;
	priority_queue<array<ll,3>>pq;
	fore(i,0,M){
		r[i]=lower_bound(ALL(ini),sum-fin[i])-ini.begin();
		l[i]=r[i]-1;
		if(l[i]>=0)pq.push({-val(i,0),i,0});
		if(r[i]<SZ(ini))pq.push({-val(i,1),i,1});
	}
	
	while(SZ(pq)&&SZ(ans)<(1ll<<20)){
		auto [v,i,w]=pq.top(); pq.pop(); v=-v;
		ans.pb(v);
		ll hago=1;
		if(w){
			r[i]++;
			hago&=r[i]<SZ(ini);
		}
		else l[i]--,hago&=l[i]>=0;
		if(hago)pq.push({-val(i,w),i,w});
	}
	imp(ans);
	return 0;
}
