#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,acts=b;i<acts;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto sdf:v)cout<<sdf<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
struct STree{
	vector<ll>t; int n;
	STree2(int n):t(2*n+5,0),n(n){}
	void upd(int p, ll v){
		for(p+=n,t[p]+=v;p>1;p>>=1)
			t[p>>1]=t[p]+t[p^1];
	}
	ll query(int l, int r){
		ll res=0;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1)res+=t[l++];
			if(r&1)res+=t[--r];
		}
		return res;
	}
};
const ll MAXN=5e5+5;
ll badl[MAXN],badr[MAXN];
int main(){FIN;
	ll n,q; cin>>n>>q;
	vector<ll>a(n),h(n),b;
	fore(i,0,n)cin>>a[i]>>h[i],b.pb({h[i],i});
	vector<ll>l(n),r(n); //[]
	fore(i,0,n){
		if(a[i]-h[i]<a[0])badl[i]=1;
		l[i]=upper_bound(ALL(a),a[i]-h[i])-a.begin();
		if(a[i]+h[i]>a[n-1])badr[i]=1;
		r[i]=lower_bound(ALL(a),a[i]+h[i])-a.begin()-1;
	}
	sort(ALL(b)); reverse(ALL(b));
	STree st(n);
	for(auto [sddf,i]:b){
		if(st.query(l[i],i))badl[i]=1;
		if(st.query(i,r[i]))badr[i]=1;
		st.upd(i,1);
	}
	reverse(ALL(b));
	st=STree(n);
	for(auto [sddf,i]:b){
		if(st.query(l[i],r[i]+1))bad[i]=1;
		st.upd(i,bad[i]);
	}
	while(q--){
		ll s,e; cin>>s>>e;
		
	}
	return 0;
}
