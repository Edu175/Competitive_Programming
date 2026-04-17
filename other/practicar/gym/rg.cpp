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
typedef long double ld;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

random_device rd;
mt19937 rng(rd());

vv distinct(ll k, ll n){ // [0,n)
	n=max(n,k);
	vv res;
	if(2*k>=n){
		vv all(n); iota(ALL(all),0);
		shuffle(ALL(all),rng);
		res=vv(all.begin(),all.begin()+k);
		sort(ALL(res));
	}
	else {
		set<ll> st;
		fore(_,0,k){
			ll x=rng()%n;
			while(st.count(x))x=rng()%n;
			st.insert(x);
		}
		res=vv(ALL(st));
	}
	return res;
}
ll X,Y;
ll gety(){return rng()%(Y+1);}
int main(){FIN;
	ll N,L; cin>>N>>X>>Y>>L;
	
	ll n=rng()%(N+1);
	vv xs=distinct(n+2,X+1);
	cout<<xs[0]<<" "<<gety()<<" ";
	cout<<xs.back()<<" "<<gety()<<"\n";
	cout<<n<<"\n";
	fore(i,1,n+1){
		cout<<xs[i]<<" ";
		ll l=gety(),z=rng()%(min(L,Y-l)+1);
		cout<<l<<" "<<l+z<<"\n";
	}
}