#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b; i<jet;i++)
#define pb push_back
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define imp(v) {for(auto i:v)cout<<i<<" ";cout<<"\n";}
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
random_device rd;
mt19937 rng(rd());

int main(){
	JET
	ll N; cin>>N;
	ll n=rng()%N+1;
	vv per(n); iota(ALL(per),1);
	shuffle(ALL(per),rng);
	fore(i,0,n)if(rng()&1)per[i]=0;
	cout<<n<<"\n";
	imp(per);
}