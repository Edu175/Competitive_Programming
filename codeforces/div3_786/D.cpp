#include <bits/stdc++.h> 
#define pb push_back 
#define fst first 
#define snd second 
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i) 
#define SZ(x) ((int)x.size()) 
#define ALL(x) x.begin(),x.end() 
#define mset(a,v) memset((a),(v),sizeof(a)) 
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
using namespace std; typedef long long ll; 
int main(){FIN;
	ll t; cin>>t;  
	while(t--){    
		ll n;cin>>n;
		ll a[n];
		ll res=1;
		ll m=0;
		fore(i,0,n){
			cin>>a[i];
			if(n%2==1)if(i==0)m=a[0];
			if(i>1){
				if(i%2==n%2)m=max(a[i-2],a[i-1]);
			}
			if(a[i]<m)res=0;
			//cout<<m<<" ";
		}
		//cout<<"\n";
		if(res)cout<<"YES\n";
		else cout<<"NO\n";
	}  
	return 0; 
}
