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
	cout<<"1\n";
	ll N,N2,M,K; cin>>N>>N2>>M>>K;
	ll m=M;
	// ll m=rng()%M+1;
	K=min(K,m*m);
	ll k=rng()%K+1;
	cout<<rng()%N+1<<" "<<rng()%N2+1<<" "<<m<<" "<<k<<"\n";
	fore(i,0,k){
		ll a=rng()%m;
		ll b=rng()%(m-1);
		if(b>=a)b++;
		cout<<a+1<<" "<<b+1<<"\n";
	}
	return 0;
}
