#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

typedef ll node;
const ll inf = 1e16;
#define oper min
#define NEUT inf

struct STree{
	int n; vector<node> t;
	STree(int n): n(n), t(2*n+5,NEUT){};
	void upd(int p, node v){
		for(p+=n,t[p] = v;p>1;p>>=1) p^=p&1,t[p>>1]=oper(t[p],t[p^1]);
	}
	node query(int l, int r){
		node izq = NEUT, der = NEUT;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1) izq= oper(izq,t[l++]);
			if(r&1) der = oper(t[--r],der);
		}
		return oper(izq,der);
	}
};


int main(){
	JET
	ll n,k; cin>>n>>k;
	STree st1(n);
	STree st2(n);
	fore(i,0,n){
		ll x; cin>>x;
		st1.upd(i,x);
		st2.upd(i,x+i);
		// cout<<"assab "<<x+i<<"\n";
	}	
	ll r = -NEUT;
	fore(i,0,n){
		ll loc = NEUT;
		loc = min(loc, st1.query(0,max(0ll,i-k+1)));
		// if(i == 5)cout<<loc<<"\n";
		loc = min(loc, st2.query(max(0ll,i-k+1),i+1) - i + k);
		// if(i == 5)cout<<loc<<"\n";
		// if(i == 5) cout<<"debug "<<i-k+1<<" "<<i+1<<" "<<st2.query(i-k+1,i+1)<<"\n";
		loc = min(loc, st1.query(i+1,n));
		// if(i == 5)cout<<loc<<"\n";
		
		r = max(r,loc);
	}
	cout<<r<<"\n";
	return 0;
}