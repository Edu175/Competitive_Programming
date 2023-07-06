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
const ll MAXN=2e5+5;

ll a[MAXN],b[MAXN];
bool comp(ll i, ll j){
	ii c={a[i],a[i]+b[i]},d={a[j],a[j]+b[j]};
	if(c.fst*d.snd>d.fst*c.snd)return 1;
	else if(c.fst*d.snd==d.fst*c.snd)return i<j;
	else return 0;
}

int main(){FIN;
	ll n; cin>>n;
	vector<ll>p;
	fore(i,0,n)cin>>a[i]>>b[i],p.pb(i);
	sort(ALL(p),comp);
	for(auto i:p){
		cout<<i+1<<" ";
	}
	cout<<"\n";
	return 0;
}
