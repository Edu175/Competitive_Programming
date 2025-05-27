#include <bits/stdc++.h>
#define fore(i,a,b) for(int i=a, jet=b;i<jet;i++)
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
#pragma GCC optimize("Ofast,O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
// #define bint __int128
struct Hash{
	// bint MOD=212345678987654321LL,P=1e9+7,PI=16734166335235990LL;
	const ll MOD=2235947513,P=1000000009,PI=500410404;
	ll add(ll a, ll b){a+=b;if(a>=MOD)a-=MOD;return a;}
	ll sub(ll a, ll b){a-=b;if(a<0)a+=MOD;return a;}
	ll mul(ll a, ll b){return a*b%MOD;}
	vector<ll> h,pi;
	Hash(vv &s){
		assert(P*PI%MOD==1);
		h.resize(SZ(s)+1); pi.resize(SZ(s)+1);
		h[0]=0; pi[0]=1;
		ll p=1;
		fore(i,1,SZ(s)+1){
			h[i]=add(h[i-1],mul(p,s[i-1]));
			pi[i]=mul(pi[i-1],PI);
			p=mul(p,P);
		}
	}
	ll get(int s, int e){ // con el prefix de potencia P
		return mul(sub(h[e],h[s]),pi[s]);
	}
	bool good(int p, int l, int k){
		ll d=sub(get(k,k+l),get(0,l));
		ll my=sub(get(p+k,p+k+l),get(p,p+l));
		bool ret=my==d;
		// cout<<"good "<<p<<" "<<l<<" "<<k<<": "<<mul(my,pi[p])<<" "<<d<<": "<<ret<<"\n";
		return ret;
	}
};

// const ll LEN=5;
// ll pot[LEN];
int cv(char a){
	if('0'<=a && a<='9')return a-'0';
	if('a'<=a && a<='z')return a-'a'+10;
	if('A'<=a && a<='Z')return a-'A'+10+26;
	assert(0);
}
int cv(string s){
	int x=0;
	for(auto i:s)x=x*62+cv(i);
	return x;
}

int main(){
    JET
	// pot[0]=1;
	// fore(i,1,LEN)pot[i]=pot[i-1]*62;
	int n; cin>>n;
	vv a(n);
	fore(i,0,n){
		string s; cin>>s;
		a[i]=cv(s);
	}
	// for(auto i:a)cout<<i<<" ";;cout<<"\n";
	Hash hsh(a);
	vector<int> h(n+1);
	
	fore(k,1,n/2+5)if(2*k+1<=n){
		// obtengo pos
		int P=n;
		
		ll d=0,prev=hsh.get(0,k);
		bool did=0;
		for(int p=0;p+k<=n;p+=k){
			bool good=0;
			if(n-(p+k)<k)good=0;
			else {
				ll now=hsh.get(p+k,p+2*k);
				ll actd=hsh.sub(now,prev);
				if(!did)d=actd,good=1,did=1;
				else good=actd==d;
				prev=now;
			}
			if(!good){
				P=p;
				// cout<<"aca dio mal "<<p<<" "<<l<<"\n";
				break;
			}
		}
		if(P==-1)continue;
		int l=0,r=min(k,n-(P+k)); // ans en (l,r)
		while(l<=r){
			int m=(l+r)/2;
			if(hsh.good(P,m,k))l=m+1;
			else r=m-1;
		}
		int pos=P+k+r;
		assert(pos<=n);
		// cout<<k<<": "<<P<<" "<<r<<": "<<pos<<"\n";
		// 
		int L=2*k+1;
		if(L<=n)h[L]=max(h[L],pos);
	}
	
	int bst=0;
	fore(m,1,n+1){
		bst=max(bst,h[m]);
		if(bst>=m)cout<<'1';
		else cout<<'0';
	}
	cout<<"\n";
    return 0;
}

