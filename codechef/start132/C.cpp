#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll>a(n);
		fore(i,0,n)cin>>a[i];
		vector<vector<ll>>sp(2,vector<ll>(n+1));
		fore(h,0,2){
			fore(i,1,n+1)sp[h][i]=sp[h][i-1]+(a[i-1]==h+1);
		}
		ll q; cin>>q;
		while(q--){
			ll l,r,k; cin>>l>>r>>k; l--;
			ll c=sp[0][r]-sp[0][l];
			ll d=sp[1][r]-sp[1][l];
			//k=min(k,r-l-(c+d));
			//ll x=min(c,d);
			ll res=0;
			//c-=x,d-=x;
			ll s=r-l-c-d;
			if(c<d)swap(c,d);
			if(k>=c-d){
				ll m=c+d+min(s,k);
				res=(m/2)*(m-m/2);
			}
			else if(k>s){
				d+=s;
				k-=s;
				k=min(k,(c-d)/2);
				c-=k;
				d+=k;
				res=c*d;
			}
			else {
				res=c*(d+k);
			}
			cout<<res<<"\n";
		}
	}
	return 0;
}
