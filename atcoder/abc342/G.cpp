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
typedef set<ii> node;
void oper(node &a, ii v, ll b){
	if(b)a.insert(v);
	else a.erase(v);
}
struct STree{
	int n; vector<node>t;
	STree(int n):n(n),t(2*n+5){}
	ll query(int p){
		ll res=0;
		for(p+=n;p;p>>=1)if(SZ(t[p]))res=max(res,prev(t[p].end())->fst);
		return res;
	}
	void upd(int l, int r, ii v, ll b){
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)oper(t[l++],v,b);
			if(r&1)oper(t[--r],v,b);
		}
	}
};

int main(){FIN;
	ll n; cin>>n;
	vector<ll>a(n);
	fore(i,0,n)cin>>a[i];
	ll q; cin>>q;
	vector<pair<ii,ll>>qs(q);
	STree st(n);
	fore(i,0,q){
		ll t; cin>>t;
		if(t==1){
			ll l,r,v; cin>>l>>r>>v; l--;
			qs[i]={{l,r},v};
			st.upd(l,r,{v,i},1);
		}
		if(t==2){
			ll j; cin>>j; j--;
			st.upd(qs[j].fst.fst,qs[j].fst.snd,{qs[j].snd,j},0);
		}
		if(t==3){
			ll p; cin>>p; p--;
			cout<<max(a[p],st.query(p))<<"\n";
		}
	}
	return 0;
}
