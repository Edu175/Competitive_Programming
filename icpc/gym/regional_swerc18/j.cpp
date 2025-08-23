#include <bits/stdc++.h>
#define fore(i,a,b) for(int i = a, jet = b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(X) ((int)X.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JE ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
// typedef long long ll;
// typedef pair<ll,ll> ii;
// typedef vector<ll> vv;
typedef unsigned long long ull;

struct ran{
	typedef unsigned long long uint64;
	vector<uint64> state;
	ran(uint64 seed){state = { seed, seed ^ 0x7263d9bd8409f526 };}
	uint64 xoroshiro128plus(uint64 s[2]) {
	  uint64 s0 = s[0];
	  uint64 s1 = s[1];
	  uint64 result = s0 + s1;
	  s1 ^= s0;
	  s[0] = ((s0 << 55) | (s0 >> 9)) ^ s1 ^ (s1 << 14);
	  s[1] = (s1 << 36) | (s1 >> 28);
	  return result;
	}
	
};

int main(){
    JE
	
	int n; cin>>n;
	vector<ran> rng;
	
	fore(i,0,4){
		ull s; cin>>s;
		rng.pb(ran(s));
	}
	
	
	
    return 0;
}