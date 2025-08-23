#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
random_device rd;
mt19937 rng(rd());

int main(){
	JET
	cout<<1<<"\n";
	ll N,K; cin>>N>>K;
	ll n=rng()%N+1; cout<<n<<" ";
	ll k=rng()%K+1; cout<<k<<" ";
	ll v=rng()%K+1; cout<<v<<"\n";
	return 0;
}