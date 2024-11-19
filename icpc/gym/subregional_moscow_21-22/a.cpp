#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a, jet=b;i<jet;i++)
#define pb push_back
#define fst first
#define snd second 
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
	int n; cin>>n;
	int a[n];
	fore(i,0,n) cin>>a[i];
	fore(i,0,n){
		a[i]++;
		fore(j,0,n/2){
			if(a[j]!=a[n-1-j]){
				cout<<1<<"\n";
				return 0;
			}
		}
		a[i]--;
	}
	cout<<0<<"\n";
}