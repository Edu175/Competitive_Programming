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

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		ll a[n],c[m];
		vector<ll>oc(n,0);
		fore(i,0,n)cin>>a[i],a[i]--,oc[a[i]]++;
		fore(i,0,m)cin>>c[i];
		priority_queue<ll>p,q;
		fore(i,0,n)p.push(oc[i]);
		fore(i,0,m)q.push(c[i]);
		ll res=0;
		while(SZ(q)){
			//cout<<p.top()<<" "<<q.top()<<"\n";
			ll r=min(p.top(),q.top());
			res+=r;
			ll x=p.top();
			q.pop(),p.pop();
			p.push(x-r);
		}
		cout<<res<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
