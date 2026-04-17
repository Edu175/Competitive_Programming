#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define fst first 
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll) x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

int main(){
	JET
	ll n; cin>>n;
	if(n==1||n==3){
		cout<<"-1\n";
		return 0;
	}
	vector<vv> a(n,vv(n,1));
	if(n%2){
		for(ll i=0,j=0;i<n;i++,j=(j-2+n)%n){
			assert(a[i][j]==1);
			a[i][j]=3;
		}
		for(ll i=n-1,j=n-1;i>=0;i--,j=(j+2)%n){
			assert(a[i][j]==1);
			a[i][j]=2;
		}
	}
	ll s=0;
	fore(i,0,n)fore(j,0,n)s+=a[i][j];
	cout<<s<<"\n";
	fore(i,0,n){
		fore(j,0,n)cout<<a[i][j]<<" ";
		cout<<"\n";
	}
	return 0;
}