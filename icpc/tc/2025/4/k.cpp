#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

int main(){
	JET
	ll n; cin>>n;
	vv u[n];
	fore(i,0,n){
		string trash; u[i].resize(4);
		cin>>trash;
		fore(j,0,3) cin>>u[i][j];
		fore(j,0,3) if(u[i][j]<0) u[i][j]=1e9;
		u[i][3]=i;
	}
	ll r[n]; 
	fore(i,0,n) r[i]=1e9;
	fore(i,0,n) fore(j,0,3) r[i]=min(u[i][j],r[i]);
	sort(r,r+n);
	ll c=0;
	ll rta=0;
	fore(i,0,n){
		if(c+r[i]>300) break;
		c+=r[i];
		rta++;
	}
	
	cout<<rta<<"\n";
	return 0;
}