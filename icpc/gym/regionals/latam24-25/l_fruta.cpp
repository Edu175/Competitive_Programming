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
#define impr(v) {for(auto i:v)cout<<i.snd<<" ";cout<<endl;}
using namespace std;
typedef int ll;
typedef long long LL;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
const ll MAXN=505*505;
random_device rd;
mt19937 rng(rd());

ll n;
ll uf[MAXN];
void uf_init(){mset(uf,-1);}
ll uf_find(ll x){return uf[x]<0?x:uf[x]=uf_find(uf[x]);}
ll uf_join(ll x, ll y){
	x=uf_find(x);
	y=uf_find(y);
	if(x==y)return 0;
	if(uf[x]>uf[y])swap(x,y);
	uf[x]+=uf[y];
	uf[y]=x;
	return 1;
}

bool check(vector<vv>&a, ll fg=0){
	fore(i,0,n){
		set<ll>st;
		fore(j,0,n){
			st.insert(a[i][j]);
			if(fg&&a[i][j]>=n)return 0;
		}
		if(SZ(st)<n)return 0;
		st.clear();
		fore(j,0,n)st.insert(a[j][i]);
		if(SZ(st)<n)return 0;
	}
	return 1;
}

vector<ll> g[MAXN];
ll no[MAXN]; set<pair<LL,ll>>st;
vv h;

bool go(){
	mset(no,0);
	h.clear();
	// impr(st)
	vector<LL> ks;
	for(auto [key,i]:st)if(!no[i]){
		h.pb(i); ks.pb(key); for(auto y:g[i])no[y]=1;
	}
	fore(i,0,SZ(h)){
		st.erase({ks[i],h[i]});
		if(i<SZ(h)-1)uf_join(h[i],h[i+1]);
	}
	// cout<<"found ";imp(h)
	return SZ(h);
}


int main(){
	JET
	uf_init();
	ll k; cin>>n>>k;
	vector<pair<char,ii>>ts(k);
	fore(_,0,k){
		char c; cin>>c;
		ll i,j; cin>>i>>j; i--,j--;
		ts[_]={c,{i,j}};
	}
	stable_sort(ALL(ts),
	[&](const pair<char,ii> &a, const pair<char,ii> &b){
		return a.fst<b.fst;
	});
	vector<vv>a(n,vv(n));
	fore(i,0,n)fore(j,0,n)a[i][j]=(i*n+j);
	auto s=a;
	fore(_,0,k){
		auto [c,pa]=ts[_];
		auto [i,j]=pa;
		if(c=='C'){
			fore(k,0,n)swap(a[k][i],a[k][j]);
		}
		else swap(a[i],a[j]);
	}
	fore(i,0,n){
		fore(j,0,n)uf_join(a[i][j],s[i][j]);
	}
	auto compress=[&](){ // given uf joins
		fore(i,0,n)fore(j,0,n)a[i][j]=uf_find(a[i][j]);
		vv vals;
		fore(i,0,n)fore(j,0,n)vals.pb(a[i][j]);
		sort(ALL(vals));
		auto _vals=vals; vals.clear();
		for(auto i:_vals)if(!SZ(vals)||i!=vals.back())vals.pb(i);
		fore(i,0,n)fore(j,0,n)
			a[i][j]=lower_bound(ALL(vals),a[i][j])-vals.begin();
	};
	compress();
	if(!check(a)){cout<<"*\n";return 0;}
	// fore(i,0,n){
	// 	fore(j,0,n)cout<<a[i][j]<<" ";
	// 	cout<<"\n";
	// }
	fore(i,0,n)fore(j,0,n){
		vv vs;
		fore(k,0,n){
			if(k!=i)vs.pb(a[k][j]);
			if(k!=j)vs.pb(a[i][k]);
		}
		for(auto v:vs)g[a[i][j]].pb(v);
	}
	ll cont=0;
	cerr<<"antes "<<double(clock())/CLOCKS_PER_SEC<<endl;
	do{
		// cerr<<"attempt "<<++cont<<endl;
		uf_init();
		st.clear();
		auto _a=a;
		fore(i,0,n)fore(j,0,n)st.insert({rng(),a[i][j]});
		while(go());
		compress();
		// assert(check(a,1));
		if(check(a,1))break;
		a=_a;
	}while(clock()<0.485*CLOCKS_PER_SEC);
	if(!check(a,1)){cout<<"*\n";return 0;}
	
	fore(i,0,n){
		fore(j,0,n)cout<<a[i][j]+1<<" ";
		cout<<"\n";
	}
	return 0;
}