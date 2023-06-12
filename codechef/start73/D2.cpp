#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define fore(i,a,b) for(ll i=a,oia=b;i<oia;i++)
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto lol:v)cout<<lol<<" ";cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
#define oper max
ii NEUT={0,-1};

struct STree{
	vector<ii>st;ll n;
	STree(ll n): st(4*n+5,NEUT), n(n) {}
	void upd(ll k, ll s, ll e, ll p, ii v){
		if(e-s==1){st[k]=v;return;}
		ll m=(s+e)/2;
		if(p<m)upd(2*k,s,m,p,v);
		else upd(2*k+1,m,e,p,v);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	ii query(ll k, ll s, ll e, ll a, ll b){
		if(s>=b||e<=a)return NEUT;
		if(a<=s&&e<=b)return st[k];
		ll m=(s+e)/2;
		return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
	}
	void upd(ll p, ii v){upd(1,0,n,p,v);}
	ii query(ll a, ll b){return query(1,0,n,a,b);}
};


int main(){
	ll t; cin>>t;
	while(t--){
		ll n,m,k; cin>>n>>m>>k;
		vector<pair<pair<ll,ll>,ll>> a(k);
		fore(i,0,k){
			cin>>a[i].fst.fst>>a[i].fst.snd;
			a[i].fst.fst=n-a[i].fst.fst;
			a[i].fst.snd=m-a[i].fst.snd;
			a[i].fst.snd*=(-1);
			a[i].snd=i;
		}
		sort(ALL(a));
		vector<pair<ll,ll>>b;
		for(auto& i:a){
			i.fst.snd*=(-1);
		}
		ll mel=0;
		for(auto i:b)mel=max(mel,i.fst);
		/*for(auto i:b){
			cout<<i.fst<<","<<i.snd<<" ";
		}
		cout<<"\n";*/
		STree st(mel+5);
		ll p[k],lis[k];
		mset(p,-1);
		mset(lis,0);
		for(auto i:b){
			ii ri=st.query(0,i.fst);
			lis[i.snd]=ri.fst+1;
			p[i.snd]=ri.snd;
			st.upd(i.fst,{ri.fst+1,i.snd});
		}
		ll maxi=0, x=-1;
		fore(i,0,k){
			if(lis[i]>maxi)maxi=lis[i],x=i;
		}
		vector<ll>res;
		while(x!=-1){
			res.pb(x+1);
			x=p[x];
		}
		reverse(ALL(res));
		/*fore(i,0,SZ(st.st)){
			ii j=st.st[i];
			cout<<i<<": "<<j.fst<<","<<j.snd<<"\n";
		}*/
		//imp(lis);
		//imp(p);
		assert(maxi==SZ(res));
		cout<<maxi/*<<" "<<SZ(res)*/<<"\n";
	}
	return 0;
}
