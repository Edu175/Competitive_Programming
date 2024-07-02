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
	auto in=[&](ll i){
		fore(j,0,i-k+1)if(a[j]>a[i])st.insert({a[j]-a[i],{j,i}});
		fore(j,i+k,n)if(a[i]>a[j])st.insert({a[i]-a[j],{i,j}});
	};
	auto out=[&](ll i){
		fore(j,0,i-k+1)if(a[j]>a[i])st.erase({a[j]-a[i],{j,i}});
		fore(j,i+k,n)if(a[i]>a[j])st.erase({a[i]-a[j],{i,j}});
	};
	fore(i,0,n)in(i);
	vector<ii>res;
	while(SZ(st)){
		auto [d,pa]=*st.begin();
		auto [i,j]=pa;
		out(i); out(j);
		res.pb({i,j});
		swap(a[i],a[j]);
		in(i); in(j);
	}
	cout<<SZ(res)<<"\n";
	for(auto i:res)cout<<i.fst+1<<" "<<i.snd+1<<"\n";
	return 0;
}
