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

#define oper max
#define NEUT 0
struct STree{
	vector<ll>st;ll n;
	STree(ll n): st(4*n+5,NEUT), n(n) {}
	void init(ll k, ll s, ll e, ll *a){
		if(s+1==e){st[k]=a[s];return;}
		ll m=(s+e)/2;
		init(2*k,s,m,a);init(2*k+1,m,e,a);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	void upd(ll k, ll s, ll e, ll p, ll v){
		if(s+1==e){st[k]=v;return;}
		ll m=(s+e)/2;
		if(p<m)upd(2*k,s,m,p,v);
		else upd(2*k+1,m,e,p,v);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	ll query(ll k, ll s, ll e, ll a, ll b){
		if(s>=b||e<=a)return NEUT;
		if(a<=s&&e<=b)return st[k];
		ll m=(s+e)/2;
		return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
	}
	void init(ll *a){init(1,0,n,a);}
	void upd(ll p, ll v){upd(1,0,n,p,v);}
	ll query(ll a, ll b){return query(1,0,n,a,b);}
};// uso: STree name(n);name.init(a);name.upd(i,v);name.query(s,e);	

int main(){FIN;
	ll n; cin>>n;
	set<ll>row,col;
	vector<ll> q[n];
	fore(_,0,n){
		ll i,j,x; cin>>i>>j>>x; i--,j--;
		row.insert(i),col.insert(j);
		q[_]={i,j,x};
	}
	map<ll,ll>idr,idc;
	ll j=0;
	for(auto i:row)idr[i]=j,j++;
	j=0;
	for(auto i:col)idc[i]=j,j++;
	map<pair<ll,ll>,ll>a;
	ll sumr[n],sumc[n]; mset(sumr,0);mset(sumc,0);
	vector<ll>pos[n];
	fore(_,0,n){
		ll i=idr[q[_][0]],j=idc[q[_][1]],x=q[_][2];
		a[{i,j}]=x;
		sumr[i]+=x;
		sumc[j]+=x;
		pos[i].pb(j);
	}
	STree st(n);
	fore(i,0,n)st.upd(i,sumc[i]);
	ll res=0;
	fore(i,0,n){
		ll s=0;
		//cout<<i<<": "<<sumr[i]<<"\n";
		for(auto j:pos[i]){
			res=max(res,sumr[i]+sumc[j]-a[{i,j}]);
			//cout<<j<<": "<<sumc[j]-a[{i,j}]<<" "<<a[{i,j}]<<" | "<<st.query(s,j)<<"="<<sumr[i]+st.query(s,j);
			res=max(res,sumr[i]+st.query(s+1,j));
			s=j;
		}
		res=max(res,sumr[i]+st.query(s+1,n));
	}
	cout<<res<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
