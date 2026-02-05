#include <bits/stdc++.h> 
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define snd second 
#define fst first
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll) x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

ll n;
ll fpow(ll x,ll b){
	if(!x) return 1;
	ll y = fpow(x/2,b);
	y*=y;
	if(x&1) y*=b;
	y%=n;
	return y;
}

int main(){
	JET
	ll k; cin>>n>>k;
	string s, rta;
	rta.resize(n);
	cin>>s;
	fore(i,0,n) rta[i] = s[(i*fpow(k,2))%n];
	cout<<rta<<"\n";
	return 0;
}