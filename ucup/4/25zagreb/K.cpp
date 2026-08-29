#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define snd second
#define fst first
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define pb push_back
#define show(x) {for(auto y:x)cout<<y<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){
	JET
	ll t;  cin>>t;
	while(t--){
		ll n; cin>>n;
		n*=2;
		priority_queue<ii> pq;
		vv res;
		fore(i,0,n){
			ll x; cin>>x;
			pq.push({x,i+1});
			if(i%2==0)res.pb(pq.top().snd),pq.pop();
		}
		show(res)
	}
	return 0;
}