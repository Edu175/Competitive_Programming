#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oia=b; i<oia;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto messi:v){cout<<messi<<" ";cout<<"\n";}
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

struct STree{
	ll n; vector<ll>t;
	STree(ll n):n(n),t(2*n+5,0){}
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
	//cout<<"scan\n";
	ll n; cin>>n;
	ll a[2*n];
	vector<vector<ll>>p(n);
	fore(i,0,2*n)cin>>a[i],a[i]--,p[a[i]].pb(i);
	//cout<<"d\n";
	vector<pair<ll,ll>>d;
	fore(i,0,n)d.pb({p[i][1]-p[i][0],i});
	sort(ALL(d));
	//cout<<"st\n";
	STree st(2*n);
	fore(i,0,2*n)st.upd(i,1);
	//cout<<"calc\n";
	ll res=0;
	for(auto i:d){
		ll x=i.snd,l=p[x][0],r=p[x][1];
		res+=st.query(l+1,r)+1;
		st.upd(l,0),st.upd(r,0);
	}
	cout<<res<<"\n";
}
