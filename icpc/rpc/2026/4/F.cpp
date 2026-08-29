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
typedef double ld;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
ll n,k;
vector<vv> pos;
const ld INF=1e18;
bool can(ld h){
	// cerr<<"\n\ncan "<<h<<":\n";
	fore(val,0,n)if(SZ(pos[val])){
		// cerr<<"val "<<val<<"\n";
		auto &v=pos[val];
		ll po=0;
		ld mx=-INF;
		fore(idx,0,SZ(v)){
			ll r=v[idx];
			while(po<SZ(v)&&r-v[po]+1>=k){
				ld otr=-(po-1)+(v[po]-1)*h;
				mx=max(mx,otr);
				po++;
			}
			if(1){
				ld otr=-(po-1)+(r-k)*h;
				mx=max(mx,otr);
			}
			ld cur=idx-h*r;
			// cerr<<"cand "<<r<<": "<<cur<<" "<<mx<<": "<<cur+mx<<"\n";
			if(cur+mx>=0){
				// cerr<<"se pudo\n";
				return 1;
			}
		}
	}
	return 0;
}

int main(){FIN;
	cin>>n>>k;
	vv a(n);
	vv vals;
	fore(i,0,n)cin>>a[i],vals.pb(a[i]);
	sort(ALL(vals)); vals.resize(unique(ALL(vals))-vals.begin());
	fore(i,0,n){
		a[i]=lower_bound(ALL(vals),a[i])-vals.begin();
	}
	pos.resize(n);
	fore(i,0,n)pos[a[i]].pb(i);
	ld l=1e-7,r=2;
	fore(_,0,64){
		ld m=2*l<r?sqrt(l*r):(l+r)/2;
		if(can(m))l=m;
		else r=m;
	}
	cout<<fixed<<setprecision(15);
	cout<<l<<"\n";
	return 0;
}
