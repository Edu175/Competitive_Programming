#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
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

int main(){
	JET
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		int a[n];
		fore(i,0,n){
			char c; cin>>c;
			if(c=='B') a[i]=0;
			else a[i]=1;
		}
		vv rta;
		stack <int> st;
		fore(i,0,n){
			if(a[i]==1){
				rta.pb(i+1);
				while(SZ(st)){
					int x = st.top();
					st.pop();
					rta.pb(x+1);
				}
				if(i<n-1) a[i+1]^=1; 
			}
			else st.push(i);
		}
		if(SZ(st)>0) cout<<"N\n";
		else{
			cout<<"Y\n";
			for(auto x:rta) cout<<x<<" ";
			cout<<"\n";
		}
	}
	return 0;
}