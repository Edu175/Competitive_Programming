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
typedef array<ll,3> node;
bool cont(node &a, node &b){
	return a[0]<=b[0]&&b[1]<=a[1];
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<node>a(n);
		fore(i,0,n)cin>>a[i][0]>>a[i][1],a[i][2]=i,a[i][1]*=-1;
		sort(ALL(a));
		string res(n,'.');
		auto pareja=[&](ll i, ll j){ // F,T
			res[i]='N',res[j]='T';
		};
		vector<node>b;
		for(auto i:a){
			i[1]*=-1;
			if(SZ(b)&&cont(b.back(),i))
				pareja(i[2],b.back()[2]),b.pop_back();
			else b.pb(i);
		}
		fore(i,0,SZ(b)){
			res[b[i][2]]=(i&1?'T':'N');
		}
		cout<<res<<"\n";
	}
	return 0;
}
