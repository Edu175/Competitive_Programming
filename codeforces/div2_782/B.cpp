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
		ll n,k; cin>>n>>k;
		char s[n];
		vector<ll>v(n);
		ll u=0;
		fore(i,0,n){
			cin>>s[i];
			if(k%2==0&&u<k){
				if(s[i]=='0')v[i]=1, u++;
			}
			if(k%2==1&&u<k){
				if(s[i]=='1')v[i]=1, u++;
			}
		}
		v[n-1]+=k-u;
		if(k%2==1){
			fore(i,0,n){
				if(v[i]%2==0){
					if(s[i]=='1')s[i]='0';
					else s[i]='1';
				}
			}
		}
		if(k%2==0){
			fore(i,0,n){
				if(v[i]%2==1){
					if(s[i]=='1')s[i]='0';
					else s[i]='1';
				}
			}
		}
		fore(i,0,n)cout<<s[i];
		cout<<"\n";
		for(auto i:v)cout<<i<<" ";
		cout<<"\n";
	}
	return 0;
}
