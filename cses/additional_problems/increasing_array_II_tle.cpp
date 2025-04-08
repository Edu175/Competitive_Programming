#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cerr<<i<<" "; cout<<"\n";}
#define impr(v) {for(auto i:v)cout<<i.fst<<","<<i.snd<<" "; cout<<endl;}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
 
#pragma GCC optimize("Ofast,O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
const ll INF=2e9;
 
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree
<pair<ll,int>,null_type,less<pair<ll,int>>,rb_tree_tag,tree_order_statistics_node_update>
indexed_set;
// find_by_order(i) -> iterator to ith element
// order_of_key(k) -> position (int) of lower_bound of k
//less_equal for repeated elements (erase only with pointer)
 
struct node{
	ll dif=0;
	indexed_set st;
	node(){}
	// invariant no erases
	void put(ll v){st.insert({v-dif,SZ(st)});}
	int lwb(ll v){return st.order_of_key({v-dif,-1});}
	int cost(int d){ // -1 o 1, <- o ->
		int l=lwb(0),r=SZ(st)-lwb(1);
		int m=SZ(st)-l-r;
		return m+(d==1?r-l:l-r);
	}
	ll cut(int d){
		if(d==1){
			auto it=st.lower_bound({-dif,-1});
			if(it==st.begin())return INF;
			return -(prev(it)->fst+dif);
		}
		else {
			auto it=st.lower_bound({-dif+1,-1});
			if(it==st.end())return INF;
			return it->fst+dif;
		}
	}
};
 
int main(){FIN;
	int n; cin>>n;
	// vector<ll> a(n);
	// fore(i,0,n)cin>>a[i];
	vector<int>b(n),a(n+1);
	fore(i,0,n)cin>>b[i];
	fore(i,1,n)a[i]=b[i]-b[i-1];
	a[0]=a[n]=INF;
	n++;
	// imp(a);
	set<int>st;
	vector<node> ds(n);
	multiset<pair<int,int>> bst;
	auto in=[&](int w, int d){
		if(ds[w].cut(d))bst.insert({ds[w].cost(d),w});
	};
	auto cand=[&](int w, int i){
		if(a[w]>0&&a[i]<0)in(w,1);
		if(a[w]<0&&a[i]>0)in(w,-1);
	};
	auto out=[&](int w, int d){
		// cout<<"out "<<w<<" "<<d<<": "<<ds[w].cost(d)<<","<<w<<endl;
		if(ds[w].cut(d))bst.erase(bst.find({ds[w].cost(d),w}));
	};
	int w=-1;
	fore(i,0,n){
		if(a[i]){
			if(w!=-1)cand(w,i);
			st.insert(i);
			ds[w=i].put(0);
		}
		else ds[w].put(0);
	}
	auto merge=[&](int i, int j){ // el j desaparece
		if(SZ(ds[i].st)<SZ(ds[j].st))swap(ds[i],ds[j]);
		auto &me=ds[j];
		for(auto v:me.st)ds[i].put(v.fst+me.dif);
		me.st.clear();
	};
	auto saco=[&](auto it, int _i, int _j){
		assert(it!=st.begin());
		auto doit=[&](int i, int j){
			if(i==_i&&j==_j)return;
			if(a[i]>0&&a[j]<0)out(i,1);
			if(a[i]<0&&a[j]>0)out(i,-1);
		};
		int l=*prev(it),m=*it,r=*next(it);
		// cout<<"saco "<<l<<" "<<m<<" "<<r<<endl;
		doit(m,r);
		doit(l,m);
		merge(l,m);
		cand(l,r);
	};
	ll res=0;
	while(SZ(bst)){
		// imp(st)
		// impr(bst)
		auto [cst,i]=*bst.begin(); bst.erase(bst.begin());
		assert(i!=n-1);
		auto it=st.lower_bound(i);
		assert(*it==i);
		int j=*next(it),d=a[i]>0?1:-1;
		int fl=min({(ll)abs(a[i]),(ll)abs(a[j]),ds[i].cut(d)});
		int _i=i,_j=j;
		if(d==-1){ds[i].dif-=fl;swap(i,j);}
		else ds[i].dif+=fl;
		assert(a[i]>0&&a[j]<0);
		// imp(a)
		// cout<<i<<" "<<j<<": "<<cst<<" "<<fl<<endl;
		bool did=0;
		fore(_,0,2){
			if((abs(a[*it])-fl==0))saco(it,_i,_j),it=st.erase(it),did=1;
			else it++;
		}
		if(!did)cand(_i,_j);
		a[i]-=fl;
		a[j]+=fl;
		res+=ll(cst)*fl;
	}
	cout<<res<<"\n";
	return 0;
}