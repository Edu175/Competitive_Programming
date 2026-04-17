#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a, jet = b; i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

typedef __int128 bint;

const bint MOD=212345678987654321LL,P=1777771,PI=106955741089659571LL;
struct Hash{
	vector<bint> h,pi;
	Hash(string &s){
		assert(P*PI%MOD==1);
		pi=h=vector<bint>(SZ(s)+1);
		pi[0]=1,h[0]=1;
		bint p=1;
		fore(i,1,SZ(s)+1){
			h[i]=(h[i-1]+s[i-1]*p)%MOD;
			pi[i]=pi[i-1]*PI%MOD;
			p=p*P%MOD;
		}
	}
	ll get(ll s, ll e){
		// cout<<"get "<<s<<" "<<e<<endl;
		ll ret=(h[e]-h[s]+MOD)%MOD*pi[s]%MOD;
		// cout<<ret<<endl;
		return ret;
	}
};

int main(){
    JET
	string s; cin>>s;
	ll n=SZ(s);
	ll d=1,p=0,r;
	auto get=[&](){
		return s[p+(r-p)%d];
	};
	// auto recalc=[&](){
	// 	ll _d=d;
	// 	while(p+d<=r&&get()!=s[r])d+=_d;
	// 	d=min(d,r-p+1);
	// };
	Hash h(s);
	fore(_r,0,n){
		r=_r;
		// cout<<r<<": "<<p<<" "<<d<<" -> ";
		if(s[r]>s[p]){
			p=r,d=1;
		}
		else if(s[r]>get()){
			while(p<=r)p+=d;
			p-=d;
			d=r-p+1;
			// cout<<p<<": "<<r<<endl;
			fore(k,1,n+3){
				// cout<<k<<": ";
				if(h.get(p,r+1-k)==h.get(p+k,r+1)){
					d=k;
					break;
				}
			}
		}
		else if(s[r]!=get())d=r-p+1;
		// cout<<p<<" "<<d<<" res: ";
		cout<<p+1<<" "<<r+1<<"\n";
	}
    return 0;
}