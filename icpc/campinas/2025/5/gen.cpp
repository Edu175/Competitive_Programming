#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef int ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
random_device rd;
mt19937 rng(rd());

int main(){
	JET
	ll n,q; cin>>n>>q; cout<<n<<" "<<q<<"\n";
	fore(i,0,n)cout<<rng()%n+1<<" ";;cout<<"\n";
	while(q--){
		ll l=rng()%n,r=rng()%n;
		if(l>=r)swap(l,r);
		cout<<l+1<<" "<<r+1<<"\n";
	}
	return 0;
}