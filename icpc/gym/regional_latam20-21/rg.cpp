#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b; i<jet; i++)
#define pb push_back
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ll(x.size())
#define ET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define impr(v) {cout<<#v<<": ";for(auto [i,j]:v)cout<<i<<","<<j<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
random_device rd;
mt19937 rng(rd());

int main(){
	ET
	ll N,V,Q; cin>>N>>V>>Q;
	ll n=rng()%(N-2)+3,q=rng()%Q+1;
	cout<<n<<" "<<q<<"\n";
	fore(i,0,n)cout<<rng()%V+1<<" ";;cout<<"\n";
	fore(_,0,q){
		ll l=rng()%n,r=rng()%n;
		if(l>r)swap(l,r);
		r++;
		cout<<l<<" "<<r<<"\n";
	}
}