#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll mod=1e9+7;
ll addm(ll a, ll b){a+=b; return a<mod?a:a-mod;}
ll subm(ll a, ll b){a-=b; return a<0?a+mod:a;}
ll mulm(ll a, ll b){return a*b%mod;}
ll pm(ll n, ll e){ll r=1; while(e){if(e&1)r=mulm(r,n); n=mulm(n,n); e>>=1;} return r;}

vector<int> kmppre(string& t){
	vector<int> r(SZ(t)+1); r[0]=-1;
	int j=-1;
	fore(i,0,SZ(t)){
		while(j>=0&&t[i]!=t[j])j=r[j];
		r[i+1]=++j;
	}
	return r;
}
int kmp(string &s, string&t ){
	int r=0;
	string KK=s+"$"+t;
	vector<int> b=kmppre(KK);
	fore(i,0,SZ(b)){
		if(b[i]==SZ(s))r++;
	}
	return r;
}
int main(){
	JET
	ll n; cin>>n;ll q; cin>>q;
	string SSS,t; cin>>SSS>>t;
	ll k=min(n,ll(1+ceill(log2((1e6/double(SZ(SSS))))))); // iteraciones
	string s[k];
	s[0]=SSS;
	fore(i,1,k){
		s[i]=s[i-1]+string({t[i-1]})+s[i-1];
	}
	ll sp[n+1][26]; //sumas parciales de cantidades de la letra j
	fore(i,0,26) sp[0][i]=0;
	fore(i,0,n)fore(j,0,26){
		sp[i+1][j]=addm(sp[i][j],(t[i]=='a'+j?pm(2,mod-1-i-1):0ll));
	}
	bool exst[n+1][26]; mset(exst,0); //existe la letra j en adelante?
	for(ll i=n-1; i>=0; i--)fore(j,0,26){
		exst[i][j]=exst[i+1][j]|(t[i]=='a'+j);
	}
	
	ll c[26];
	// cout<<k<<"k\n";
	while(q--){
		string w; ll obj; cin>>obj>>w;
		ll j=0;
		for(;j<k&&SZ(w)>SZ(s[j]);j++);
		if(j==k){cout<<"0\n"; continue;}
		// cout<<j<<" j\n";
		// cout<<s[j]<<" s\n";
		// cout<<w<<" w\n";
		mset(c,0);
		ll r=mulm(kmp(w,s[j]),pm(2,obj-j));
		// cout<<kmp(w,s[j])<<" kmp\n";
		// cout<<r<<" pre-r\n";
		string aux=s[j].substr(SZ(s[j])-SZ(w)+1,SZ(w)-1)+string({'a'})+s[j].substr(0,SZ(w)-1);
		// cout<<aux<<" aux\n";
		fore(z,0,26)if(exst[j+1][z]){
			aux[SZ(w)-1]=z+'a';
			// cout<<aux<<" aux\n";
			// cout<<z<<" z\n";
			// // cout<<kmp(w,aux)<<" kmp\n";
			// // cout<<subm(sp[n][z],sp[j+1][z])<<" sumparc\n";
			// // cout<<obj<<" saco\n";
			// cout<<mulm(pm(2,obj),subm(sp[obj][z],sp[j][z]))<<"sumo\n";
			r=addm(r,mulm(pm(2,obj),mulm(subm(sp[obj][z],sp[j][z]),kmp(w,aux))));		
		}
		cout<<r<<"\n";
		// cout<<"\n";
	}
	return 0;
}
// 3 3
// aa
// bcd
// 2 aba
// 3 ca
// 3 aa

// 3k
// 1j
// aabaas
// abaw
// 0kmp
// 0
// 0j
// aas
// caw
// 0kmp
// 0
// 0j
// aas
// aaw
// 1kmp
// 8
// ed
