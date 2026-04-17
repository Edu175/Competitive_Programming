#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,tap=b;i<tap;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto asd:v)cout<<asd<<" ";cout<<"\n"
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll n; cin>>n;
	char a[n][n];
	fore(i,0,n)fore(j,0,n){
		cin>>a[i][j];
	}
	ll res=0;
	fore(i,0,n){
		ll c=0;
		fore(j,0,n){
			if(a[i][j]=='N')c++;
			else res+=c/2,c=0;
		}
		res+=c/2;
	}
	cout<<res<<"\n";
	return 0;
}
