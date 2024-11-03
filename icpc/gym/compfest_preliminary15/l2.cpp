#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define pb push_back
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

int main(){
	JET
	ll n,m; cin>>n>>m;
	ll res=-1;
	ll men=0;
	fore(k,1,m+1){
		vv a(n+1);
		fore(i,0,n+1) a[i]=i;
		ll sum=0;
		fore(i,1,n+1){
			a[i]=0;
			sum+=a[(i*k-1)%n+1];
			a[(i*k-1)%n+1]=0;
		}
		if(sum>res) men=k;
		res=max(sum,res);
	}
	cout<<men<<"\n";
	cerr<<res<<"\n";
	
}