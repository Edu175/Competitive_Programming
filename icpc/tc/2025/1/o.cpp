#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define pb push_back
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

int main(){
	JET
	ll _; cin>>_; while(_--){
		ll n,q; cin>>n>>q;
		ll a[n]; fore(i,0,n) cin>>a[i];
		ll sp[n+1]; sp[0]=0; fore(i,0,n) sp[i+1]=sp[i]^a[i];
		ll nxt[n+1][30]; 
 		fore(i,0,30){
			nxt[0][29-i]=-1;
			if(!i)fore(j,0,n) nxt[j+1][29]=((a[j]&(1<<(29)))?j:nxt[j][29]);
			else fore(j,0,n) nxt[j+1][29-i]=((a[j]&(1<<(29-i)))?j:max(nxt[j][29-i],nxt[j+1][30-i]));
		}
		// fore(i,0,n+1){
		// 	fore(j,0,30){
		// 		cout<<nxt[i][j]<<" ";
		// 	}
		// 	cout<<"\n";
		// }
		while(q--){
			ll x; cin>>x; ll pos=n;
			ll b=0;
			// cout<<q<<" qq\n";
			while(pos){
				if(!x) break;
				while(b<30){
					if((x&(1<<(29-b)))) break;
					else b++;
				}
				// cout<<b<<"\n";
				x^=(sp[pos]^sp[nxt[pos][29-b]+1]);
				pos=nxt[pos][29-b]+1;
				// cout<<x<<"x  "<<pos<<"pos \n";
				if(!pos) break;
				if(x<a[pos-1]) break;
				x^=a[pos-1];
				pos--;
			}
			cout<<n-pos<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
