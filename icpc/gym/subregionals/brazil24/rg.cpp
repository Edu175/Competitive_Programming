#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(a) {for(auto x:a)cout<<x<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
random_device rd;
mt19937 rng(rd());

int main(){
	JET
	ll N,V,Q; cin>>N>>V>>Q;
	auto getv=[&](){return rng()%V+1;};
	ll n = N;
	n = rng()%N+1;
	cout<<n<<"\n";
	fore(i,0,n)cout<<getv()<<" ";
	cout<<"\n";
	vv h(n); iota(ALL(h),0);
	fore(i,n,2*n-1){
		ll idx=rng()%SZ(h);
		cout<<h[idx]+1<<" ";
		swap(h[idx],h.back()); h.pop_back();
		idx=rng()%SZ(h);
		cout<<h[idx]+1<<"\n";
		swap(h[idx],h.back()); h.pop_back();
		h.pb(i);
	}
	assert(SZ(h)==1);
	ll q=Q;
	q=rng()%Q+1;
	cout<<q<<"\n";
	while(q--){
		ll x=rng()%n; cout<<x+1<<" "<<getv()<<"\n";
	}
	return 0;
}