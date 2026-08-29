#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define pb push_back
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(v){for(auto x:v)cout<<x<<" "; cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
ll QUERIES=0;
ll n;
ll ask(vv a){
	assert(SZ(a)==n);
	assert(++QUERIES<=4*n);
	for(auto i:a)cout<<i<<" ";;cout<<endl;
	ll ret; cin>>ret;
	if(ret==-1)exit(0);
	if(!ret)exit(0);
	return ret;
}

int main(){
    // JET
    cin>>n;
	ll L=1,R=2*n;
	// if(n==1){
	// 	ask({L});
	// 	ask({R});
	// 	assert(0);
	// }
	vv a(n,-1);
	auto doit=[&](vv vdef, ll def, ll fg){ // def is an upperbound
		fore(i,0,n-fg)if(a[i]==-1){
			auto b=vdef;
			b[i]=L;
			ll d=ask(b);
			if(d>def){a[i]=L+d;continue;}
			b[i]=R;
			d=ask(b);
			if(d>def)a[i]=R-d;
		}
	};
	vv vdef(n,n);
	doit(vdef,n,0);
	vdef=a;
	fore(i,0,n)if(vdef[i]==-1)vdef[i]=n;
	doit(vdef,1,1);
	if(a[n-1]!=-1){
		ask(a);
		assert(0);
	}
	a[n-1]=n;
	ask(a);
	a[n-1]=n+1;
	ask(a);
	assert(0);
	return 0;
}
