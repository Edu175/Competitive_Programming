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
const ll MAXN=1e5+5;
unordered_map<ll,ll> ft[MAXN+1];
ll n;
void upd(int i0, int j0, int v){
	i0=n-1-i0;
	for(int i=i0+1;i<=MAXN;i+=i&-i)
	for(int j=j0+1;j<=MAXN;j+=j&-j)
		ft[i][j]+=v;
}
int get(int i0, int j0){
	i0=n-1-i0;
	int r=0;
	for(int i=i0;i;i-=i&-i)
	for(int j=j0;j;j-=j&-j)
		r+=ft[i][j];
	return r;
}
/*int get_sum(int i0, int j0, int i1, int j1){
	return get(i1,j1)-get(i1,j0)-get(i0,j1)+get(i0,j0);
}*/

int main(){FIN;
	cin>>n;
	vector<pair<ii,ll>>a(n);
	fore(i,0,n){
		ll ai,ci; cin>>ai>>ci; ai--;
		a[i]={{ai,ci},i};
	}
	sort(ALL(a)); reverse(ALL(a));
	vector<ll>res(n);
	STree st(n);
	for(auto [par,i]:a){
		auto [v,c]=par;
		ll nx=max(st.query(0,i),i-c);
		ll x=nx+get(i,nx+1);
		res[v]=x;
		st.upd(i,x);
		upd(i,x,1);
		cout<<v<<" "<<i<<": "<<nx<<" "<<x<<"\n";
	}
	vector<ll>b(n);
	fore(i,0,n)b[res[i]]=i+1;
	imp(b);
	return 0;
}
