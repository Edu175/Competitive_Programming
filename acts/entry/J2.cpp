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

typedef ll node;
#define oper max
#define NEUT 0
struct STree{
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

int main(){FIN;
	ll n; cin>>n;
	vector<pair<ii,ll>>a(n);
	fore(i,0,n){
		ll ai,ci; cin>>ai>>ci; ai--;
		a[i]={{ai,ci},i};
	}
	sort(ALL(a)); reverse(ALL(a));
	vector<pair<ii,ll>>res;
	STree st(n);
	for(auto [par,i]:a){
		auto [v,c]=par;
		ll x=max(st.query(0,i),i-c);
		st.upd(i,x);
		res.pb({{x,-v},i});
		cout<<v<<" "<<i<<": "<<x<<"\n";
	}
	sort(ALL(res));
	for(auto i:res)cout<<-i.fst.snd+1<<" ";;cout<<"\n";
	return 0;
}
