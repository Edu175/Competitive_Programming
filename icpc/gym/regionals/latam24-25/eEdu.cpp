#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b; i<jet;i++)
#define pb push_back
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define imp(v) {for(auto i:v)cout<<i<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

bool good(vv a){
	ll n=SZ(a);
	ll did=0,res=1;
	fore(i,0,n-1){
		did|=a[i]>a[i+1];
		if(did)res&=a[i]>a[i+1];
		else res&=a[i]<a[i+1];
	}
	return res;
}

int main(){
	JET
	ll n; cin>>n;
	vv a(n);
	fore(i,0,n)cin>>a[i];
	vv is(n+1);
	fore(i,0,n)is[a[i]]=1;
	if(*max_element(ALL(a))==0){
		vv ret(n); iota(ALL(ret),1);
		imp(ret);
		return 0;
	}
	auto solve=[&](vv a){
		vv p(n);
		ll l=0,r=n-1;
		ll s=max_element(ALL(a))-a.begin();
		ll u=a[s];
		for(ll i=s;i>=0;i--){
			if(a[i])u=a[i];
			p[i]=u;
		}
		u=n+5;
		fore(i,s+1,n){
			if(a[i])u=a[i];
			p[i]=u;
		}
		queue<ll>q;
		fore(i,1,n+1)if(!is[i])q.push(i);
		ll bl=0,br=0;
		auto meto=[&](ll i){
			if(!a[i])a[i]=q.front(),q.pop();
		};
		while(l<=r){
			ll go=!(p[l]<p[r]);
			if(SZ(q)){
				ll x=q.front();
				if(x<bl)go=1;
				if(x<br)go=0;
			}
			if(!go)meto(l),bl=max(bl,a[l]),l++;
			else meto(r),br=max(br,a[r]),r--;
		}
		return a;
	};
	auto r0=solve(a);
	reverse(ALL(a));
	auto r1=solve(a);
	reverse(ALL(r1));
	if(good(r0)){
		imp(r0);
	}
	else if(good(r1)){
		imp(r1);
	}
	else cout<<"*\n";
}