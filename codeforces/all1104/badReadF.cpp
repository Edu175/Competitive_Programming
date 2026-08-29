#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll INF=1e18;
/*
struct STreeMin{
	typedef ii tn; // node type
	typedef array<ll,3> tl; // lazy type
	ii NEUT={INF,0}; // min , sum of difs
	tl CLEAR={0,0,0};
	tn oper(tn a, tn b){
		return {min(a.fst,b.fst),a.snd+b.snd};
	}
	void acum(tl &a, tl v){ // accumulate lazy node
		a[0]=a[0]+a[1]*a[2]+v[0];
		a[1]+=v[1];
		a[2]=v[2];
	}
	tn calc(int s, int e, tn a, tl v){ // calculate STree range, a=previous value
		assert(s|e|1); // useless, it's only to avoid compiler warning
		a.fst+=v.fst;
		a.snd+=(e-s)*v.snd;
		return a;
	}
	vector<tn>st; vector<tl>lazy; int n;
	void apply_difs(){
		st[1]
	}
	STreeMin(int n):st(4*n+5,NEUT),lazy(4*n+5,CLEAR),n(n){}
	void init(int k, int s, int e, vector<tn>&a){
		if(e-s==1)st[k]=a[s];
		else {
			int m=(s+e)/2;
			init(2*k,s,m,a); init(2*k+1,m,e,a);
			st[k]=oper(st[2*k],st[2*k+1]);
		}
	}
	void push(int k, int s, int e){
		if(lazy[k]==CLEAR)return;
		st[k]=calc(s,e,st[k],lazy[k]);
		if(e-s!=1){
			acum(lazy[2*k],lazy[k]);
			acum(lazy[2*k+1],lazy[k]);
		}
		lazy[k]=CLEAR;
	}
	void upd(int k, int s, int e, int a, int b, tl v){ // range update
		push(k,s,e);
		if(e<=a||b<=s)return;
		if(a<=s&&e<=b){
			acum(lazy[k],v);
			push(k,s,e);
			return;
		}
		int m=(s+e)/2;
		upd(2*k,s,m,a,b,v),upd(2*k+1,m,e,a,b,v);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	tn query(int k, int s, int e, int a, int b){
		if(e<=a||b<=s)return NEUT;
		push(k,s,e);
		if(a<=s&&e<=b)return st[k];
		int m=(s+e)/2;
		return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
	}
	void upd(int k, int s, int e, int p, tn v){ // assign v to position p
		push(k,s,e);
		if(e<=p||p<s)return;
		if(e-s==1&&s==p){
			push(k,s,e);
			st[k]=v;
			return;
		}
		int m=(s+e)/2;
		upd(2*k,s,m,p,v),upd(2*k+1,m,e,p,v);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	void upd(int p, tn v){upd(1,0,n,p,v);}
	void upd(int a, int b, tl v){upd(1,0,n,a,b,v);}
	tn query(int a, int b){return query(1,0,n,a,b);}
	void init(vector<tn>&a){init(1,0,n,a);}
};
*/
struct STreePair{
	typedef ii tn; // node type
	typedef ii tl; // lazy type
	ii NEUT={INF,0}; // min , sum of js
	ii CLEAR={0,0};
	tn oper(tn a, tn b){
		return {min(a.fst,b.fst),a.snd+b.snd};
	}
	void acum(tl &a, tl v){ // accumulate lazy node
		a.fst+=v.fst;
		a.snd+=v.snd;
	}
	tn calc(int s, int e, tn a, tl v){ // calculate STree range, a=previous value
		assert(s|e|1); // useless, it's only to avoid compiler warning
		a.fst+=v.fst+a.snd*v.snd;
		return a;
	} 
	vector<tn>st; vector<tl>lazy; int n;
	STreePair(int n):st(4*n+5,NEUT),lazy(4*n+5,CLEAR),n(n){}
	void init(int k, int s, int e, vector<tn>&a){
		if(e-s==1)st[k]=a[s];
		else {
			int m=(s+e)/2;
			init(2*k,s,m,a); init(2*k+1,m,e,a);
			st[k]=oper(st[2*k],st[2*k+1]);
		}
	}
	void push(int k, int s, int e){
		if(lazy[k]==CLEAR)return;
		st[k]=calc(s,e,st[k],lazy[k]);
		if(e-s!=1){
			acum(lazy[2*k],lazy[k]);
			acum(lazy[2*k+1],lazy[k]);
		}
		lazy[k]=CLEAR;
	}
	void upd(int k, int s, int e, int a, int b, tl v){ // range update
		push(k,s,e);
		if(e<=a||b<=s)return;
		if(a<=s&&e<=b){
			acum(lazy[k],v);
			push(k,s,e);
			return;
		}
		int m=(s+e)/2;
		upd(2*k,s,m,a,b,v),upd(2*k+1,m,e,a,b,v);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	tn query(int k, int s, int e, int a, int b){
		if(e<=a||b<=s)return NEUT;
		push(k,s,e);
		if(a<=s&&e<=b)return st[k];
		int m=(s+e)/2;
		return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
	}
	void upd(int k, int s, int e, int p, tn v){ // assign v to position p
		push(k,s,e);
		if(e<=p||p<s)return;
		if(e-s==1&&s==p){
			push(k,s,e);
			st[k]=v;
			return;
		}
		int m=(s+e)/2;
		upd(2*k,s,m,p,v),upd(2*k+1,m,e,p,v);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	void upd(int p, tn v){upd(1,0,n,p,v);}
	void upd(int a, int b, tl v){upd(1,0,n,a,b,v);}
	tn query(int a, int b){return query(1,0,n,a,b);}
	void init(vector<tn>&a){init(1,0,n,a);}
	#undef NEUT
	#undef oper
};
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		vv a(n);
		fore(i,0,n)cin>>a[i];
		if(m==1){
			ll res=0;
			fore(i,0,n)res+=a[i]-1;
			cout<<res<<"\n";
			continue;
		}
		fore(i,0,n)a[i]=i-a[i]+1;
		// vector<STreeSum> st1les(2,STreeSum(n)),st1big=st1les;
		vector<STreePair> st1(2,STreePair(n));
		// vector<STreeMin> st2(2,STreeMin(n));
		auto st2=st1;
		ll ans;
		vector<priority_queue<ii,vector<ii>,greater<ii>>> pq(2);
		fore(i,0,n+1)fore(did,0,2){
			ll caso2=INF;
			ll caso1=INF;
			if(i>=m){ // caso 2
				caso2=st2[did].query(i-m,i).fst;
				caso2=min(caso2,st2[0].query(i-m,i-m+1).fst);
			}
			if(1){ // caso 1
				caso1=st1[did].query(0,i).fst;
			}
			if(i==n){
				if(did)ans=caso2;
				continue;
			}
			ll cur=min(caso1,caso2);
			if(i==0&&!did)cur=0;
			cout<<i<<" "<<did<<": "<<caso1<<" "<<caso2<<": "<<cur<<"\n";
			if(1){ // upd caso 1
				st1[did].upd(i,{cur,i});
				st1[did].upd(a[i],n,{-a[i],1}); // bigger than ai
				st1[did].upd(0,a[i],{a[i],-1}); // smaller than ai
			}
			if(1){ // upd caso 2
				st2[did].upd(i,{cur,a[i]});
				st2[did].upd(0,i+1,{a[i],-1});
				ll j=a[i]+m;
				pq[did].push({j,i});
				while(SZ(pq[did])&&pq[did].top().fst<=i){
					auto [asd,j]=pq[did].top(); pq[did].pop();
					st2[did].upd(0,j+1,{-2*a[j],2});
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
