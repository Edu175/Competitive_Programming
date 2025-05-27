#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define pb push_back
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
random_device rd;
mt19937 rng(rd());
int main(){
	JET
	ll N,K; cin>>N>>K;
	ll n=rng()%(N-2)+3,k=rng()%(K+1);
	cout<<"1\n"<<n<<" "<<k<<"\n";
	return 0;
}