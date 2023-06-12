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
const ll INF=1e10;
struct node{
	ll h[2][2]={};
	node(ll v): h() {h[0][0]=0,h[1][1]=v,h[0][1]=v,h[1][0]=v;}
	node(){}
};
node NEUT;
node oper(node a, node b){
	if(a.h[0][0]==-1)return b;
	if(b.h[0][0]==-1)return a;
	node res;
	fore(i,0,2)fore(j,0,2){
		res.h[i][j]=min(a.h[i][0]+b.h[1][j],a.h[i][1]+b.h[0][j]);
	}
	return res;
}
struct STree{
	ll n; vector<node>t;
	STree(ll n):n(n),t(2*n+5,NEUT){}
	void init(vector<ll>&a){
		assert(SZ(a)>=n);
		fore(i,0,n)t[i+n]=node(a[i]);
		for(ll s=1ll<<(64-__builtin_clzll(n)),e=2*n;s>1;s>>=1,e=s<<1){
			for(ll i=s;i<e;i+=2)t[i>>1]=oper(t[i],t[i^1]);
		}
	}
	void upd(ll p, ll v){
		for(p+=n,t[p]=node(v);p>1;p>>=1)t[p>>1]=oper(t[p],t[p^1]);
	}
	node query(ll l, ll r){
		node res=NEUT;
		vector<node>opl,opr;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)opl.pb(t[l++]);//res=oper(res,t[l++]);
			if(r&1)opr.pb(t[--r]);//res=oper(res,t[--r]);
		}
		reverse(ALL(opr));
		for(auto i:opl)res=oper(res,i); 
		for(auto i:opr)res=oper(res,i);
		return res;
	}
};

void print(node x){
	fore(i,0,2)fore(j,0,2)cout<<"["<<i<<" "<<x.h[i][j]<<" "<<j<<"] ";
	cout<<"\n";
}
int main(){FIN;
	mset(NEUT.h,-1);
	ll n; cin>>n; n--;
	vector<ll> a(n);
	fore(i,0,n)cin>>a[i];
	/*fore(i,0,n){
		cout<<a[i]<<" "<<a[i+1]<<": ";
		print(oper(node(a[i]),node(a[i+1])));
	}*/
	STree st(n);
	//st.init(a);
	fore(i,0,n)st.upd(i,a[i]);
	//print(st.query(0,n));
	ll q; cin>>q;
	while(q--){
		//cout<<q<<": ";
		ll p,v; cin>>p>>v; p--;
		st.upd(p,v);
		node res=st.query(0,n);
		//print(st.query(0,n));
		cout<<2*res.h[1][1]<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
