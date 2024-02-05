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

int main(){FIN;
	ll n;
	while(cin>>n){
		stack<ll> a[n];
		ll mn=1e9;
		priority_queue<ii>pq;
		fore(i,0,n){
			ll k; cin>>k;
			fore(j,0,k){
				ll x; cin>>x;
				a[i].push(x);
				mn=min(mn,x);
			}
			pq.push({-a[i].top(),i});
			a[i].pop();
		}
		ll res=0;
		while(1){
			res++;
			auto [x,i]=pq.top(); pq.pop(); x=-x;
			if(x==mn)break;
			if(SZ(a[i])){
				pq.push({-a[i].top(),i});
				a[i].pop();
			}
		}
		cout<<res<<"\n";
	}
	return 0;
}
