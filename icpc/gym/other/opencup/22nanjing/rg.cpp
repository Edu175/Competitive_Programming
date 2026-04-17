#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
random_device rd;
mt19937 rng(rd());

int main(){
	JET 
	ll T=300; cout<<T<<"\n";
	ll M=1e9;
	while(T--){
		ll a=rng()%M+1;
		ll b=rng()%M+1;
		while(a==b)b=rng()%M+1;
		cout<<a<<" "<<b<<"\n";
	}
	return 0;
}

