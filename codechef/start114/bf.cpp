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
	ll n; cin>>n;
	/*fore(c,0,n){
		cout<<c<<":\n";
		cout<<"0,0"<<" "<<c<<","<<c<<"\n";
		fore(i,0,c)cout<<i<<","<<0<<" "<<0<<","<<i<<" "<<c<<","<<i<<" "<<i<<","<<c<<"\n";
	}*/
	fore(mk,0,1ll<<(n*n)){
		ll a[n][n];
		if(__builtin_popcountll(mk)!=(n*n+1)/2)continue;
		fore(i,0,n)fore(j,0,n)a[i][j]=(mk&(1ll<<(n*i+j)))>0;
		ll flag=1;
		fore(c,0,n){
			ll s=a[0][0]+(c==0?0:a[c][c]);
			fore(i,0,c)s+=a[i][0]+a[0][i]+a[c][i]+a[i][c];//,			cout<<i<<","<<0<<" "<<0<<","<<i<<" "<<c<<","<<i<<" "<<i<<","<<c<<"\n";
			if(s%2==0)flag=0;
		}
		if(flag){
			fore(i,0,n){
				fore(j,0,n)cout<<a[i][j];
				cout<<"\n";
			}
			cout<<"\n";
		}
	}
	return 0;
}
