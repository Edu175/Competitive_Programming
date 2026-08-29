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

ll QUERIES=0;

ll ask(ll l, ll r, ll d, ll u){
	if(l>=r||d>=u||(r-l==1&&u-d==1))return 0;
	assert(++QUERIES<=1600);
	cout<<"? "<<l<<" "<<r<<" "<<d<<" "<<u<<endl;
	ll ret; cin>>ret;
	return ret;
}

ll asksw(ll l, ll r, ll d, ll u, ll sw){
	if(sw)swap(l,d),swap(r,u);
	return ask(l,r,d,u);
}

ll do_bin(ll l, ll r, ll d, ll u, ll sw, ll cur){ // returns coord of cut
	if(sw)swap(l,d),swap(r,u);
	ll h=u-d;
	ll w=r-l;
	assert(w>=2);
	ll lo=l,hi=r-1;
	while(hi-lo>1){
		ll mid=(lo+hi)/2;
		if(asksw(l,mid+1,d,u,sw)==cur)hi=mid;
		else lo=mid;
	}
	ll ret=hi;
	if(cur>h)ret++;
	else if(h>1&&ret==l+cur-1&&ret+1<r){
		assert(cur==h);
		ll ver=0;
		if(h==2){
			ver=asksw(ret-1,ret+1,d,d+1,sw)+
				asksw(ret-1,ret+1,d+1,u,sw)==h;
		}
		else {
			ver=asksw(ret-1,ret+1,d,u,sw)==cur;
		}
		if(!ver)ret++;
	}
	return ret;
}

vector<tuple<char,ll,ll,ll>> ret;

void f(ll l, ll r, ll d, ll u){
	ll cur=ask(l,r,d,u);
	if(!cur)return;
	ll isv=0;
	ll w=r-l,h=u-d;
	ll c=-1;
	if(w!=h){
		if(cur==max(w,h))isv=h>w; // corte a lo largo (lado largo)
		else if(cur==min(w,h))isv=!(h>w);
		else {
			// el corte secundario predomina
			ll sw=0;
			if(!(w>h))sw=1,swap(w,h),swap(l,d),swap(r,u);
			// ahora esta acostado
			assert(cur<w);
			isv=!sw;
			if(asksw(r-cur,r,d,u,sw)==cur)c=r-cur;
			
			if(sw)swap(w,h),swap(l,d),swap(r,u);
		}
		
	}
	else if(w>2){
		isv|=ask(l,r-1,d,u)==h;
		if(!isv)isv|=ask(l+1,r,d,u)==h;
	}
	else {
		assert(w==2&&h==2);
		isv=(ask(l,r,d,d+1)&&ask(l,r,d+1,u));
	}
	if(c==-1)c=do_bin(l,r,d,u,!isv,cur);
	if(isv){
		ret.pb({'v',d,u,c});
		f(l,c,d,u);
		f(c,r,d,u);
	}
	else {
		ret.pb({'h',l,r,c});
		f(l,r,d,c);
		f(l,r,c,u);
	}
}

int main(){
	// FIN;
	ll n,m,k; cin>>n>>m>>k;
	f(0,n,0,m);
	cout<<"! "<<SZ(ret)<<endl;
	assert(SZ(ret)==k-1);
	for(auto [t,a,b,c]:ret)cout<<t<<" "<<a<<" "<<b<<" "<<c<<endl;
	return 0;
}
