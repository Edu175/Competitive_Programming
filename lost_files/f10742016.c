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

ii operator*(ii p,ll v){return {p.fst*v,p.snd*v};}
ii operator*(ll v,ii p){return {p.fst*v,p.snd*v};}
ii operator+(ii p,ii q){return {p.fst+q.fst,p.snd+q.snd};}
ii operator+=(ii &p,ii q){return p=p+q;}
ii z={0,0};
struct STree { // example: range sum with range addition
	vector<ii> st,lazy;int n;
	STree(int n): st(4*n+5,z), lazy(4*n+5,z), n(n) {}
	STree(){};
	/*void init(int k, int s, int e, int *a){
		lazy[k]=z;  // lazy neutral element
		if(s+1==e){st[k]=a[s];return;}
		int m=(s+e)/2;
		init(2*k,s,m,a);init(2*k+1,m,e,a);
		st[k]=st[2*k]+st[2*k+1]; // operation
	}*/
	void push(int k, int s, int e){
		if(lazy[k]==z)return; // if neutral, nothing to do
		st[k]+=(e-s)*lazy[k]; // update st according to lazy
		if(s+1<e){ // propagate to children
			lazy[2*k]+=lazy[k];
			lazy[2*k+1]+=lazy[k];
		}
		lazy[k]=z; // clear node lazy
	}
	void upd(int k, int s, int e, int a, int b, ii v){
		push(k,s,e);
		if(s>=b||e<=a)return;
		if(s>=a&&e<=b){
			lazy[k]+=v; // accumulate lazy
			push(k,s,e);return;
		}
		int m=(s+e)/2;
		upd(2*k,s,m,a,b,v);upd(2*k+1,m,e,a,b,v);
		st[k]=st[2*k]+st[2*k+1]; // operation
	}
	ii query(int k, int s, int e, int a, int b){
		if(s>=b||e<=a)return z; // operation neutral
		push(k,s,e);
		if(s>=a&&e<=b)return st[k];
		int m=(s+e)/2;
		return query(2*k,s,m,a,b)+query(2*k+1,m,e,a,b); // operation
	}
	//void init(int *a){init(1,0,n,a);}
	void upd(int a, int b, ii v){upd(1,0,n,a,b,v);}
	ii query(int a, int b){return query(1,0,n,a,b);}
}; // usage: STree rmq(n);rmq.init(x);rmq.upd(s,e,v);rmq.query(s,e);



int main(){FIN;
	ll n,m; cin>>n>>m;
	ll s=0;
	if(n>m)swap(n,m),s=1;
	char g[n][m];
	if(s){
		fore(j,0,m){
			fore(i,0,n)cin>>g[i][j];
		}
		/*fore(i,0,n){
			fore(j,0,m)cout<<g[i][j];
			cout<<"\n";
		}*/
	}
	else{
		fore(i,0,n){
			fore(j,0,m)cin>>g[i][j];
		}
	}
	STree st(n*m);
	fore
	ll q; cin>>q;
	fore(t,0,q){
		ll a,b; cin>>a>>b; a--,b--;
		if(s)swap(a,b);
		ll v=1; if((t&1)==0)v=-1;
		ii p0={a,b},p1={a,b+m},p2={a+n,b},p3={a+n,b+m};
		cout<<"0,0 "<<a<<","<<b<<": += "<<(p0*v).fst<<","<<(p0*v).snd<<"\n";
		cout<<0<<","<<b+1<<" "<<a<<","<<m-1<<": += "<<(p1*v).fst<<","<<(p1*v).snd<<"\n";
		cout<<a+1<<","<<0<<" "<<n-1<<","<<a<<": += "<<(p2*v).fst<<","<<(p2*v).snd<<"\n";
		cout<<a+1<<","<<b+1<<" "<<n-1<<","<<m-1<<": += "<<(p3*v).fst<<","<<(p3*v).snd<<"\n";
		fore(i,0,a+1){
			st.upd(m*i,m*i+b+1,p0*v);
			st.upd(m*i+b+1,m*(i+1),p1*v);
		}
		fore(i,a+1,n){
			st.upd(m*i,m*i+b+1,p2*v);
			st.upd(m*i+b+1,m*(i+1),p3*v);
		}
	}
	char res[n][m];
	fore(i,0,n){
		fore(j,0,m){
			ii p={i,j};
			p+=st.query(i*m+j,i*m+j+1);
			if(q&1)p=p*-1;
			res[p.fst][p.snd]=g[i][j];
			cout<<i<<","<<j<<": "<<p.fst<<","<<p.snd<<"\n";
		}
	}
	if(s){
		fore(j,0,m){
			fore(i,0,n)cout<<res[i][j];
			cout<<"\n";
		}
	}
	else{
		fore(i,0,n){
			fore(j,0,m)cout<<res[i][j];
			cout<<"\n";
		}
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
