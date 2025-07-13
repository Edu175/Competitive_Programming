#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<endl;}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MX=2500100;
#define tle(c) if(!(c)){auto t=clock();while(clock()-t<CLOCKS_PER_SEC*100);};

vector<ll> fib;
pair<vv,vv> get(ll v){
	vv id[2];
	for(ll i=SZ(fib)-1;i>=0;i--){
		if(v>=fib[i])v-=fib[i],id[i&1].pb(fib[i]);
	}
	tle(!v);
	return {id[0],id[1]};
}

int main(){FIN;
	ll n; cin>>n;
	fib={1,1};
	while(fib.back()<=n)fib.pb(fib.back()+fib.end()[-2]);
	vv a(n);
	fore(i,0,n)cin>>a[i];
	vector<array<ll,3>>res;
	//operacion
	auto agr=[&](ll i, char c, ll j){
		res.pb({i,c,j}); 
		if(c=='-')a[i]-=a[j];
		else a[i]+=a[j];
		tle(SZ(res)<MX);
		assert(a[i]>=1&&a[i]<=n); // salta este
	};
	
	ll p=find(ALL(a),1)-a.begin();
	ll q=p==0?1:p-1;
	while(a[q]>a[p])agr(q,'-',p);
	p=min(p,q);
	
	// bajar r con p y q
	auto down=[&](ll p, ll q, ll r){ // q es el del medio
		tle(a[p]==1&&a[q]==1);
		auto [ev,od]=get(a[r]-1);
		auto f=[&](ll w,auto &&f){
			if(!SZ(ev))return;
			if(ev.back()==a[q]){
				agr(r,'-',q);
				ev.pop_back();
			}
			if(!SZ(ev))return;
			ll u=!w?q:p,v=u^q^p;
			agr(u,'+',v),f(w^1,f),agr(u,'-',v);
		};
		f(0,f);
		swap(ev,od);
		f(1,f);
	};
	
	// bajo todos
	fore(i,p+2,n)down(i-2,i-1,i);
	for(ll i=p-1;i>=0;i--)down(i+2,i+1,i);
	
	// from 111... go to id
	fore(i,1,n)agr(i,'+',i-1);
	vv id(n); iota(ALL(id),1);
	tle(id==a);
	cout<<SZ(res)<<"\n";
	for(auto [a,c,b]:res){
		cout<<a+1<<" "<<char(c)<<" "<<b+1<<"\n";
	}
	return 0;
}
