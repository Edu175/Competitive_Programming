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
	vector<ll>pi,h,pt;
	Hash(string& s){
		assert((P*PI)%MOD==1);
		pi.resize(SZ(s)+1),h.resize(SZ(s)+1),pt.resize(SZ(s)+1);
		pi[0]=1,h[0]=0,pt[0]=1;
		bint p=1;
		fore(i,1,SZ(s)+1){
			h[i]=(h[i-1]+(s[i-1]*p)%MOD)%MOD;
			pi[i]=(pi[i-1]*PI)%MOD;
			p=(p*P)%MOD;
			pt[i]=p;
		}
	}
	ll get(ll s, ll e){
		return (((h[e]-h[s]+MOD)%MOD)*pi[s])%MOD;
	}
	ll con(ll h1, ll m, ll h2){
		return (h1+(bint(h2)*bint(pt[m]))%MOD)%MOD;
	}
};
int main(){FIN;
	ll n; cin>>n;
	string s,t;
	cin>>s;
	t=s; reverse(ALL(t));
	Hash w(s);
	Hash x(t);
	ll res=-1;
	for(ll r=n,l2=0,l1=2*n;r>=0;l2++,r--,l1--){
		//cout<<r<<" "<<l1<<" | "<<l2<<" "<<l2+n<<"\n";
		ll h2=x.get(l2,l2+n),h1=w.con(w.get(0,r),r,w.get(l1,2*n));
		//cout<<h1<<" | "<<h2<<"\n";
		
		if(h1==h2)res=r;
	}
	if(res==-1)cout<<res<<"\n";
	else {
		string sr;
		fore(i,res,res+n)sr.pb(s[i]);
		reverse(ALL(sr));
		cout<<sr<<"\n"<<res<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home

