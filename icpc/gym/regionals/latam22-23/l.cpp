#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b; i<jet; i++)
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define pb push_back
#define ET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef int ll;
typedef long long lL;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
typedef __int128 xl;
const xl MOD=212345678987654321LL, P=1777771, PI=106955741089659571LL;
const ll MAXN=2e5+5;
ll d,n;
struct Hash{
	vector<xl> h,pi;
	Hash() {}
	Hash(string &s){
		assert(P*PI%MOD==1);
		h.resize(SZ(s)+1); pi.resize(SZ(s)+1);
		h[0]=0; pi[0]=1;
		xl p=1;
		fore(i,1,SZ(s)+1){
			h[i]=(h[i-1]+p*s[i-1])%MOD;
			pi[i]=(pi[i-1]*PI)%MOD;
			p=(p*P)%MOD;
		}
	}
	lL get(int s, int e){
		return (((h[e]-h[s]+MOD)%MOD)*pi[s])%MOD;
	}
};
Hash T;

int main(){
	ET
	//ll n,m;
	string t; 
	cin>>t>>d;
	n=SZ(t);
	//cout<<n<<"\n";
	T=Hash(t);
	ll rta=0;
	ll i=0;
	while(i<n){
		rta++;
		//if(i==n) return 0;
		ll m=0;
		fore(j,1,min(d+1,n-i+1)){
			ll k=1;
			while(i-1+j*(k+1)<n){
				if(T.get(i,i+j)==T.get(i+j*(k),i+j*(k+1))) k++;
				else break;
			}
			ll b=i+j*(k), l=0, r=min(j,n-b);
			
			while(l<=r){
				ll h=(l+r)/2;
				if(T.get(i,i+h)==T.get(b,b+h)) l=h+1;
				else r=h-1;
			}
			m=max(m,b+r);
		}
		//cout<<i<<endl;
		//cout<<depe(m+1)<<"\n";
		i=m;
	}
	cout<<rta<<"\n";
	return 0;
}
//g++ -Wall -Wextra -std=c++20 -g templatea.cpp -o a