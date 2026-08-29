#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(a){for(auto x:a)cout<<a<<" ";cout<<"\n"}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef __int128 xl;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

ll k;
vv as,bs;
ll c;
xl t;
ll could=0;
void f(ll i, ll s, xl u, ll r){
	if(i==SZ(as)){
		if(u>=(k-1)*c)r=u%c;
		if(t==0)could|=s==0;
		else could|=c-r>=s;
		return;
	}
	fore(v,0,k+1){
		xl ui=u+v;
		if(ui>t)continue;
		xl a=as[i],b=bs[i];
		a-=b*v;
		f(i+1,s+max(xl(0),a),ui,r+(v==k));
		if(could)return;
	}
}

bool can(ll _k){
	k=_k;
	t=xl(c)*k;
	could=0;
	f(0,0,0,0);
	return could;
}

int main(){
	JET
	ll n; cin>>n>>c;
	as=bs=vv(n);
	fore(i,0,n)cin>>as[i]>>bs[i];
	ll r=2;
	fore(i,0,n)r+=(as[i]+bs[i]-1)/bs[i];
	ll l=0;
	while(r-l>1){
		ll m=(l+r)/2;
		if(can(m))r=m;
		else l=m;
	}
	ll res=r;
	cout<<res-1<<"\n";
	return 0;
}