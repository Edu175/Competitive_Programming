#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef long double ld;

typedef vector<ll> vv;
typedef pair<ll,ll> ii;

int main(){
	JET
	string s; cin>>s;
	string s1 = "";
	for(auto x:s)if(x!='.')s1.pb(x);
	ll x = stoll(s1);
	ll h = 36000;
	cout<<h/gcd(x,h)<<"\n";
	return 0;
}