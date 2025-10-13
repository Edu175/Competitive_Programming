#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
typedef vv poly;


const ll K=20;
const ll maxn=(1<<K); //ajustado!!



poly sos(poly p){
	ll n=SZ(p);
	fore(k,0,K)fore(i,0,n){
		if(i>>k&1)p[i]+=p[i^(1ll<<k)];
	}
	return p;
}
poly sosInv(poly p){
	ll n=SZ(p);
	fore(k,0,K)for(ll i=n-1;i>=0;i--){
		if(i>>k&1)p[i]-=p[i^(1ll<<k)];
	}
	return p;
}
poly brute(poly p, poly q){
	ll n=SZ(p);
	assert(n==SZ(q)); // mismo tamanio!!!
	poly r(maxn,0);
	fore(i,0,n)fore(j,0,n){
		r[i|j]+=p[i]*q[j];
	}
	return r;
}
poly conv(poly p, poly q){
	ll n=SZ(p);
	
	// poly r=brute(p,q);
	
	assert(n==SZ(q)); // mismo tamanio!!!
	p=sos(p); q=sos(q);
	fore(i,0,n)p[i]*=q[i];
	p=sosInv(p);
	
	// assert(p==r);
	
	return p;
}

poly operator+(poly p, poly q){
	poly r(maxn,0);
	fore(i,0,maxn){
		r[i]=p[i]+q[i];
	}
	return r;
}
poly operator-(poly p, poly q){
	poly r(maxn,0);
	fore(i,0,maxn){
		r[i]=p[i]-q[i];
	}
	return r;
}

poly operator*(ll t, poly &p){
	poly r(maxn,0);
	fore(i,0,maxn){
		r[i]=t*p[i];
	}
	return r;
}
ll k;
ll mk(string &s){
	ll x=0;
	fore(i,0,k)if(s[i]=='1'){
		x|=(1<<i);
	}
	return x;
}

int main(){
	JET
	ll n; cin>>n>>k;
	poly p(maxn,0);
	fore(i,0,n){
		string s;
		cin>>s;
		p[mk(s)]+=1;
	}
	// for(auto c:p) cout<<c<<" ";;cout<<"\n";
	poly r=conv(p,p);
	// for(auto c:r) cout<<c<<" ";;cout<<"\n";
	
	r=(conv(r,p)-(3*r))+(2*p);
	// for(auto c:r) cout<<c<<" ";;cout<<"\n";
	ll m; cin>>m;
	fore(i,0,m){
		string s; cin>>s;
		ll k=r[mk(s)];
		cout<<k/6<<"\n";
	}
	
	return 0;
}