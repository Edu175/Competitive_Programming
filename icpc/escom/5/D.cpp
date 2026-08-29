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
const ll MAXV=1e5+1;
// const ll B=3;
const ll B=100;
ll n;
ll QUERIES=0;
ll ask(ll a){
	if(a>=n)return 0;
	assert(++QUERIES<=1e4);
	cout<<"A "<<a<<endl;
	ll ret; cin>>ret;
	return ret;
}
ll remove(ll a){
	if(a>=n)return 0;
	assert(++QUERIES<=1e4);
	cout<<"B "<<a<<endl;
	ll ret; cin>>ret;
	return ret;	
}
void answer(ll x){
	assert(++QUERIES<=1e4);
	cout<<"C "<<x<<endl;
}

int main(){
	// FIN;
	cin>>n; n++; // n)
	vv is(n,1); is[0]=is[1]=0;
	// vector<vv> g(n); // tachados por primera vez en el paso i
	vv ps;
	fore(i,2,n)if(is[i]){
		// g[i].pb(i);
		ps.pb(i);
		for(ll j=1ll*i*i;j<n;j+=i){
			// if(is[j])g[i].pb(j);
			is[j]=0;
		}
	}
	// cout<<"hay "<<count(ALL(is),1)<<" primos\n";
	// ll cnt=0;
	// fore(i,0,MAXV)if(is[i])cnt+=i*i<=MAXV;
	// cout<<"hay "<<cnt<<" <= a raiz\n";
	ll r=n;
	vv bu;
	vv ans; // only set of primes
	ll cnt=n-1;
	auto do_bucket=[&](){
		ll got=ask(1);
		if(!SZ(ans)&&got==cnt){
			bu.clear();
			return;
		}
		cnt=got;
		
		for(auto p:bu)if(p<r){
			if(ask(p)){
				ans.pb(p);
				r=(r+p-1)/p; // techo pq es r)
			}
		}
		
		bu.clear();
	};
	reverse(ALL(ps));
	fore(i,0,SZ(ps)){
		ll p=ps[i];
		if(p>=r)continue;
		bu.pb(p);
		remove(p);
		cnt-=(n-1)/p;
		if(i==SZ(ps)-1||SZ(bu)==B)do_bucket();
	}
	ll res=1;
	for(auto p:ans){
		res*=p;
		for(ll pot=p*p;ask(pot);pot*=p)res*=p;
	}
	answer(res);
	return 0;
}
