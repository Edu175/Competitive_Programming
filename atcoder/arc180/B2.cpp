#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll n,k; cin>>n>>k;
	vector<ll>a(n);
	fore(i,0,n)cin>>a[i],a[i]--;
	set<pair<ll,ii>>st;
	queue<ii> dis[n];
	
	auto in=[&](ll i){
		fore(j,0,i-k+1)if(a[j]>a[i])dis[a[j]-a[i]].push({j,i});
		fore(j,i+k,n)if(a[i]>a[j])dis[a[i]-a[j]].push({i,j});
	};
	fore(i,0,n)in(i);
	vector<ii>res;
	while(1){
		ll x=-1,y=-1;
		fore(d,1,n){
			while(SZ(dis[d])){
				auto [i,j]=dis[d].front(); dis[d].pop();
				if(a[i]-a[j]!=d)continue;
				x=i,y=j;
				break;
			}
			if(x!=-1)break;
		}
		if(x==-1)break;
		res.pb({x,y});
		swap(a[x],a[y]);
		in(x); in(y);
	}
	cout<<SZ(res)<<"\n";
	for(auto i:res)cout<<i.fst+1<<" "<<i.snd+1<<"\n";
	return 0;
}
