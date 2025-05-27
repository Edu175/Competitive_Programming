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
const ll INF=1e6;
struct STree{
	typedef ll node;
	#define NEUT -INF
	ll oper(ll a, ll b){return max(a,b);}
	int n; vector<node>t;
	STree(int n):n(n),t(2*n+5,NEUT){}
	void upd(int p, node v){
		for(p+=n,t[p]=v;p>1;p>>=1)t[p>>1]=oper(t[p],t[p^1]);
	}
	node query(int l, int r){
		node res=NEUT;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)res=oper(res,t[l++]);
			if(r&1)res=oper(res,t[--r]);
		}
		return res;
	}
};

ll get(ll d){ // d es <= 0, min +2 para que d>0
	d=-d;
	return d/2+1;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,q; cin>>n>>q;
		string s; cin>>s;
		vv as(n),bs(n),d(n);
		STree st(n);
		set<ll>se;
		fore(i,0,n){
			if(i)as[i]=as[i-1],bs[i]=bs[i-1];
			(s[i]=='A'?as:bs)[i]++;
			if(s[i]=='A')se.insert(i);
			d[i]=as[i]-bs[i];
			st.upd(i,d[i]);
		}
		se.insert(n);
		// imp(d)
		while(q--){
			ll l,r; cin>>l>>r; l--;
			ll fa=*se.lower_bound(l); // first a
			if(fa>=r){cout<<"-1\n";continue;}
			ll mx=st.query(fa,r)-(l?d[l-1]:0);
			
			ll dif=d[r-1]-(l?d[l-1]:0);
			// ll ca=as[r-1]-(l?as[l-1]:0);
			// ll cb=bs[r-1]-(l?bs[l-1]:0);
			// cerr<<fa<<": "<<dif<<" "<<mx<<"\n";
			// siempre se puede ahora
			if(dif>0){cout<<"0\n";continue;}
			if(mx>0){
				cout<<get(dif)<<"\n";
				continue;
			}
			ll res=-mx+1; dif+=res;
			if(dif>0){cout<<res<<"\n";continue;}
			cout<<res+get(dif)<<"\n";
		}
	}
	return 0;
}