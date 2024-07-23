#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b; i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

ll dif(string a, string b){
	ll rta=0;
	fore(i,0,SZ(a)){
		rta+=(a[i]!=b[i]);
	}
	return rta;
}

int main(){
	int n,m,k;
	cin>>n>>m>>k;
	string a[n];
	fore(i,0,n) cin>>a[i];
	fore(i,0,n){
		fore(j,0,n){
			if(i==j) continue;
			// cout<<"dif entre "<<i<<" "<<j<<" es "<<dif(a[i],a[j])<<"\n"; 
			if(dif(a[i],a[j])!=k){
				break;
			}
			if(j==n-1){
				cout<<i+1<<"\n";
			}
		}
	}
}