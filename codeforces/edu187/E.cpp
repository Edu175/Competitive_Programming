#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXV=ll(1e12)+5;
const ll INF=1e18;
const ll MOD=(119<<23)+1;
int add(int a, int b){a+=b;if(a>=MOD)a-=MOD;return a;}
int sub(int a, int b){a-=b;if(a<0)a+=MOD;return a;}
int mul(ll a, ll b){return a*b%MOD;}
int fpow(int a, ll b){
	if(b<0)return 0;
	int r=1;
	while(b){if(b&1)r=mul(r,a); b>>=1; a=mul(a,a);}
	return r;
}
ll inv(ll a){return fpow(a,MOD-2);}
typedef ii node;
node oper(node a, node b){return {a.fst+b.fst,a.snd+b.snd};}
ii NEUT={0,0};
struct STree{
	int n; vector<node>t;
	STree(int n):n(n),t(2*n+5,NEUT){}
	void init(vector<node>a){
		fore(i,0,n)t[n+i]=a[i];
		for(ll i=n-1;i>0;i--)t[i]=oper(t[2*i],t[2*i+1]);
	}
	void upd(int p, node v){
		for(p+=n,t[p]=oper(t[p],v);p>1;p>>=1)t[p>>1]=oper(t[p],t[p^1]);
	}
	node query(int l, int r){
		node res=NEUT;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)res=oper(res,t[l++]);
			if(r&1)res=oper(res,t[--r]);
		}
		return res;
	}
};
 // sum,cant
int main(){FIN;
	ll n; cin>>n;
	vv a(n); vector<ii> sa(n);
	fore(i,0,n)cin>>a[i],sa[i]={a[i],i};
	sort(ALL(sa));
	map<ll,ll> pos;
	fore(i,0,n)pos[sa[i].fst]=i;
	STree st(n);
	set<ll> all;
	auto get=[&](ll p)->ii {
		ll le=p,ri=p;
		ll cant=st.query(pos[p],pos[p]+1).snd;
		assert(cant>0);
		if(cant==1){
			le=-1,ri=-1;
			auto it=all.lower_bound(p);
			if(it!=all.begin())le=*prev(it);
			if(next(it)!=all.end())ri=*next(it);
		}
		ll L=0,R=0;
		if(le!=-1){
			auto [sum,cant]=st.query(0,pos[le]);
			L=cant*le-sum;
		}
		if(ri!=-1){
			auto [sum,cant]=st.query(pos[ri],n);
			R=sum-cant*ri;
		}
		return {L,R};
	};
	fore(i,0,n){
		st.upd(pos[a[i]],{a[i],1});
		all.insert(a[i]);
		ll l=0,r=MAXV;
		while(r-l>1){
			ll m=(l+r)/2;
			auto it=all.lower_bound(m);
			ll can=1;
			if(it!=all.end()){
				auto [L,R]=get(*it);
				can=L>R;
			}
			if(can)r=m;
			else l=m;
		}
		auto use=[&](auto it, ll fg)->ll {
			if(!fg&&it==all.end())return INF;
			if(fg&&it==all.begin())return INF;
			if(fg)--it;
			ll p=*it;
			auto [L,R]=get(p);
			// cout<<"use "<<p<<": "<<L<<","<<R<<"\n";
			return max(L,R);
		};
		ll tam=i+1;
		if(tam>=3){
			auto it=all.lower_bound(r);
			// cerr<<"l,r: "<<l<<","<<r<<"\n";
			ll res=min(use(it,0),use(it,1));
			// cerr<<res<<": ";
			res%=MOD;
			res=mul(res,inv(tam-2));
			cout<<res<<"\n";
		}
	}
	return 0;
}
