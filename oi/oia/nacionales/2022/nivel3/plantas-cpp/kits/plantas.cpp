#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" ";cout<<"\n"
using namespace std;
typedef long long ll;
#define oper +
#define NEUT 0
struct STree{
	vector<ll>st;ll n;
	STree(ll n): st(4*n+5,NEUT), n(n) {}
	void upd(ll k, ll s, ll e, ll p, ll v){
		if(s+1==e){st[k]=v;/*cout<<k<<"="<<p<<"\n";*/return;}
		ll m=(s+e)/2;
		if(p<m)upd(2*k,s,m,p,v);
		else upd(2*k+1,m,e,p,v);
		st[k]=(st[2*k]+st[2*k+1]);
	}
	ll query(ll k, ll s, ll e, ll a, ll b){
		if(s>=b||e<=a)return NEUT;
		if(a<=s&&e<=b)return st[k];
		ll m=(s+e)/2;
		return (query(2*k,s,m,a,b)+query(2*k+1,m,e,a,b));
	}
	void upd(ll p, ll v){upd(1,0,n,p,v);}
	ll query(ll a, ll b){return query(1,0,n,a,b);}
};

long long plantas(vector<int> &a) {
    ll n=SZ(a);
    ll p[n];
    fore(i,0,n)a[i]--,p[a[i]]=i;
    ll res=0;
    STree st(n);
    fore(i,0,n)st.upd(i,1);
    //imp(st.st);
    //vector<ll>pos={4,5,6,14,15};
    fore(i,0,n){
    	/*for(auto i:pos){
			cout<<st.st[i]<<" ";
		}
		cout<<"\n";*/
    	res+=min(st.query(0,p[i]),st.query(p[i]+1,n));
    	//cout<<i<<" "<<p[i]<<": "<<"l="<<st.query(0,p[i])<<" r="<<st.query(p[i]+1,n)<<"\n";
    	st.upd(p[i],0);
    }
    return res;
}
