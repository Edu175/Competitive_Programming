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

#define oper max
#define NEUT 0
struct STree{
	int n; vector<ll>t;
	STree(int n):n(n),t(2*n+5,NEUT){}
	void upd(int p, ll v){
		for(p+=n,t[p]=v;p>1;p>>=1)t[p>>1]=oper(t[p],t[p^1]);
	}
	ll query(int l, int r){
		ll res=NEUT;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)res=oper(res,t[l++]);
			if(r&1)res=oper(res,t[--r]);
		}
		return res;
	}
};

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		vector<ll>a(n),b(m);
		map<ll,ll>id;
		fore(i,0,n)cin>>a[i],id[a[i]]=-1;
		fore(i,0,m)cin>>b[i],id[b[i]]=-1;
		vector<ll>pos;
		ll k=0;
		for(auto &i:id)i.snd=k,pos.pb(i.fst),k++;
		fore(i,0,n)a[i]=id[a[i]];
		fore(i,0,m)b[i]=id[b[i]];
		sort(ALL(b)); reverse(ALL(b));
		STree st(k);
		ll p=0,lis=0;
		fore(i,0,n){
			ll x=st.query(0,a[i]),y=st.query(a[i],a[i]+1);
			ll v=max(x+1,y);
			st.upd(a[i],v);
			if(v>lis)p=i,lis=v;
			else if(v==lis){
				if(a[i]<a[p])p=i;
			}
		}
		//cout<<p<<" "<<lis<<"\n";	
		vector<ll>res;
		ll po=m;
		fore(j,0,m){
			if(a[p]>=b[j]){
				po=j;
				break;
			}
			res.pb(b[j]);
		}
		fore(i,0,n)res.pb(a[i]);
		fore(i,po,m)res.pb(b[i]);
		for(auto i:res){
			cout<<pos[i]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
