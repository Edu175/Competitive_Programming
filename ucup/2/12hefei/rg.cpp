#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b;i<jet;i++)
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
random_device rd;
mt19937 rng(rd());
string alphabet;
const ll LEN=5;
int main(){
    JET
	fore(i,'0','9'+1)alphabet.pb(i);
	fore(i,'a','z'+1)alphabet.pb(i);
	fore(i,'A','Z'+1)alphabet.pb(i);
    
	ll N; cin>>N;
	ll n=N;
	cout<<n<<"\n";
	string s;
	fore(i,0,LEN)s.pb(alphabet[rng()%SZ(alphabet)]);
	
	fore(i,0,n)cout<<s<<" ";;cout<<"\n";
	
	return 0;
}

