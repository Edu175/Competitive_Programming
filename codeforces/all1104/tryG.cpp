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
const ll MAXV=1e6+1,B=1 + 1000;

int main(){FIN;
	vv cr(MAXV,-1); // biggest prime divisor
	vv pots;
	fore(i,2,MAXV)if(cr[i]==-1){
		if(i<B){
			ll pot=1; while(pot*i<B)pot*=i;
			pots.pb(pot);
		}
		cr[i]=i;
		for(ll j=i*i;j<MAXV;j+=i)cr[j]=i;
	}
	vv valid(MAXV,1); valid[0]=0;
	fore(i,1,MAXV){
		map<ll,ll>mp;
		ll n=i;
		while(n>1){
			ll p=cr[n];
			mp[p]++;
			n/=p;
		}
		for(auto [p,e]:mp){
			ll pot=1; fore(_,0,e)pot*=p;
			valid[i]&=pot<B;
		}
	}
	cerr<<"done valid\n";
	ll mx=0;
	fore(i,2,MAXV){
		fore(_d,0,i+1){
			ll d=_d;
			ll good=(i-d>=1&&valid[i-d])||(i+d<MAXV&&valid[i+d]);
			if(good){mx=max(mx,d);break;}
		}
	}
	vv le(MAXV,-1),ri(MAXV,1e10);
	fore(i,1,MAXV){
		le[i]=le[i-1];
		if(valid[i])le[i]=i;
	}
	for(ll i=MAXV-1;i>=0;i--){
		if(i+1<MAXV)ri[i]=ri[i+1];
		if(valid[i])ri[i]=i;
		assert(abs(i-le[i])<=mx||abs(i-ri[i])<=mx);
	}
	ll ans=-1,L=-1,R=-1;
	fore(z,1,MAXV){
		fore(l,-z,1){
			ll good=1;
			ll r=l+z;
			// cerr<<"try "<<l<<","<<r<<"\n";
			fore(i,0,MAXV){
				ll now=le[i]>=i+l||ri[i]<i+r;
				if(!now){good=0;break;}
			}
			if(good){ans=z,L=l,R=r;break;}
		}
		if(ans!=-1)break;
	}
	cerr<<"hay "<<count(ALL(valid),1)<<" numeros validos\n";
	cerr<<"z: "<<ans<<"\n";
	cerr<<"l r : "<<L<<" "<<R<<"\n";
	set<ll> st(ALL(pots));
	vv nums;
	while(SZ(st)){
		ll x=1;
		while(1){
			auto it=st.lower_bound(MAXV/x+1);
			if(it==st.begin())break;
			x*=*(--it);
			st.erase(it);
		}
		assert(x>1);
		nums.pb(x);
	}
	cerr<<"sz: "<<SZ(nums)<<"\n";
	show(nums)
	cerr<<"mx: "<<mx<<"\n";
	return 0;
	ll t; cin>>t;
	while(t--){
		
	}
	return 0;
}
