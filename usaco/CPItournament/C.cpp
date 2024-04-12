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
typedef pair<ll,ll> ii;

int main(){FIN;
	ll n,k; cin>>n>>k;
	ll a[n][n];
	fore(i,0,n)fore(j,0,n)cin>>a[i][j];
	ll res=0,old=0;
	fore(i,0,n-1){
		vector<ll>cl,cr,pos;
		ll u=-1;
		fore(j,0,n){
			if(a[i][j]==3||a[i+1][j]==3)u=j;
			ll both=(a[i][j]==2&&a[i+1][j]==2);
			ll dos=a[i][j]==2||a[i+1][j]==2;
			if(dos){
				cl.pb(min(k+both,j-u));
				pos.pb(j);
			}
		}
		u=n;
		for(ll j=n-1;j>=0;j--){
			if(a[i][j]==3||a[i+1][j]==3)u=j;
			ll both=(a[i][j]==2&&a[i+1][j]==2);
			ll dos=a[i][j]==2||a[i+1][j]==2;
			if(dos){
				cr.pb(min(k+both,u-j));
			}
		}
		reverse(ALL(cr));
		fore(i,0,SZ(pos)){
			if(i){
				cl[i]=min(cl[i],pos[i]-pos[i-1]);
			}
			if(i<SZ(pos)-1){
				cr[i]=min(cr[i],pos[i+1]-pos[i]);
			}
		}
		ll sum=0;
		fore(i,0,SZ(pos)){
			if(i){
				ll p=pos[i-1]+cr[i-1];
				if(p==pos[i]-cl[i]&&max(a[i][p],a[i+1][p])!=3)sum=sum;
				else if(pos[i-1]+cr[i-1]<=pos[i]-cl[i])sum=0;
			}
			sum+=cl[i];
			res+=sum*cr[i];
		}
		//cout<<i<<": "<<res-old<<"\n";
		old=res;
	}
	cout<<res<<"\n";
	return 0;
}
