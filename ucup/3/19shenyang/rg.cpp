#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
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
random_device rd;
mt19937 rng(rd());

int main(){
	JET
	ll N,M; cin>>N>>M;
	ll n=rng()%N+1,m=rng()%M+1;
	cout<<n<<" "<<m<<" "<<n<<"\n";
	fore(i,0,m){
		cout<<rng()%n<<" "<<rng()%n<<"\n";
	}
	fore(i,0,n)cout<<i<<"\n";
	return 0;
}