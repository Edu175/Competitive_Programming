#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define pb push_back
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

int main(){
	JET
	ll t; cin>>t;
	while(t--){
		int n; cin>>n;
		n--;
		vv p(n);
		int i = 1;
		while(i<n){
			cout<<"? 1 "<<i+1<<endl;
			ll r; cin>>r;
			if(r==0){
				p[i] = 1;
				i++;
				break;
			}
			p[i] = 0;
			i++;
		}
		int idx = 0;
		fore(j,i,n){
			ll r =1;
			while(r==1){
				idx++;
				cout<<"? "<<j+1<<" "<<idx+1<<endl;
				cin>>r;
			}	
			p[j] = idx+1;
		}
		cout<<"! ";
		for (auto x:p) cout<<x<<" ";
		cout<<endl;
	}
	return 0;
}