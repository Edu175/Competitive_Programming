#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define snd second
#define fst first
#define pb push_back
#define SZ(x) ((int)x.size())
#define ALL(x) (x.begin(),x.end())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const ll MAXN=1005;
ll n,m;
vector<ii>ed;
vector<ii>ig;
bool good(vector<ll>c){
	for(auto [x,y]:ed)if(!(c[x]<c[y]))return 0;
	for(auto [x,y]:ig)if(!(c[x]==c[y]))return 0;
	return 1;
}
int main(){JET
	#ifdef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	assert(n<30);
	cin>>n>>m;
	fore(i,0,m){
		string s; cin>>s;
		ll x=0,y=0,w=0; char c;
		fore(i,0,SZ(s)){
			if(s[i]<'0'||s[i]>'9')w=1,c=s[i];
			else {
				if(!w)x=x*10+(s[i]-'0');
				else y=y*10+(s[i]-'0');
			}
		}
		x--,y--;
		if(c=='=')ig.pb({x,y});
		else {
			if(c=='>')swap(x,y);
			// cout<<x<<" "<<y<<": "<<c<<"\n";
			ed.pb({x,y});
		}
	}
	// for(auto i:ed)cout<<i.fst<<","<<i.snd<<" ";;cout<<endl;
	// for(auto i:ig)cout<<i.fst<<","<<i.snd<<" ";;cout<<endl;
	ll pot[30]; pot[0]=1;
	fore(i,1,30)pot[i]=pot[i-1]*3;
	// for(auto i:pot)cout<<i<<" ";;cout<<endl;
	vector<ll>can(n);
	fore(mk,0,pot[n]){
		ll k=mk;
		vector<ll>c;
		fore(i,0,n)c.pb(k%3),k/=3;
		if(good(c)){
			fore(i,0,n)can[i]|=1ll<<c[i];
		}
		// cout<<mk<<": ";
		// for(auto i:c)cout<<i<<" ";
		// cout<<" = "<<good(c)<<"\n";
	}
	fore(i,0,n){
		if(__builtin_popcountll(can[i])==1){
			cout<<"BRW"[__builtin_ctzll(can[i])];
		}
		else cout<<"?";
	}
	cout<<"\n";
	return 0;
 }