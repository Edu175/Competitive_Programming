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
random_device rd;
mt19937 rng;
ll n;
vv per;
ll ask(vv s, ll x){
	cout<<"? "<<x+1<<" "<<SZ(s)<<" ";
	for(auto i:s)cout<<per[i]+1<<" ";
	cout<<endl;
	ll ret; cin>>ret;
	if(ret==-1){
		exit(0);
	}
	return ret;
}

ll f(ll l, ll r, vv a, ll first=0){
	if(!SZ(a))return 0;
	if(r-l==1){
		assert(SZ(a)==1);
		return a[0];
	}
	ll m=(l+r)/2;
	vv sL,sR;
	fore(i,l,r)(i<m?sL:sR).pb(i);
	vv L,R;
	ll both=0;
	for(auto x:a){
		ll isl=ask(sL,x);
		ll isr=!isl?1:ask(sR,x);
		if(isl&&isr)both++;
		else (isl?L:R).pb(x);
	}
	if(first){
		if((SZ(sL)-both)&1)return f(l,m,L);
		assert((SZ(sR)-both)&1);
		return f(m,r,R);
	}
	return f(l,m,L)+f(m,r,R);
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n;
		per=vv(2*n-1); iota(ALL(per),0);
		shuffle(ALL(per),rng);
		vv all(n); iota(ALL(all),0);
		ll res=f(0,2*n-1,all,1);
		cout<<"! "<<res+1<<endl;
	}
	return 0;
}
