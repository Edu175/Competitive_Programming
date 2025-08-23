#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
// #define forr(i,a,b) for(ll i=b-1,jet=a;i>=jet;i--)
#define pb push_back
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define mset(a,v) memset((a),(v),sizeof(a))
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
random_device rd;
mt19937 rng(rd());

int main(){
	JET
	ll N,V; cin>>N>>V;
	ll n=rng()%N+1; cout<<n<<"\n";
	vv all(V); iota(ALL(all),1);
	shuffle(ALL(all),rng);
	sort(all.begin(),all.begin()+n);
	fore(i,0,n)cout<<all[i]<<" "<<"RGB"[rng()%3]<<"\n";
	return 0;
}