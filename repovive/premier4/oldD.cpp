#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<endl;}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

vv a,b;
ll n;
vector<ii> ops;
void mop(ll l, ll r){
	fore(i,l,r+1)a[i]^=1;
	cerr<<"mop "<<l<<","<<r<<"\n";
	show(a)
	ops.pb({l,r});
}
void solve(ll l, ll r){ // already sorted
	while(1){
		while(l<=r){
			if(a[r]==b[r])r--;
			else if(a[l]==b[l])l++;
			else break;
		}
		// cerr<<"reduced to "<<l<<","<<r<<"\n";
		if(l>r)return;
		cerr<<"in loop "<<l<<","<<r<<"\n";
		assert(a[l]&&!b[l]);
		assert(!a[r]&&b[r]);
		if(r-l+1==2){
			mop(l,r);
			continue;
		}
		if(!a[l+1]&&!b[l+1]){
			ll p=l+1; while(p<r&&!a[p])p++;
			p--;
			mop(l,p);
			continue;
		}
		if(a[r-1]&&b[r-1]){
			ll p=r-1; while(p>l&&a[p])p--;
			p++;
			mop(p,r);
			continue;
		}
		assert(!(a[l+1]&&!a[r-1])); // bc its sorted
		// 	cerr<<"tuvo que flipear\n";
		// 	mop(l+1,r-1);
		// }
		if(a[r-1]){
			// cerr<<"hago derecha\n";
			ll p=r-1;
			while(p>=l&&a[p]&&!b[p])p--;
			if(p<l||!a[p])p++;
			mop(p,r);
			continue;
		}
		// cerr<<"hago izquierda\n";
		assert(!a[l+1]);
		ll p=l+1;
		while(p<=r&&!a[p]&&b[p])p++;
		if(p>r||a[p])p--;
		mop(l,p);
	}
}
bool doit(){
	ll l=0,r=n-1;
	while(l<=r){
		if(a[r]==b[r])r--;
		else if(a[l]==b[l])l++;
		else if(a[r])return 0;
		else if(!a[l]) return 0;
		else break;
	}
	if(l>r)return 1;
	assert(a[l]&&b[r]);
	assert(!b[l]&&!a[r]);
	ll _l=l,_r=r; l++,r--;
	// sort it
	while(l<=r){
		if(a[r])r--;
		else if(!a[l])l++;
		else mop(l,r);
	}
	l=_l,r=_r;
	solve(l,r);
	return 1;
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n;
		string s,t; cin>>s>>t;
		ops.clear();
		a=b=vv(n);
		fore(i,0,n)a[i]=s[i]-'0',b[i]=t[i]-'0';
		ll good=doit();
		if(!good){
			cout<<"-1\n";
			continue;
		}
		assert(a==b);
		assert(SZ(ops)<=n);
		cout<<SZ(ops)<<"\n";
		for(auto [l,r]:ops)cout<<l+1<<" "<<r+1<<"\n";
	}
	return 0;
}
