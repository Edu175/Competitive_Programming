#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i = a,jet = b; i<jet; i++)
#define snd second
#define fst first
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;



int main(){
	JET
	ll n,k; cin>>n>>k;
	ll p[n]; iota(p,p+n,1);
	if(!k){
		cout<<-1<<"\n";
	}
	
	else{
		if(k&1){
			fore(i,0,k/2){
				swap(p[2*i+1],p[2*(i+1)]);
			}
			fore(i,0,n) cout<<p[i]<<" ";; cout<<"\n";
		}
		else{
			swap(p[0],p[n-1]);
			fore(i,0,(k-1)/2){
				swap(p[2*i+1],p[2*(i+1)]);
			}
			fore(i,0,n) cout<<p[i]<<" ";; cout<<"\n";
		}
	}
	return 0;
}