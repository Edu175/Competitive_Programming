#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b; i<jet;i++)
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
random_device rd;
mt19937 rng(rd());

int main(){JET
	ll n; cin>>n;
	vector<ll>a={0};
	fore(i,0,n){
		if(rng()&1)a.pb(i);
	}
	cout<<SZ(a)<<"\n";
	for(auto i:a)cout<<i<<" ";;cout<<"\n";
	return 0;
}