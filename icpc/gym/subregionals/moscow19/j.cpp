#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b; i<jet; i++)
#define fst first
#define snd second
#define pb push_back
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXN=3e5+5;

ll ans,tot;
ll fn(ll n){return n*(n+1)/2;}
ll val(ii x){return fn(x.snd-x.fst);}
ll n;
struct node{
	ll cur;
	set<ii>st;
	node(){
		st.insert({0,0});
		st.insert({n,n});
		cur=tot;
	}
	ll fun(auto it){ // ranges blancos
		if(it==st.end()||it==st.begin())return 0;
		return fn(it->fst-prev(it)->snd);
	}
	void merge(auto it){
		if(it==st.end()||it==st.begin())return; // no deberia pasar
		if(it->fst==prev(it)->snd){
			cur-=val(*it)+val(*prev(it));
			ll s=prev(it)->fst,e=it->snd;
			st.erase(prev(it));
			it++;
			st.erase(prev(it));
			st.insert({s,e});
			it--;
			cur+=val(*it);
		}
	}
	void put(ii x){
		if(!(x.snd-x.fst))return;
		auto it=st.upper_bound(x);
		cur-=fun(it);
		st.insert(x);
		cur+=val(x);
		cur+=fun(it)+fun(prev(it));
		
		merge(prev(it));
		merge(it);
	}
	ll get(){return tot-cur;}
};

vv g[MAXN];
ll res;
node dfs(ll x, ll fa=-1){
	node ans;
	ans.put({x,x+1});
	for(auto y:g[x])if(y!=fa){
		auto cur=dfs(y,x);
		res+=cur.get();
		if(SZ(ans.st)<SZ(cur.st))swap(ans,cur);
		for(auto i:cur.st)ans.put(i);
	}
	return ans;
}


int main(){
    JET
	cin>>n;
	tot=fn(n);
	fore(i,1,n){
		ll p; cin>>p; p--;
		g[p].pb(i);
	}
	dfs(0);
	res+=tot;
	cout<<res<<"\n";
    return 0;
}