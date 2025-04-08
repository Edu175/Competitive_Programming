#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cerr<<i<<" "; cerr<<"\n";}
#define impr(v) {for(auto i:v)cerr<<i.fst<<","<<i.snd<<" "; cerr<<endl;}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef struct item *pitem;
random_device rd;
mt19937 rng(rd());
struct item {
	int pr;
	ll key;
	int cnt;
	pitem l,r;
	item(int key):key(key),pr(rng()),cnt(1),l(0),r(0) {}
};
int cnt(pitem t){return t?t->cnt:0;}
void upd_cnt(pitem t){if(t)t->cnt=cnt(t->l)+cnt(t->r)+1;}
void split(pitem t, ll key, pitem& l, pitem& r){ // l: < key, r: >= key
	if(!t)l=r=0;
	else if(key<t->key)split(t->l,key,l,t->l),r=t;
	else split(t->r,key,t->r,r),l=t;
	upd_cnt(t);
}
void insert(pitem& t, pitem it){
	if(!t)t=it;
	else if(it->pr>t->pr)split(t,it->key,it->l,it->r),t=it;
	else insert(it->key<t->key?t->l:t->r,it);
	upd_cnt(t);
}
void merge(pitem& t, pitem l, pitem r){
	if(!l||!r)t=l?l:r;
	else if(l->pr>r->pr)merge(l->r,l->r,r),t=l;
	else merge(r->l,l,r->l),t=r;
	upd_cnt(t);
}
void erase(pitem& t, ll key){
	if(t->key==key)merge(t,t->l,t->r);
	else erase(key<t->key?t->l:t->r,key);
	upd_cnt(t);
}
// void unite(pitem &t, pitem l, pitem r){ // linear, I think (O(n+m))
// 	if(!l||!r){t=l?l:r;return;}
// 	if(l->pr<r->pr)swap(l,r);
// 	pitem p1,p2;split(r,l->key,p1,p2);
// 	unite(l->l,l->l,p1);unite(l->r,l->r,p2);
// 	t=l;upd_cnt(t);
// }
pitem kth(pitem t, int k){
	if(!t)return 0;
	if(k==cnt(t->l))return t;
	return k<cnt(t->l)?kth(t->l,k):kth(t->r,k-cnt(t->l)-1);
}
pair<int,ll> lb(pitem t, ll key){ // position and value of lower_bound
	if(!t)return {0,1ll<<60}; // (special value)
	if(key>t->key){
		auto w=lb(t->r,key);w.fst+=cnt(t->l)+1;return w;
	}
	auto w=lb(t->l,key);
	if(w.fst==cnt(t->l))w.snd=t->key;
	return w;
}
void dbg(pitem t){
	if(!t)return;
	dbg(t->l);
	cerr<<t->key<<"\n";
	dbg(t->r);
	
}
vector<pitem> nod;
void dfs(pitem t, ll dif){
	if(!t)return;
	dfs(t->l,dif);
	t->key+=dif;
	nod.pb(t);
	dfs(t->r,dif);
}
// #pragma GCC optimize("Ofast,O3,unroll-loops,inline")
// #pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
const ll INF=2e9;



struct node{
	ll dif=0;
	pitem t=0;
	node(){}
	// invariant no erases
	void put(ll v){
		v-=dif;
		pitem p=new item(v);
		merge(t,t,p);
	}
	void put(pitem p){
		// p->key-=dif;
		p->l=p->r=0; p->cnt=1;
		pitem r;
		split(t,p->key,t,r);
		merge(t,t,p);
		merge(t,t,r);
	}
	// int lwb(ll v){return st.order_of_key({v-dif,-1});}
	int cost(int d){ // -1 o 1, <- o ->
		int l=lb(t,-dif).fst,r=cnt(t)-lb(t,1-dif).fst; // aca habia un bug que no salto (no hacia el dif)
		int m=cnt(t)-l-r;
		ll ret=m+(d==1?r-l:l-r);
		// cerr<<"cost "<<d<<" "<<dif<<": "<<ret<<"\n";
		// dbg(t);
		return ret;
	}
	ll cut(bool d){
		if(d==1){
			auto [pos,val]=lb(t,-dif);
			if(pos==0)return INF;
			return -(kth(t,pos-1)->key+dif);
		}
		else {
			auto [pos,val]=lb(t,-dif+1);
			if(pos==cnt(t))return INF;
			return val+dif;
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
	priority_queue<pair<int,int>> bst;
	auto in=[&](int w, int d){
		if(ds[w].cut(d))bst.push({-ds[w].cost(d),w});
	};
	auto cand=[&](int w, int i){
		if(a[w]>0&&a[i]<0)in(w,1);
		if(a[w]<0&&a[i]>0)in(w,-1);
	};
	int w=-1;
	fore(i,0,n){
		if(a[i]){
			if(w!=-1)cand(w,i);
			st.insert(i);
			ds[w=i].put((ll)0);
		}
		else ds[w].put((ll)0);
	}
	auto merge=[&](int i, int j){ // el j desaparece
		if(cnt(ds[i].t)<cnt(ds[j].t))swap(ds[i],ds[j]);
		auto &me=ds[j];
		dfs(me.t,me.dif-ds[i].dif);
		for(auto p:nod)ds[i].put(p);
		nod.clear();
		// unite(ds[i].t,ds[i].t,me.t); // quadratic
	};
	auto saco=[&](auto it){
		assert(it!=st.begin());
		int l=*prev(it),m=*it,r=*next(it);
		// cout<<"saco "<<l<<" "<<m<<" "<<r<<endl;
		merge(l,m);
		cand(l,r);
	};
	ll res=0;
	while(SZ(bst)){
		// imp(st)
		// impr(bst)
		auto [cst,i]=bst.top(); bst.pop(); cst=-cst;
		assert(i!=n-1);
		bool d=a[i]>0;
		auto it=st.lower_bound(i);
		// cerr<<"pinchilaaaa\n";
		if(ds[i].cost(d)!=cst||*it!=i)continue;
		int j=*next(it); 
		bool good=a[i]>0&&a[j]<0;
		if(!d)good=a[j]>0&&a[i]<0;
		if(!good)continue;
		int fl=min({(ll)abs(a[i]),(ll)abs(a[j]),ds[i].cut(d)});
		int _i=i,_j=j;
		if(d==0){ds[i].dif-=fl;swap(i,j);}
		else ds[i].dif+=fl;
		assert(a[i]>0&&a[j]<0);
		// imp(a)
		// cerr<<i<<" "<<j<<": "<<cst<<" "<<fl<<endl;
		bool did=0;
		fore(_,0,2){
			if((abs(a[*it])-fl==0))saco(it),it=st.erase(it),did=1;
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