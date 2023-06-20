#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
#define pres cout<<res<<"\n"
using namespace std;
typedef long long ll;

struct node{
	ll x,y;
	node(ll v):x(v),y(0){}
	node(ll x0, ll y0):x(x0),y(y0){}
	node(){}
};
node oper(node a, node b){
	vector<ll>v={a.x,a.y,b.x,b.y};
	sort(ALL(v));
	return node(v[3],v[2]);
}
node NEUT=node(0);

struct STree{
	vector<node>st;int n;
	STree(int n0): st(4*n0+5,NEUT), n(n0) {}
	void init(int k, int s, int e, vector<node> &a){
		if(s+1==e){st[k]=a[s];return;}
		int m=(s+e)/2;
		init(2*k,s,m,a);init(2*k+1,m,e,a);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	void upd(int k, int s, int e, int p, node v){
		if(s+1==e){st[k]=v;return;}
		int m=(s+e)/2;
		if(p<m)upd(2*k,s,m,p,v);
		else upd(2*k+1,m,e,p,v);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	node query(int k, int s, int e, int a, int b){
		if(s>=b||e<=a)return NEUT;
		if(a<=s&&e<=b)return st[k];
		int m=(s+e)/2;
		return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
	}
	void init(vector<node> &a){init(1,0,n,a);}
	void upd(int p, node v){upd(1,0,n,p,v);}
	node query(int a, int b){return query(1,0,n,a,b);}
};// uso: STree name(n);name.init(a);name.upd(i,v);name.query(s,e);	

int main(){FIN;
	ll n; cin>>n;
	vector<ll> a(n);
	fore(i,0,n)cin>>a[i];
	vector<node>b(n);
	fore(i,0,n)b[i]=node(a[i]);
	STree st(n);
	st.init(b);
	ll q; cin>>q;
	while(q--){
		char ty; cin>>ty;
		if(ty=='U'){
			ll p,v; cin>>p>>v; p--;
			st.upd(p,node(v));
		}
		else {
			ll l,r; cin>>l>>r; l--;
			node re=st.query(l,r);
			cout<<re.x+re.y<<"\n";
		}
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
