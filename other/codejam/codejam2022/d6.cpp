#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

int main(){FIN;
	ll t; cin>>t;
	ll te=t;
	while(t--){
		cout<<"Case #"<<te-t<<": ";
		ll n;cin>>n;vector<ll>v(n);
		fore(i,0,n)cin>>v[i];
		sort(ALL(v));
		/*for(auto i:v)cout<<i<<" ";
		cout<<"\n";*/
		ll res=0;
		ll k=0;
		fore(i,0,n){
			/*if(i<n-1&&v[i+1]==v[i]){
				continue;
			}*/
			if(v[i]>=i+1-k)res++;
			else k++;
		}
		cout<<res<<"\n";
	}
	return 0;

