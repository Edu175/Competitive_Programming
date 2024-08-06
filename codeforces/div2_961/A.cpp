#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
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
		ll n,k; cin>>n>>k;
		vector<ll>c(4*n+5);
		fore(i,0,n)fore(j,0,n)c[i+j]++;
		sort(ALL(c)); reverse(ALL(c));
		ll res=-1;
		fore(i,0,SZ(c)){
			if(k<=0){res=i;break;}
			k-=c[i];
		}
		cout<<res<<"\n";
	}
	return 0;
}
