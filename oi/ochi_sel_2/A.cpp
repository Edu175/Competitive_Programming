#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

vector<bool> laboratorio(vector<vector<int>> pruebas);

vector<bool> ask(vector<vector<ll>>v){
	vector<vector<int>>r;
	for(auto a:v){
		vector<int>as;
		for(auto i:a)as.pb(i+1);
		r.pb(as);
	}
	return laboratorio(r);
}
int mote_con_huesito(int N){
	ll n=N,K=64-__builtin_clzll(n);
	//if(__builtin_popcount(n)==1)K--;
	assert(1<<K>=n);
	vector<vector<ll>>st(2<<K);
	ll C=1<<K;
	fore(i,0,n){
		ll p=C+i;
		while(p)st[p].pb(i),p/=2;
	}
	vector<vector<ll>>v(K);
	fore(i,1,SZ(st))if(i%2==0&&SZ(st[i])){
		for(auto j:st[i])v[62-__builtin_clzll(i)].pb(j);
	}
	vector<set<ll>>is(SZ(v));
	fore(i,0,SZ(v))for(auto j:v[i])is[i].insert(j);
	auto r=ask(v);
	vector<ll>ans;
	fore(i,0,n){
		ll flag=1;
		fore(j,0,SZ(v))if(r[j]!=is[j].count(i))flag=0;
		if(flag)ans.pb(i);
	}
	//imp(ans);
	//cout<<endl;
	assert(SZ(ans)==1);
	return ans[0]+1;
}
