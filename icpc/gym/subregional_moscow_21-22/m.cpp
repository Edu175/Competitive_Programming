#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b;i<jet;i++)
#define pb push_back
#define fst first
#define snd second 
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ld EPS=1e-9;



ld eval(vector<ld> d){
	ll n=SZ(d);
	assert(n>0);
	vector<ld> dp(n);
	dp[n-1]=d[n-1];
	for(ll i=n-2;i>=0;i--){
		auto sal=[&](ld t){
			return d[i]/t+dp[i+1]*(1/(1-t));
		};
		ld l=0,r=1;
		ll it=70;
		while(it--){
			ld ter=(r-l)/3;
			ld m0=l+ter,m1=l+2*ter;
			if(sal(m0)<sal(m1))r=m1;
			else l=m0;
		}
		dp[i]=sal(l);
	}
	return dp[0];
}
ld eval(vector<ld> d, ld t){
	return eval(d)*1/t;
}
ll n;

vector<ii>

vector<ld> dijkstra(){
	vector<ld>d(n);
	vector<ll> vis(n);
	priority_queue<ii>pq;
	d[0]=0;
	while(SZ(pq)){
		auto [dis,x]=pq.top(); dis=-dis;
		if(d[x]<dis)continue;
		for(auto y:g[x])
	}
}

#define NEUT 1e15

typedef ll node;
node oper(node a, node b){ return min(a,b);}


struct STree{
	int n; vector<node> t;	
	STree(int n): n(n),t(2*n+5,NEUT){}
	void upd(int p, node v){
		for(p+=n,t[p]=v;p>1;p>>=1)p^=p&1,t[p>>1]=oper(t[p],t[p^1]);
	}
	node query(int l, int r){
		node izq = NEUT, der =NEUT;
		for(l+=n,r+=n;l<r;l>>=1,r>>=1){
			if(l&1) izq = oper(izq,t[l++]);
			if(r&1) der = oper(der,t[--r]);
		}
		return oper(izq,der);
	}
};

int main(){
	JET
		
}