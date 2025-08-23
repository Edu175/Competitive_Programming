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

const ll N=52;
typedef array<ll,N> arr;
typedef arr tn;
typedef arr tl;
arr NEUT;
arr CLEAR;
tn oper(tn a, tn b){
	fore(i,0,N)a[i]+=b[i];
	return a;
}
arr prod(arr a, arr b){ // a is shuffled by per b
	arr c;
	fore(i,0,N)c[i]=a[b[i]];
	return c;
}
void acum(tl &a, tl v){
	a=prod(a,v); // sino al reves
}
tn calc(int s, int e, tn a, tl v){
	assert(s|e|1);
	a=prod(a,v);
	return a;
} 
struct STree{
	vector<tn>st; vector<tl>lazy; int n;
	STree(int n):st(4*n+5,NEUT),lazy(4*n+5,CLEAR),n(n){}
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
	void upd(int a, int b, tl v){upd(1,0,n,a,b,v);}
	tn query(int a, int b){return query(1,0,n,a,b);}
	void init(vector<tn>&a){init(1,0,n,a);}
};
int main(){FIN;
	iota(ALL(CLEAR),0);
	ll t; cin>>t;
	while(t--){
		ll n,q; cin>>n>>q;
		vector<arr> ini(n);
		fore(i,0,n)fore(j,0,N)ini[i][j]=j%13+1;
		STree st(n);
		st.init(ini);
		while(q--){
			ll ty; cin>>ty;
			if(ty==0){ // shuffle
				ll l,r,i,j; cin>>l>>r>>i>>j; r++;
				arr per; iota(ALL(per),0);
				swap(per[i],per[j]);
				st.upd(l,r,per);
			}
			else {
				ll l,r; cin>>l>>r; r++;
				auto rq=st.query(l,r);
				cout<<rq[N-1]<<"\n";
			}
		}
	}
	return 0;
}
