#include<bits/stdc++.h>
#define fore(i,a,b) for( ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define pb push_back
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
random_device rd;
mt19937 rng(rd());

int main(){
	JET
	ll N,K,V; cin>>N>>K>>V;
	ll n=rng()%(N-1)+2,k=rng()%(K+1);
	cout<<n<<" "<<k<<" 1\n";
	fore(i,0,n)cout<<rng()%(V+1)<<" ";;cout<<"\n";
	ll l=rng()%n,r=rng()%n;
	if(l>r)swap(l,r);
	cout<<l<<" "<<r<<"\n";
	return 0;
}