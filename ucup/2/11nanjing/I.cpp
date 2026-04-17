#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

int main(){
	JET
	ll t; cin>>t;
	while(t--){
		ll n, k; cin>>n>>k;
		vector<ii> a(k);
		fore(i,0,k) cin>>a[i].fst>>a[i].snd;
		sort(ALL(a));
		ll start = 0, ant = -1;
		bool b = true;
		for(auto [x,y] : a){
			ll aux = x-y;
			if(aux <= ant && aux!=start) b = false;
			start = aux, ant = x;
		}
		cout<<(b ? "Yes\n" : "No\n");
	}
	return 0;
}