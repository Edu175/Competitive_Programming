#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b;i<jet;i++)
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
const ll maxm=1e3;
int main(){
	
	#ifdef ONLINE_JUDGE
	freopen("filter.in","r",stdin);     freopen("filter.out","w",stdout);
	#endif

	JET
	ll m,f; cin>>m>>f;
	ll a[f]; fore(i,0,f) {cin>>a[i]; a[i]%=m;}
	ll n; cin>>n;
	bitset<maxm> d[n];
	fore(i,0,n){
		string s;
		cin>>s;
		//reverse(ALL(s));
		ll pos=0;
		fore(j,0,SZ(s)){
			ll x=(s[j]<='9'&&s[j]>='0'?s[j]-'0':s[j]-'a'+10);
		//	cout<<j<<"j "<<pos<<"pos "<<x<<"x "<<i<<"i\n";
			ll paux=pos+4;
			while(x&&pos<maxm){
				d[i][pos]=x&1;
				pos++;
				x>>=1;
			}
			pos=paux;
			if(pos>=maxm) break;
		}
	}
	/*fore(i,0,n) {
		fore(j,0,m) cout<<d[i][j]<<" ";
		cout<<"\n";
	}*/
	vv res;
	ll q; cin>>q;
	bool flag[n];
	fore(i,0,n) flag[i]=0;
	while(q--){
		ll uk; cin>>uk;
		uk%=m;
		ll na[f];
		fore(i,0,f) na[i]=uk*a[i]%m;
		fore(i,0,n){
			bool fl=1;
			fore(j,0,f){
				fl=fl&d[i][na[j]];
			}
			flag[i]=flag[i]|fl;	
		}
	}
	
	fore(i,0,n) if(flag[i]) res.pb(i);
	cout<<SZ(res)<<" ";
	for(auto x:res) cout<<x<<" ";; cout<<"\n";
	return 0;
	
}

