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
typedef pair<ll,ii> node; //cnt,l,r
#pragma GCC optimize("Ofast,O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
// #define bint __int128
// const bint MOD=212345678987654321LL,P=1777771,PI=106955741089659571LL;
#define bint ll
const bint MOD=1000000007,P=3954751,PI=115951928;
struct Hash{
	ll add(ll a, ll b){a+=b;if(a>=MOD)a-=MOD;return a;}
	ll sub(ll a, ll b){a-=b;if(a<0)a+=MOD;return a;}
	ll mul(bint a, bint b){return a*b%MOD;}
	vector<ll> h,pi;
	Hash(string &s){
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
	ll get(ll s, ll e){ // con el prefix de potencia P
		return mul(sub(h[e],h[s]),pi[s]);
	}
	
};
const ll maxn=6e6+5;
ll d1[maxn]; ll d2[maxn]; // cambiar
void manacher(string &s){
    int l=0, r=-1, n=SZ(s);
    fore(i,0,n){
        int k=i>r?1:min(d1[l+r-i],r-i);
        while(i+k<n&&i-k>=0&&s[i+k]==s[i-k])k++;
        d1[i]=k--;
        if(i+k>r) l=i-k,r=i+k;
    }
    l=0; r=-1;
    fore(i,0,n){
        int k=i>r?0:min(d2[l+r-i+1],r-i+1);k++;
        while(i+k<n&&i-k>=0&&s[i+k-1]==s[i-k])k++;
        d2[i]=--k;
        if(i+k-1>r)l=i-k,r=i+k-1;
    }
}

unordered_map<ll,node> m;
void oper(node &nod, ll l, ll r){
    nod.fst++;
    nod.snd.fst=l;
    nod.snd.snd=r;
}
vector<ii> rtaQ,rtaS; // 
const ll mod=998244353;
ll addm(ll a, ll b){a+=b;if(a>=mod)a-=mod;return a;}
ll subm(ll a, ll b){a-=b;if(a<0)a+=mod;return a;}
ll mulm(ll a, ll b){return a*b%mod;}
int main(){
    JET
    ll n; cin>>n;
    string s; cin>>s;
    string w=s; fore(i,0,n) w.pb(s[i]);
    Hash H(w);
    manacher(w);
    fore(i,n/2,n+n/2){
        ll k=min(d1[i],(n+1)/2);
        oper(m[H.get(i-k+1,i+k)],i-k+1,i+k);//borrar el +1 al "r" y agregar +1 al "l"
        k=min(d2[i],n/2);
        if(k)oper(m[H.get(i-k,i+k)],i-k,i+k);//bien
    }
    for(auto [h,nod]: m){
        auto [wi,lr]=nod;
        auto [l,r]=lr;
        while(l<r){
			auto hsh=H.get(l,r);
			rtaQ.pb({hsh,wi});
			rtaS.pb({hsh,r-l});
            // rta[].fst+=wi;
            // rta[H.get(l,r)].snd=(ii){l,r};
            l++,r--;
        }
    }
	sort(ALL(rtaQ));
	sort(ALL(rtaS));
	ll p=0,q=0;
    ll r=0;
	while(p<SZ(rtaQ)&&q<SZ(rtaS)){
		ll sz=0,qant=0,hsh=rtaQ[p].fst;
		assert(hsh==rtaS[q].fst);
		while(p<SZ(rtaQ)&&rtaQ[p].fst==hsh)qant+=rtaQ[p++].snd;
		while(q<SZ(rtaS)&&rtaS[q].fst==hsh)sz=rtaS[q++].snd;
		r=addm(r,mulm(mulm(qant,qant),sz));
	}
    cout<<r<<"\n";
    return 0;
}