#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second 
#define fore(i,a,b) for(ll i=a,jet=b ;i<jet;i++)
#define SZ(x) ((int) x.size())
#define ALL(x) x.begin(),x.end()
#define  mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;

int main(){
	FIN
	ll n; cin>>n;
	vector<ll>a(n);
	ll mx=-1;
	fore(i,0,n)cin>>a[i],mx=max(a[i],mx);
	if(mx==a[0])cout<<"S\n";
	else cout<<"N\n";
	return 0;
} 