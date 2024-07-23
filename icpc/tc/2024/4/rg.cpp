#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
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
	ll n; cin>>n;
	cout<<1<<"\n"<<n<<"\n";
	fore(i,0,n)cout<<(rng()%2?'K':'?');;cout<<"\n";
	/*ll N,M; cin>>N>>M;
	ll n=rng()%N+1,m=rng()%M+1;
	cout<<"1\n";
	cout<<n<<" "<<m<<"\n";
	fore(i,0,n)cout<<rng()%n+1<<" ";;cout<<"\n";
	fore(i,0,m){
		ll l=rng()%n+1,r=rng()%n+1;
		if(l>r)swap(l,r);
		cout<<l<<" "<<r<<"\n";
	}*/
}