#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) (ll)x.size()
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){
	JET
	int t; cin>>t;
	while(t--){
		int n,p,k; cin>>n>>p>>k; p--;
		vector<ll>a(n);
		fore(i,0,n)cin>>a[i];
		if(k>=p){
			ll res=0;
			fore(i,0,n){
				if(i+n-p-1<n)res=max(res,max(a[i],))
			}
		}
	}
}
