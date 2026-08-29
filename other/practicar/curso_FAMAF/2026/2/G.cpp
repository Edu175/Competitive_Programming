#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define show(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	ll n; cin>>n;
	vector<pair<ll,string>> a(n);
	fore(i,0,n)cin>>a[i].second>>a[i].first;
	sort(ALL(a));
	vector<pair<string,ll>> res;
	for(auto [p,s]:a){
		if(p>SZ(res)){
			cout<<"-1\n";
			exit(0);
		}
		res.insert(res.begin()+p,{s,n-SZ(res)});
	}
	for(auto [s,h]:res)cout<<s<<" "<<h<<"\n";
	return 0;
}
