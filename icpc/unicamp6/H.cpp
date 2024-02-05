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

struct STree{
	vector<ll>t; ll n;
	STree(ll n):t(2*n+5,0),n(n){}
	void upd(ll p, ll v){
		for(p+=n,t[p]=v;p>1;p>>=1)t[p>>1]=t[p]+t[p^1];
	}
	ll query(ll l, ll r){
		ll res=0;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)res+=t[l++];
			if(r&1)res+=t[--r];
		}
		return res;
	}
};

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<vector<ll>>a(2,vector<ll>(n)),b(2,vector<ll>(n));
		vector<ll>c(n),d(n);
		fore(h,0,2)fore(i,0,n)cin>>a[h][i];
		fore(h,0,2)fore(i,0,n)cin>>b[h][i];
		map<ii,ll>mp;
		ll k=0;
		fore(i,0,n){
			ii p={b[0][i],b[1][i]};
			if(i&1)swap(p.fst,p.snd);
			if(!mp.count(p))mp[p]=k++;
			d[i]=mp[p];
		}
		ll flag=1;
		fore(i,0,n){
			ii p={a[0][i],a[1][i]};
			if(i&1)swap(p.fst,p.snd);
			if(!mp.count(p))flag=0;
			else c[i]=mp[p];
		}
		if(!flag){
			cout<<"-1\n";
			continue;
		}
		queue<ll>p[k];
		fore(i,0,n)p[c[i]].push(i);
		ll res=0;
		STree st(n);
		fore(i,0,n)st.upd(i,1);
		fore(i,0,n){
			if(!SZ(p[d[i]])){flag=0;break;}
			auto x=p[d[i]].front(); p[d[i]].pop();
			res+=st.query(0,x);
			st.upd(x,0);
		}
		if(flag)cout<<res<<"\n";
		else cout<<"-1\n";
	}
	return 0;
}
