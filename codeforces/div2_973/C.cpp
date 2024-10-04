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
ll ask(vv v){
	cout<<"? ";
	for(auto i:v)cout<<i;
	cout<<endl;
	ll ret; cin>>ret;
	if(ret==-1)exit(0);
	return ret;
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vv v;
		v.pb(0);
		if(!ask(v))v={1};
		while(SZ(v)<n){
			v.pb(0);
			if(!ask(v)){
				v[SZ(v)-1]=1;
				if(!ask(v)){
					v.pop_back();
					break;
				}
			}
		}
		if(SZ(v)==n){
			cout<<"! ";
			for(auto i:v)cout<<i;
			cout<<endl;
			continue;
		}
		while(SZ(v)<n){
			v.insert(v.begin(),0);
			if(!ask(v)){
				v[0]=1;
			}
		}
		cout<<"! ";
		for(auto i:v)cout<<i;
		cout<<endl;
	}
	return 0;
}
