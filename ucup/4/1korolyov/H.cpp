#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){FIN;
	ll n,m,k; cin>>n>>m>>k;
	vector<vv> a(n,vv(k)); // columnas
	fore(i,0,k)fore(j,0,n)cin>>a[j][i];
	fore(i,0,n)sort(ALL(a[i])),reverse(ALL(a[i]));
	vv us(n);
	priority_queue<ii> pq;
	auto put=[&](ll i){
		ll z=SZ(a[i]);
		ll del=z-(k-z);
		pq.push({del,i});
	};
	fore(i,0,n)put(i);
	ll res=k*m;
	while(m&&SZ(pq)){
		auto [del,i]=pq.top(); pq.pop();
		ll dur=a[i].back()-us[i];
		ll q=min(m,dur);
		res-=q*del;
		m-=q;
		us[i]+=q;
		a[i].pop_back();
		put(i);
		// cout<<"uso "<<i<<": "<<del<<" "<<q<<"\n";
	}
	assert(!m);
	assert(res%2==0); res/=2;
	cout<<res<<"\n";
	return 0;
}
