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
		ll n;cin>>n;vector<char>v(n);
		ll res=0;
		fore(i,0,n){
			cin>>v[i];
		}
		fore(i,1,n){
			if(i<n-1&&v[i]=='1'){
				if(v[i-1]=='0'&&v[i+1]=='0')res++;
			}
			if(v[i]=='0'){
				if(v[i-1]=='0')res+=2;
			}
		}
		cout<<res<<"\n";
	}
	 return 0;
}
