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

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		ll l[n],r[n];
		fore(i,0,n)cin>>l[i];
		fore(i,0,n)cin>>r[i];
		vector<ll>sp(n+1);
		fore(i,1,n+1)sp[i]=sp[i-1]+r[i-1]-l[i-1]+1;
		ll p=lower_bound(ALL(sp),k)-sp.begin(); p--;
		if(p>=n){
			cout<<"-1\n";
			continue;
		}
		ll x=l[p]+k-sp[p]-1;// cout<<p<<" "<<x<<": ";
		ll c=p+1;	// # ran
		ll q=0;		// # 1
		fore(i,0,p+1)q+=(r[i]-l[i]+1==1);
		ll res=2*c+x;
		while(q&&p<n&&x<=r[n-1]){
			q--,x++,c--;
			if(x>r[p]){
				p++;
				if(p>=n)break;
				x=l[p],q+=(r[p]-l[p]==0),c++;
			}
			res=min(res,2*c+x);
		}
		cout<<res<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
