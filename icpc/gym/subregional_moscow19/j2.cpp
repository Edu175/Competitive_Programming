#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b; i<jet; i++)
#define fst first
#define snd second
#define pb push_back
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
const ll MAXN=3e5+5;

vv g[MAXN];
ll ans,cur,tot;
set<ll>a,b;
ll to2(ll n){return n*(n-1)/2;}
void meto(ll x, set<ll> &st){
	auto it=st.upper_bound(x);
	cur-=to2(*it-*prev(it));
	st.insert(x);
	cur+=to2(*it-*prev(it));
	--it;
	cur+=to2(*it-*prev(it));
}
void saco(ll x, set<ll> &st){
	auto it=st.upper_bound(x);
	cur-=to2(*it-*prev(it));
	--it;
	cur-=to2(*it-*prev(it));
	it++;
	st.erase(x);
	cur+=to2(*it-*prev(it));
}

void dfs(ll x, ll fa=-1){
	for(auto y:g[x])if(y!=fa){
		saco(x,b);
		meto(x,a);
		ans+=tot-cur;
		dfs(y,x);
		
	}
}


int main(){
    JET
	ll n; cin>>n;
	a.insert(-1); a.insert(n);
	b.insert(-1); b.insert(n);
    return 0;
}