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
 
 int main(){JET
	#ifdef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ll n,m; cin>>n>>m;
	ll k=0;
	ll pos=n-1;
	ll sum=0;
	ll st=0;
	ll a[n];
	fore(i,0,n){
		ll c; cin>>c;
		a[i]=c;
		if(i>0 && c>k){
			pos=i-1;
		}
		sum+=c;
		k=max(c,k);
	}
	fore(i,0,pos){
		st+=a[i];
	}
	ll h=a[pos];
	//cout<<h;
	if(m==0 ){
		if(pos==n-1){
			cout<<"YES\n";
		}
		else cout<<"KEK\n";
		return 0;
	}
	if(pos==n-1) pos=n-2+k
	ll x=(m-pos-1)/(n-1+k);

	if(pos>=m||x<0){
		cout<<"KEK\n";
		// cout<<"dkjgh\n";
		// cout<<pos<<" "<<m<<"\n";
		return 0;
	}
	
	if(m-st<=x*(sum)+h) cout<<"YES\n";
	else cout<<"KEK\n";
	return 0;
 }