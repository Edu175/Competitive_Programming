#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b; i<jet;i++)
#define fst first
#define snd second 
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define pb push_back
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef short ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
random_device rd;
mt19937 rng(rd());

int main(){
	JET
	ll T; cin>>T;
	ll A,B,M; cin>>A>>B>>M;
	ll t=rng()%T+1;
	cout<<t<<"\n";
	while(t--){
		ll a=rng()%(A+1);
		ll b=rng()%(B+1);
		ll m=rng()%(M+1);
		cout<<a<<" "<<b<<" "<<m<<"\n";
		fore(i,0,m){
			ll l=rng()%(2*m)+1;
			ll r=rng()%(2*m)+1;
			if(l>r)swap(l,r);
			cout<<rng()%2+1<<" "<<l<<" "<<r<<"\n";
		}
	}
	return 0;
}