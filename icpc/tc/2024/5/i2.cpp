#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b; i<jet;i++)
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(s) ((ll)s.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const int maxn=1e5+5;
const int INF=1e6+10;

typedef ll node;
node oper(node a, node b){return min(a,b);}
#define NEUT 1e14
struct STree{
	int n; vector<node>t;
	STree(int n):n(n),t(2*n+5,NEUT){}
	void upd(int p, node v){
		for(p+=n,t[p]=v;p>1;p>>=1) t[p>>1]=oper(t[p],t[p^1]);
	}
	node query(int x){
		if (t[1]>=x) return INF;
		int i=1;
		while(i<n){
			if(t[i*2]<x) i=i*2;
			else i=i*2+1;
		}
		return i-n;
	}
};

int main(){
	JET
	ll n; cin>>n;
	ll a[n];
	ii g={0,-1};
	fore(i,0,n){
		cin>>a[i];
		g=max(g,{a[i],i});
	}
	STree st(1<<18);
	ll rta[n];
	fore(i,0,n) st.upd(i,a[i]);
	fore(i,0,n){
		st.upd(i,NEUT);
		st.upd(i+n,a[i]);
		ll x=st.query((a[i]+1)/2);
		rta[i]=x-i;
	}
	int i=g.snd;
	if(rta[i]>=3*maxn){
		fore(i,0,n) cout<<-1<<" ";
		cout<<"\n";
		return 0;
	}
	i--;
	if(i<0) i+=n;
	while(i!=g.snd){
		rta[i]=min(rta[(i+1)%n]+1,rta[i]);
		i--;
		if(i<0) i+=n;
	}
	fore(i,0,n) cout<<rta[i]<<" ";
	cout<<"\n";
}