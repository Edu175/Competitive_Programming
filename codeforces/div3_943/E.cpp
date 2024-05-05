#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		if(n==2){
			cout<<"1 1\n1 2\n";
			continue;
		}
		if(n==3){
			cout<<"2 1\n2 3\n3 1\n";
			continue;
		}
		vector<ii>a;
		a.pb({n-1,n-1});
		fore(i,0,n-2){
			a.pb({0,i});
		}
		a.pb({n-1,1});
		for(auto [u,v]:a){
			cout<<u+1<<" "<<v+1<<"\n";
		}
	}
	return 0;
}
