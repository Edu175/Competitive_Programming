#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
#define bint __int128
struct Hash{
	bint MOD=212345678987654321LL,P=1777771,PI=106955741089659571LL;
	vector<ll>pi,h;
	Hash(vector<ll>& s){
		assert((P*PI)%MOD==1);
		pi.resize(SZ(s)+1),h.resize(SZ(s)+1);
		pi[0]=1,h[0]=0;
		bint p=1;
		fore(i,1,SZ(s)+1){
			h[i]=(h[i-1]+(s[i-1]*p)%MOD)%MOD;
			pi[i]=(pi[i-1]*PI)%MOD;
			p=(p*P)%MOD;
		}
	}
	ll get(ll s, ll e){
		return (((h[e]-h[s]+MOD)%MOD)*pi[s])%MOD;
	}
};


int main(){FIN;
	ll n,m; cin>>n>>m;
	vector<ll> a(n),b(m);
	fore(i,0,n)cin>>a[i];
	fore(i,0,m)cin>>b[i];
	//imp(a);
	//imp(b);
	fore(i,0,n-1)a[i]=a[i+1]-a[i]+3e5;
	fore(i,0,m-1)b[i]=b[i+1]-b[i]+3e5;
	a.pop_back();
	b.pop_back();
	n--,m--;
	Hash w(a);
	Hash v(b);
	/*cout<<"\n";
	for(auto i:a){
		cout<<i-3e5<<" ";
	}
	cout<<"\n";
	for(auto i:b){
		cout<<i-3e5<<" ";
	}
	cout<<"\n\n";*/
	ll res=0;
	fore(i,0,n-m+1){
		/*fore(j,i,i+m){
			cout<<a[j]-3e5<<" ";
		}
		cout<<": "<<(w.get(i,i+m)==v.get(0,m))<<"\n";*/
		if(w.get(i,i+m)==v.get(0,m))res++;
	}
	cout<<res<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
