#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
auto pinchilon=[](){
	#ifdef ONLINE_JUDGE
	freopen("factorial.in","r",stdin);     freopen("factorial.out","w",stdout);
	#endif
};

const ll MAXV=1e4+10;
ll cr[MAXV];
vv ps;
void init_sieve(){
	mset(cr,-1);
	fore(i,2,MAXV)if(cr[i]==-1){
		ps.pb(i);
		for(ll j=1ll*i*i;j<MAXV;j+=i)cr[j]=i;
	}
}
vv operator+(vv a, vv b){
	assert(SZ(a)==SZ(b));
	fore(i,0,SZ(a))a[i]+=b[i];
	return a;
}
vv operator-(vv a, vv b){
	assert(SZ(a)==SZ(b));
	fore(i,0,SZ(a))a[i]-=b[i];
	return a;
}
int main(){pinchilon();
	JET
	init_sieve();
	ll z=SZ(ps);
	auto get=[&](ll n)->vv{
		vv c(z);
		fore(i,0,z){
			ll p=ps[i],pot=p;
			while(pot<=n)c[i]+=n/pot,pot*=p;
		}
		return c;
	};
	vv h(z);
	ll n1,n2; cin>>n1>>n2;
	fore(i,0,n1+n2){
		ll x; cin>>x;
		if(i<n1)h=h+get(x);
		else h=h-get(x);
	}
	ll flag=1;
	for(auto i:h)flag&=i>=0;
	if(!flag){
		cout<<"-1\n";
		return 0;
	}
	vector<ii> res;
	while(h[0]){
		ll l=2,r=MAXV*MAXV;
		while(l<=r){
			ll m=(l+r)/2;
			ll flag=1;
			auto c=get(m);
			fore(j,0,z)if(!(h[j]>=c[j])){flag=0;break;}
			if(flag)l=m+1;
			else r=m-1;
		}
		assert(r>=2);
		auto c=get(r);
		ll mn=MAXV*100;
		fore(j,0,z)if(c[j])mn=min(mn,h[j]/c[j]);
		assert(mn>0);
		res.pb({r,mn});
		fore(j,0,z)h[j]-=c[j]*mn;
	}
	cout<<SZ(res)<<"\n";
	for(auto [x,y]:res)cout<<x<<" "<<y<<"\n";
	return 0;
}