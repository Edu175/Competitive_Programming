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
const ll MOD=1e9+7;

typedef ll node;
inline ll cut(ll a){return a<MOD?a:a-MOD;}
node oper(node a, node b){return cut(a+b);}
#define NEUT 0
struct STree{
	int n; vector<node>t;
	STree(int n):n(n),t(2*n+5,NEUT){}
	void upd(int p, ll v){
		for(p+=n,t[p]=oper(t[p],v);p>1;p>>=1)t[p>>1]=oper(t[p],t[p^1]);
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
	vector<ll>a(n),cmp,id;
	fore(i,0,n)cin>>a[i],cmp.pb(a[i]);
	sort(ALL(cmp));
	for(auto i:cmp)if(!SZ(id)||i!=id.back())id.pb(i);
	fore(i,0,n)a[i]=lower_bound(ALL(id),a[i])-id.begin();
	STree st(n);
	for(ll i=n-1;i>=0;i--){
		ll v=cut(st.query(a[i]+1,n)+1);
		//cout<<i<<" "<<a[i]<<": "<<v<<"\n";
		st.upd(a[i],v);
	}
	cout<<st.query(0,n)<<"\n";
	return 0;
}

