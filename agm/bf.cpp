//notes https://github.com/Edu175/padalustro/blob/master/padalustro.cpp
#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll n,m; cin>>n>>m;
	vector<ll>a;
	fore(i,0,n)fore(j,0,m)a.pb(i);
	ll mx=0;
	sort(ALL(a));
	do{
		ll b[n][m];
		fore(i,0,n)fore(j,0,m)b[i][j]=a[m*i+j];
		vector<ll>c(n);
		fore(h,0,n)fore(i,0,n){
			ll q=0;
			fore(j,0,m){
				if(b[i][j]==h)c[h]+=m-1-j-q++;
			}
		}
		ll mn=c[0];
		for(auto i:c)mn=min(mn,i);
		mx=max(mx,mn);
		/*if(mn==5){
			fore(i,0,n){imp(b[i]);}
			cout<<"\n";
		}*/
	}
	while(next_permutation(ALL(a)));
	cout<<mx<<"\n";
	return 0;
}
