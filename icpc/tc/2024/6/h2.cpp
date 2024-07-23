#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b; i<jet;i++)
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
#define imp(v) {for(auto fdkhg:v)cout<<fdkhg<<" ";cout<<"\n";}
string cv(vector<ll>a){
	string ret="{ ";
	for(auto i:a)ret+=to_string(i)+" ";
	ret+="}";
	return ret;
}
const ll MAXN=605,MAXM=2005;

#define bint __int128
bint MOD=212345678987654321LL,P=1777771,PI=106955741089659571LL;
struct Hash{
	vector<bint> h,pi;//,pt;
	Hash(){}
	Hash(string &s){
		assert(P*PI%MOD==1);
		h.resize(SZ(s)+1); pi.resize(SZ(s)+1); //pt.resize(SZ(s)+1);
		h[0]=0;pi[0]=1;//pt[0]=1;
		bint p=1;
		fore(i,1,SZ(s)+1){
			h[i]=(h[i-1]+p*s[i-1])%MOD;
			pi[i]=pi[i-1]*PI%MOD;
			p=p*P%MOD;
			// pt[i]=p;
		}
	}
	bint get(ll s, ll e){
		return (h[e]-h[s]+MOD)%MOD*pi[s]%MOD;
	}
	/*ll con(ll s0, ll e0, ll s1, ll e1){
		ll h0=get(s0,e0),h1=get(s1,e1);
		return (h0+h1*pt[e0-s0])%MOD;
	}*/
};
Hash ha;
bint fpow(bint b, ll e){
	bint res=1;
	while(e){
		if(e&1)res=res*b%MOD;
		b=b*b%MOD,e>>=1;
	}
	return res;
}
string S;
ll ls[MAXM],rs[MAXM];
// abc < abcd
bool les(vector<ll>&a, vector<ll>&b){ // aristas
	if(!SZ(b))return 1;
	if(!SZ(a))return 0;
	// vector<vector<ll>>vs={a,b};
	// cout<<"les "<<cv(a)<<" "<<cv(b)<<"\n";
	vector<bint>pota={1},potb={1};
	ll suma=0;
	for(auto i:a)suma+=rs[i]-ls[i],pota.pb(fpow(P,suma));
	ll sumb=0;
	for(auto i:b)sumb+=rs[i]-ls[i],potb.pb(fpow(P,sumb));
	auto get=[&](ll x, ll w)->ll{ // check ?
		bint h=0;ll _x=x;
		// cout<<"get "<<_x<<"en "<<(w?"b":"a")<<":\n";
		fore(i,0,(w?SZ(b):SZ(a))){
			ll idx=(w?b:a)[i];
			// cout<<idx<<": "<<ls[idx]<<","<<rs[idx]<<" ls,rs\n";
			if(x-(rs[idx]-ls[idx])>=0){
				// cout<<"completo "<<i<<"\n";
				h=(h+(w?potb:pota)[i]*ha.get(ls[idx],rs[idx]))%MOD;
				x-=rs[idx]-ls[idx];
			}
			else {
				// cout<<"resto en "<<i<<": "<<x<<"\n";
				h=(h+(w?potb:pota)[i]*ha.get(ls[idx],ls[idx]+x))%MOD;
				x=0;
				break;
			}
		}
		// cout<<" = "<<(ll)h<<"\n";
		assert(!x);
		if(x)return -1;
		return h;
	};
	ll l=0,r=min(suma,sumb);
	while(l<=r){
		ll m=(l+r)/2;
		ll h0=get(m,0),h1=get(m,1);
		// cout<<"binaria "<<l<<","<<r<<" ("<<m<<")"<<": "<<h0<<" "<<h1<<"\n";
		if(h0!=h1)r=m-1;
		else l=m+1;
	}
	auto dbg=[](ll res){
		// cout<<" = "<<res<<"\n";
	};
	if(r>=suma){dbg(1);return 1;}
	if(r>=sumb){dbg(0);return 0;}
	// cout<<"difieren en la pos "<<r<<"\n";
	char ca,cb;
	ll x=r;
	for(auto i:a){
		if(x-(rs[i]-ls[i])>=0)x-=rs[i]-ls[i];
		else {
			ca=S[ls[i]+x];
			break;
		}
	}
	x=r;
	for(auto i:b){
		if(x-(rs[i]-ls[i])>=0)x-=rs[i]-ls[i];
		else {
			// cout<<" arista "<<i+1<<" en b con resto "<<x<<"\n";
			cb=S[ls[i]+x];
			break;
		}
	}
	// cout<<ca<<" "<<cb<<"\n\n\n";
	dbg(ca<cb);
	return ca<cb;
}

vector<ii>g[MAXN];
vector<ll> dp[MAXN];  // aristas
vector<ll> cam[MAXN]; // nodos

vector<ll>ord;
ll vis[MAXN];
void dfs(ll x){
	vis[x]=1;
	for(auto [y,i]:g[x])if(!vis[y])dfs(y);
	ord.pb(x);
}

int main(){JET
	ll n,m,D,s; cin>>n>>m>>D>>s; s--;
	cin>>S;
	ha=Hash(S);
	fore(i,0,m){
		ll u,v,l,r,len; cin>>u>>v>>l>>len; u--,v--,l--;
		r=l+len;
		// cout<<u<<","<<v<<" "<<l<<","<<r<<endl;
		ls[i]=l,rs[i]=r;
		g[u].pb({v,i});
	}
	dfs(s);
	reverse(ALL(ord));
	for(auto x:ord){
		// cout<<x+1<<" ord\n";
		cam[x].pb(x);
		for(auto [y,i]:g[x]){
			// cout<<"upd "<<y+1<<"\n";
			auto tmp=dp[x]; tmp.pb(i);
			if(les(tmp,dp[y]))dp[y]=tmp,cam[y]=cam[x];
		}
	}
	// fore(x,0,n){
	// 	cout<<x<<" dp: ";
	// 	for(auto i:dp[x])cout<<i+1<<" ";
	// 	cout<<"\n";
	// }
	fore(x,0,n){
		cout<<SZ(cam[x])<<" ";
		for(auto i:cam[x])cout<<i+1<<" ";
		cout<<"\n";
	}
	return 0;
}