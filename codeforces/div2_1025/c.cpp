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
ll MAGIC=999999999;
ll ask(string s, ll y){
	cout<<s<<" "<<y<<endl;
	ll ret; cin>>ret;
	if(ret==-1)exit(0);
	return ret;
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ask("mul",MAGIC);
		ll asd;
		cout<<"digit"<<endl;
		cin>>asd;
		// cout<<"digit"<<endl;
		// cin>>asd;
		if(n!=81)ask("add",n-81);
		cout<<"!"<<endl;
		ll ans; cin>>ans;
		if(ans==-1)exit(0);
	}
	return 0;
}
