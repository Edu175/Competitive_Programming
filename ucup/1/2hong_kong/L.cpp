#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define pb push_back
#define fst first
#define snd second
#define show(x) {for(auto y:x)cout<<y<<" ";cout<<"\n";}
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll maxn=2e5+10;
struct Ft{
	int ft[maxn];	
	ll n;
	void clear(){
		fore(i,0,n+1) ft[i]=0;
	}
	void init(ll _n){
		n=_n+5; clear();
	}
	void upd(int i0, int v){
		for(int i=i0+1;i<n;i+=i&-i)ft[i]+=v;
	}
	int get(int i0){//[0,i0)
		int r=0;
		for(int i=i0; i; i-=i&-i)r+=ft[i];
		return r;
	}
};

bool check(ll *a, ll *b, ll n, ll m){
	ll i=0;
	for(ll j=0; j<m&&i<n; j++){
		while(i<n&&a[i]!=b[j]) i++;
		if(i==n) return false;
	}
	return true;
}
int main(){
	JET
	Ft pos;
	ll _; cin>>_; while(_--){
		ll n,m,k; cin>>n>>m>>k;
		pos.init(n+2);
		ll a[n]; fore(i,0,n) cin>>a[i];
		ll b[m]; fore(i,0,m) cin>>b[i];
		ll l[k]; fore(i,0,k) cin>>l[i];
		if(!check(a,b,n,m)) {cout<<"NO\n"; continue;}
		set<ii> t;
		set<ll> un;
		fore(i,0,k) t.insert({l[i],i});
		ll inv[n+2]; fore(i,0,n) inv[a[i]]=i+1;
		
		ll h[n+2]; mset(h,0);
		h[0]=1; h[n+1]=1;
		fore(i,0,m) h[b[i]]=1;
		un.insert(n+1);
		un.insert(0);
		fore(i,0,n+2) pos.upd(i,1);
		// ll ut=n;
		bool bad=0;
		for(ll i=n; i; i--){
			if(!h[i]){
				// cout<<i<<" "<<inv[i]<<" "<<cn<<"\n";
				
				// // cout<<R<<" "<<l<<" R l\n";
				// cout<<un.get(R)<<" "<<un.get(1)<<" "<<cn<<"R 1 cn\n";
				auto ut=un.lower_bound(inv[i]);
				ll R=*ut;
				ll L=*--ut;
				ll l=pos.get(L+1);
				ll r=pos.get(R);
				ll d=r-l;
				// cout<<i<<" "<<_l<<" "<<_r<<" "<<d<<" ilrd\n";
				auto it=t.lower_bound((ii){d+1,-1});
				if(it==t.begin()) {bad=1; break;}
				t.erase(--it);
				pos.upd(inv[i],-1);

			}
			else {
				un.insert(inv[i]);
			}
		}
		cout<<(bad?"NO\n":"YES\n");
		pos.clear();
		un.clear();
	}
	return 0;
}
// 1 1 2
// 4 6 R l
// 2 1 3R 1 cn
// 3 4 5 1 ilrd
// 1 4 R l
// 1 1 2R 1 cn
// 2 1 3 2 ilrd
// 1 4 R l
// 1 1 2R 1 cn
// 1 1 2 1 ilrd

