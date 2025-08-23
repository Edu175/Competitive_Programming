#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define pb push_back
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define mset(a,v) memset((a),(v),sizeof(a))
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){
	JET
	ll a,b,m,r; cin>>a>>b>>m>>r;
	map<ll,ll> M; M[r]=0; ll t;
	fore(i,1,2*m+1){
	r=(r*a+b)%m;
	if(M.count(r)){t=i-M[r]; break;}
	M[r]=i;	
	}	
	cout<<t<<"\n";
	return 0;
}