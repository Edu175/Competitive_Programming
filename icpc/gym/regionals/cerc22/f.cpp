#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define show(x) {for(auto y:x)cout<<y<<" ";cout<<"\n";}
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll maxn=1e5+5;
ll h[maxn];
mt19937_64 rng(67677);
int main(){
	JET
	ll n,m,k; cin>>n>>m>>k;
	fore(i,0,n) h[i]=rng();
	string s[n];
	fore(i,0,n) cin>>s[i];
	ll S[n],c[4],p[4]; mset(S,0);
	
	fore(i,0,m){
		mset(c,0);mset(p,0);
		fore(j,0,n){
			c[s[j][i]-'A']+=h[j];
		}
		fore(j,0,4)fore(r,0,4)if(j!=r)p[j]+=c[r];
		fore(j,0,n)S[j]+=p[s[j][i]-'A'];
	}
	ll T=0;
	fore(i,0,n) T+=h[i];
	T*=k;
	ll r;
	fore(i,0,n)if(T-(h[i]*k)==S[i]) r=i;
	cout<<r+1<<"\n";
	return 0;
}