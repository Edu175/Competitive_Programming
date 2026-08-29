#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {cout<<#v<<": ";;for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll INF=1e9;

struct FTree{
	ll n,tot; vv ft;
	FTree(ll n):n(n),tot(0),ft(n+1){}
	void upd(int i0, int v){ // add v to i0th element (0-based)
		// add extra fors for more dimensions
		tot+=v;
		for(int i=i0+1;i<=n;i+=i&-i)ft[i]+=v;
	}
	int get(int i0){ // get sum of range [0,i0)
		int r=0;
		// add extra fors for more dimensions
		for(int i=i0;i;i-=i&-i)r+=ft[i];
		return r;
	}
	int pre(int i0){return get(i0);} // [0,i0)
	int suf(int i0){return tot-get(i0+1);} // (i0,n)
};
struct STree{
	vv a;
	int n;
	ll NEUT;
	vector<ll>t;
	ll oper(ll i, ll j){return a[i]<=a[j]?i:j;}
	STree(vv _a):a(_a),n(SZ(a)),NEUT(n),t(2*n+5){
		a.pb(INF);
		fore(i,0,n)t[n+i]=i;
		for(ll i=n-1;i>0;i--)t[i]=oper(t[2*i],t[2*i+1]);
	}
	void upd(int p, ll v){
		for(p+=n,t[p]=v;p>1;p>>=1)t[p>>1]=oper(t[p],t[p^1]);
	}
	void mata(ll p){upd(p,NEUT);}
	ll query(int l, int r){
		ll res=NEUT;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)res=oper(res,t[l++]);
			if(r&1)res=oper(res,t[--r]);
		}
		return res;
	}
	ll next(ll x){return query(x+1,n);}
};

struct getMin{
	priority_queue<ii,vector<ii>,greater<ii>> pq;
	ll dif=0;
	void push(ll x, ll val){val-=dif;pq.push({val,x});}
	void add(ll d){dif+=d;}
	void pop(){pq.pop();}
	ii top(){
		auto rq=pq.top();
		rq.fst+=dif;
		return rq;
	}
};

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv a(n);
		fore(i,0,n)cin>>a[i],a[i]--;
		FTree ftInv(n);
		ll inv=0;
		fore(i,0,n)inv+=ftInv.suf(a[i]),ftInv.upd(a[i],1);
		vector<vector<FTree>> ft(2,vector<FTree>(2,FTree(n)));
		// [x/o] [i/v]
		fore(i,0,n){
			ft[0][0].upd(i,1);
			ft[0][1].upd(a[i],1);
		}
		vv is(n);
		auto val=[&](ll i){ // when doing x -> o
			ll aba=ft[0][1].pre(a[i]);
			ll izq=ft[0][0].pre(i);
			ll esq1=izq-aba;
			ll d1=aba-esq1;
			
			ll arr=ft[1][1].suf(a[i]);
			ll der=ft[1][0].suf(i);
			ll esq2=der-arr;
			ll d2=esq2-arr;
			
			ll res=d1+d2;
			return res;
		};
		STree st(a);
		vv inSeq(n);
		getMin cand;
		set<ll> seq; seq.insert(-1);
		auto go=[&](ll p){
			while(1){
				p=st.next(p);
				if(p>=n||inSeq[p])break;
				assert(!is[p]);
				cand.push(p,val(p));
				inSeq[p]=1;
				seq.insert(p);
			}
		};
		auto use=[&](ll p){ // do x -> o
			assert(inSeq[p]); inSeq[p]=0;
			st.mata(p);
			cand.pop(); // because p is top
			ft[0][0].upd(p,-1);
			ft[0][1].upd(a[p],-1);
			
			is[p]=1;
			cand.add(-1);
			
			ft[1][0].upd(p,1);
			ft[1][1].upd(a[p],1);
			
			auto it=seq.lower_bound(p);
			it=--seq.erase(it);
			go(*it);
		};
		go(-1);
		ll res=inv;
		cout<<res<<" ";
		fore(_,0,n){
			// cout<<"\n\nstep "<<_<<":\n";
			// imp(is)
			// imp(seq)
			auto [d,p]=cand.top();
			// cout<<d<<","<<p<<"\n";
			res+=d;
			use(p);
			cout<<res<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
