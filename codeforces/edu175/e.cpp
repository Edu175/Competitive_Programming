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

typedef ll node;
node oper(node a, node b){return a+b;}
#define NEUT 0
struct STree{
	int n; vector<node>t;
	STree(int n):n(n),t(2*n+5,NEUT){}
	void upd(int p, node v){
		for(p+=n,t[p]=oper(t[p],v);p>1;p>>=1)p^=p&1,t[p>>1]=oper(t[p],t[p^1]);
	}
	node query(int l, int r){
		node izq=NEUT,der=NEUT;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)izq=oper(izq,t[l++]);
			if(r&1)der=oper(t[--r],der);
		}
		return oper(izq,der);
	}
};

ll algo(ll r){
	return (r==1||r==2)-3*(r==2||r==3);
}

int main(){FIN;
	ll n; cin>>n;
	string s; cin>>s;
	vv difs(n+1);
	ll dif=0;
	fore(i,0,n){
		if(s[i]=='1')dif-=3;
		else dif++;
		difs[i+1]=dif;
	}
	vv vals;
	for(auto i:difs)fore(a,-3,2)vals.pb(i+a);
	sort(ALL(vals));
	vals.resize(unique(ALL(vals))-vals.begin());
	// imp(vals)
	auto get_idx=[&](ll v){return lower_bound(ALL(vals),v)-vals.begin();};
	vector<STree> st(4,STree(SZ(vals)));
	ll ans=0;
	for(ll i=n;i>=0;i--){
		ll res=0;
		fore(j,0,4){
			ll r=((j-i)%4+4)%4;
			res+=st[j].query(get_idx(difs[i]+algo(r))+1,st[j].n);
		}
		st[i%4].upd(get_idx(difs[i]),1);
		ans+=res;
	}
	cout<<ans<<"\n";
	return 0;
}
