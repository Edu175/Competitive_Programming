#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
#pragma GCC optimize("Ofast") // may lead to precision errors

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
const ll MAXN=2e5+5,B=1300;

ii NEUT={0,0};
ii oper(ii a, ii b){return {a.fst+b.fst,a.snd+b.snd};}
struct STree { // persistent segment tree for min over integers
	vector<ii> st;vector<int> L, R; int n,sz,rt;
	STree(int n): st(1,NEUT),L(1,0),R(1,0),n(n),rt(0),sz(1){}
	int new_node(ii v, int l=0, int r=0){
		int ks=SZ(st);
		st.pb(v);L.pb(l);R.pb(r);
		return ks;
	}
	/*int init(int s, int e, int *a){ // not necessary in most cases
		if(s+1==e)return new_node(a[s]);
		int m=(s+e)/2,l=init(s,m,a),r=init(m,e,a);
		return new_node(oper(st[l],st[r]),l,r);
	}*/
	int upd(int k, int s, int e, int p, ii v){
		int ks=new_node(st[k],L[k],R[k]);
		if(s+1==e){st[ks]=oper(st[ks],v);return ks;}
		int m=(s+e)/2,ps;
		if(p<m)ps=upd(L[ks],s,m,p,v),L[ks]=ps;
		else ps=upd(R[ks],m,e,p,v),R[ks]=ps;
		st[ks]=oper(st[L[ks]],st[R[ks]]);
		return ks;
	}
	ii query(int k, int s, int e, int a, int b){
		if(e<=a||b<=s)return NEUT;
		if(a<=s&&e<=b)return st[k];
		int m=(s+e)/2;
		return oper(query(L[k],s,m,a,b),query(R[k],m,e,a,b));
	}
	//int init(int *a){return init(0,n,a);}
	int upd(int k, int p, ii v){return rt=upd(k,0,n,p,v);}
	int upd(int p, ii v){return upd(rt,p,v);} // update on last root
	ii query(int k,int a, int b){return query(k,0,n,a,b);};
}; // usage: STree rmq(n);root=rmq.init(x);new_root=rmq.upd(root,i,v);rmq.query(root,s,e);
STree st(MAXN);
vector<ll>rts={st.rt};
ii operator-(ii a, ii b){return {a.fst-b.fst,a.snd-b.snd};}
/*string cv(ii i){
	return to_string(i.fst)+","+to_string(i.snd);
}*/
ii query(ll l, ll r, ll s, ll e){
	/*ii rhs=st.query(rts[r],s,e);
	ii lhs=st.query(rts[l],s,e);
	ii rq=rhs-lhs;*/
	/*if(s<100){
		cout<<"query "<<l<<","<<r<<" "<<s<<","<<e<<": "<<cv(rq)<<"\n";
		cout<<rts[l]<<","<<rts[r]<<"\n";
		cout<<cv(lhs)<<" "<<cv(rhs)<<"\n";
		cout<<"l: ";
		fore(i,0,20)cout<<"["<<i<<"] "<<cv(st.query(rts[l],i,i+1))<<" ";;cout<<"\n";
		cout<<"r: ";
		fore(i,0,20)cout<<"["<<i<<"] "<<cv(st.query(rts[r],i,i+1))<<" ";;cout<<"\n";
		
	}*/
	return st.query(rts[r],s,e)-st.query(rts[l],s,e);
}
int main(){FIN;
	ll n,q; cin>>n>>q;
	vector<ll>a(n);
	fore(i,0,n)cin>>a[i];
	//imp(a);
	fore(i,0,n)rts.pb(st.upd(st.rt,a[i],{a[i],1}));
	//imp(rts);
	vector<int>sp[B];
	fore(x,1,B){
		sp[x].resize(n+1);
		fore(i,1,n+1)sp[x][i]=sp[x][i-1]+a[i-1]%x;
	}
	while(q--){
		ll l,r,x; cin>>l>>r>>x; l--;
		//cout<<"\n l r x "<<l<<","<<r<<" "<<x<<"\n";
		if(x<B)cout<<sp[x][r]-sp[x][l]<<" ";
		else {
			ll res=0;
			for(ll s=0;s<MAXN;s+=x){
				ll e=min(MAXN,s+x);
				ii rq=query(l,r,s,e);
				res+=rq.fst-s*rq.snd;
			}
			cout<<res<<" ";
		}
	}
	cout<<"\n";
	return 0;
}
