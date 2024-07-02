#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,oii=b;i<oii;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) {for(auto dksjfg:v)cout<<dksjfg<<" ";cout<<endl;}
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

const ll K=17;
ll F[K][1ll<<K];
int main(){FIN;
	ll n; cin>>n;
	vector<ll>a(n);
	fore(i,0,n)cin>>a[i];
	vector<ll> fr(n);
	for(ll i=n-1;i>=0;i--)
		for(fr[i]=i+1;fr[i]<n&&a[i]>a[fr[i]];fr[i]=fr[fr[i]]);
	imp(fr);
	fore(i,0,n)F[0][i]=fr[i];
	F[0][n]=n;
	fore(k,1,K)fore(i,0,n+1)F[k][i]=F[k-1][F[k-1][i]];
	ll q; cin>>q;
	while(q--){
		ll l,r; cin>>l>>r; l--;
		ll res=0,x=l;
		for(ll k=K-1;k>=0;k--){
			if(F[k][x]<r)x=F[k][x],res+=1ll<<k;
		}
		res+=1;
		cout<<res<<"\n";
	}
	
	return 0;
}