#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b; i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

int main(){
	JET
	ll t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		vector<pair<ii,ll>> v(n);
		fore(i,0,n){
			cin>>v[i].snd;
			v[i].fst.snd=i;
		}
		fore(i,0,n){
			cin>>v[i].fst.fst;
		}
		sort(ALL(v));
		fore(i,0,n) cout<<v[i].snd<<" ";
		cout<<"\n";
	}
	return 0;
}