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
	// cerr<<"mop "<<l<<","<<r<<"\n";
	// show(a)
	ops.pb({l,r});
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
	ll s=l+1,e=r-1;
	while(s<=e){
		assert(a[l]&&b[r]);
		assert(!b[l]&&!a[r]);
		if(a[s]!=b[s])s++;
		else if(a[s]==0){
			mop(l,s); l=s; s++;
		}
		else if(a[e]!=b[e])e--;
		else if(a[e]==1){
			mop(e,r); r=e; e--;
		}
		else mop(s,e),s++,e--;
	}
	assert(l<r);
	mop(l,r);
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
