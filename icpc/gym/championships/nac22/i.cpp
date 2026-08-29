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

ll c;
vv as,bs;
bool can(xl k){
	ll n=SZ(as);
	vector<array<ll,3>> h(n);
	fore(i,0,n)h[i]={bs[i],as[i],0};
	sort(ALL(h)); reverse(ALL(h));
	xl t=k*c;
	for(auto &[b,a,q]:h){
		q=min({t,(xl)k,(xl)a/b});
		a-=b*q;
		t-=q;
		b=a;
	}
	sort(ALL(h)); reverse(ALL(h));
	ll sum=0,r=0;
	for(auto &[b,a,q]:h){
		ll ex=min({t,(xl)k-q,(xl)1ll,xl(a)});
		a-=b*ex;
		t-=ex;
		q+=ex;
		sum+=a;
		r+=q==k;
	}
	if(t<c)r=c-t;
	if(t==0)return sum==0;
	return c-r>=sum;
}

int main(){
	JET
	ll n; cin>>n>>c;
	as=bs=vv(n);
	fore(i,0,n)cin>>as[i]>>bs[i];
	ll l=0,r=1e15;
	while(r-l>1){
		ll m=(l+r)/2;
		if(can(m))r=m;
		else l=m;
	}
	ll res=r;
	cout<<res-1<<"\n";
	return 0;
}