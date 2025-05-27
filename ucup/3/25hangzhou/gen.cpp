#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
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

int main(){
	JET
	ll n,q,V; cin>>n>>q>>V;
	cout<<n<<" "<<q<<"\n";
	fore(i,0,n)cout<<rng()%V<<" ";;cout<<"\n";
	while(q--){
		ll ty=rng()%3+1;
		cout<<ty<<" ";
		if(ty==1||ty==3){
			ll l=rng()%n,r=rng()%n;
			if(l>=r)swap(l,r);
			cout<<l+1<<" "<<r+1<<" ";
		}
		if(ty==2)cout<<rng()%n+1<<" ";
		if(ty==1||ty==2)cout<<rng()%V;
		cout<<"\n";
	}
	return 0;
}