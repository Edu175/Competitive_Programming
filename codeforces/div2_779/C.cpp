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
	while(t--){
		ll n;cin>>n;vector<ll>v(n);
		ll res=1;
		set<ll>st;
		fore(i,0,n)cin>>v[i],st.insert(v[i]);
		if(count(ALL(v),1)!=1)res=0;
		if(v[0]-v[n-1]>1)res=0;
		fore(i,1,n){
			if(res==0||n==1){
				break;
			}
			//if(st.count(i+1)>n-i)res=0;
			if(v[i]-v[i-1]>1)res=0;
		}
		if(res)cout<<"YES\n";else cout<<"NO\n";
	}
	 return 0;
}
