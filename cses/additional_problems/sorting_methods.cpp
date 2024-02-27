#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef ll node;
node oper(node a, node b){return a+b;}
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
	vector<ll>a(n),p(n);
	fore(i,0,n)cin>>a[i],a[i]--,p[a[i]]=i;
	STree st(n);
	fore(i,0,n)st.upd(i,1);
	vector<ll>res(4);
	fore(i,0,n){
		res[0]+=st.query(0,p[i]);
		st.upd(p[i],0);
	}
	vector<ll>vis(n);
	fore(i,0,n)if(!vis[i]){
		res[1]++;
		for(ll x=i;!vis[x];x=a[x])vis[x]=1;
	}
	res[1]=n-res[1];
	vector<ll>v;
	fore(i,0,n){
		ll lwb=lower_bound(ALL(v),a[i])-v.begin();
		if(lwb>=SZ(v))v.pb(a[i]);
		else v[lwb]=a[i];
	}
	res[2]=n-SZ(v);
	ll x=n-1;
	for(ll i=n-1;i>=0;i--){
		if(a[i]==x)x--;
	}
	res[3]=x+1;
	imp(res);
	return 0;
}

