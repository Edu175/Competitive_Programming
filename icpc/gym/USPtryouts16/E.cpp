#include <bits/stdc++.h>
#define fst first
#define snd second
#define pb push_back
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define fore(i,a,b) for(ll i=a,aei=b;i<aei;++i)
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define imp(v) for(auto messi:v) cout << messi << " ";cout << "\n";
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef pair<ll,ll> ii;

#define bint __int128
struct Hash{
    const bint MOD=212345678987654321LL,P=1777771,PI=106955741089659571LL;
    vector<ll>pi,h,pt;
    Hash(string& s){
        assert(P*PI%MOD==1);
        pi.resize(SZ(s)+1),h.resize(SZ(s)+1),pt.resize(SZ(s)+1);
        pi[0]=1,h[0]=0,pt[0]=0;
        bint p=1;
        fore(i,1,SZ(s)+1){
            h[i]=(h[i-1]+s[i-1]*p)%MOD;
            pi[i]=(pi[i-1]*PI)%MOD;
            p=p*P%MOD;
            pt[i]=p;
        }
        ll get(ll s, ll e){
            return (h[e]-h[s]+MOD)*pi[s]%MOD;
        }
    }
};

int main(){FIN;
	return 0;
}
