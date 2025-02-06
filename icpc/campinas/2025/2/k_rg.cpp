#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b; i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
random_device rd;
mt19937 rng(rd());

int main(){
	JET
	ll N,V,Q; cin>>N>>V>>Q;
	ll n=rng()%(N-1)+2,q=rng()%Q+1;
	cout<<n<<" "<<q<<"\n";
	fore(i,0,n)cout<<rng()%V+1<<" ";;cout<<"\n";
	vv pa(n,-1);
	fore(i,1,n){
		pa[i]=rng()%i;
		cout<<pa[i]+1<<" "<<i+1<<" "<<rng()%V+1<<"\n";
	}
	while(q--){
		ll ty=rng()&1; cout<<ty+1<<" ";
		if(ty==0){
			cout<<rng()%n+1<<" ";
		}
		else {
			ll x=rng()%(n-1)+1;
			cout<<x+1<<" "<<pa[x]+1<<" ";
		}
		cout<<rng()%V+1<<"\n";
	}
	return 0;
}