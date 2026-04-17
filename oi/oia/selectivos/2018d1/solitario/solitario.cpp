#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oia=b;i<oia;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto kdfjg:v)cout<<kdfjg<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
ll n,k;
vector<ll>a;
ll simul(ll n, ll k){
	vector<ll>a;
	fore(i,0,n)a.pb(i);
	vector<ll>vis(n);
	ll j=0,i=0,cnt=0;
	while(cnt<n-1){
		if(i==n){i=0;imp(vis);}
		if(vis[i]);
		else if(j==0)vis[i]=1,j=k,cnt++;
		else j--;
		i++;
	}
	imp(vis);
	fore(i,0,n)if(!vis[i])return i;
	assert(0);
}

ll get(ll i){
	i=n-1-i;
	return a[i%SZ(a)];
}
/*ll sub3(ll n, ll k){
	assert(k==1);
	ll p=1ll<<(63-__builtin_clzll(n));
	ll pri=2*(n-p);
	return (pri-1+n)%n;
}*/
ll f(ll x, ll r){
	return x-x/k-(x%k>r);
}

ll inv(ll p, ll n, ll r){
	ll y=__int128(p)*__int128(k)/__int128(k-1)%__int128(n);
	fore(i,y-3,y+3){
		ll x=(i%n+n)%n;
		if(x%k!=r&&f(x,r)==p)return x;
	}
	assert(0);
	ll s=0,e=n-1;
	while(s<=e){
		ll m=(s+e)/2;
		if(f(m,r)>p)e=m-1;
		else s=m+1;
	}
	assert(e%k!=r&&f(e,r)==p);
	return e;
}

ll card(ll n, ll K){
	if(n==1)return 0;
	k=K+1;
	if(k==1)return n-1;
	ll r=0;
	vector<ll>ns={n},rs={r};
	while(n>1){
		ll ri;
		if(r>=n)ri=r%n;
		else ri=(r-n%k+k)%k;
		n=f(n,r);
		r=ri;
		ns.pb(n); rs.pb(r);
	}
	//cerr<<SZ(ns)<<"\n";
//	imp(ns);
//	imp(rs);
	ll p=0;
	for(ll i=SZ(ns)-2;i>=0;i--){
		ll n=ns[i],r=rs[i];
		p=inv(p,n,r);
	}
//	cerr<<p<<" p\n";
	return p;
}
void debug(ll N, ll K){
	ll steps; srand((long long)&steps); steps=0;
	while(1){
		ll n=rand()%N+1,k=rand()%(K+1);
		if(card(n,k)!=simul(n,k)){
			cout<<"FAILED!!!\n";
			cout<<"try "<<n<<" "<<k<<endl;
			cout<<"expected "<<simul(n,k)<<", found "<<card(n,k)<<endl;
			exit(0);
		}
		cout<<"ok "<<++steps<<endl;
	}
}
int solitario(vector<int> C, long long N, int k){
	n=N;
	for(auto i:C)a.pb(i);
	//reverse(ALL(a));
	//debug(n,k);
	//cout<<simul(n,k)<<" s\n";
	ll p;
	//if(k==1)p=sub3(n,k);
	p=card(n,k);
    return get(p);
}
