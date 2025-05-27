#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

int main(){
	JET
	ll t; cin>>t;
	while(t--){
		ll n, k; cin>>n>>k;
		ii a[k];
		ll maxi=0,max1=0,id;
		fore(i,0,k){
			cin>>a[i].fst>>a[i].snd;
			ll x = a[i].snd - a[i].fst+1;
			if(x>maxi){
				max1=maxi;
				maxi = x;
				id=i;
			}
			else if(x>max1) max1 =x ;
		}
		if(k==1){
			fore(i,0,n)cout<<i<<" ";
			cout<<"\n";
			continue;
		}
		if(maxi==max1){
			cout<<"IMPOSSIBLE\n";
			continue;
		}
		ll rta[n+1];
		fore(i,0,k){
			fore(j,a[i].fst,a[i].snd+1){
				if(j==a[i].fst){
					(j==a[id].fst) ? rta[j]=0: rta[j]=a[id].fst;
				}
				else rta[j] = j-1;
			}
		}
		fore(i,1,n+1) cout<<rta[i]<<" ";
		cout<<"\n";
		
	}
	return 0;
}