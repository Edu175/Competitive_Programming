#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
using namespace std;
typedef long long ll;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		string s; cin>>s;
		ll flag=1;
		ll a[n],b[n]; 
		fore(i,0,n){
			a[i]=s[i]-'0';
			b[i]=a[i]^1;
			if(a[i])flag=0;
		}
		if(k==1){
			cout<<flag<<"\n";
			continue;
		}
		ll c=0;
		fore(i,0,k){
			if(a[i]==0){
				if(!i||a[i-1])c++;
			}
		}
		//cout<<"0 "<<k-1<<": "<<c<<"\n";
		ll res=2*c-(!a[0]);
		fore(i,1,n-k+1){
			if(a[i]&&!a[i-1])c--;
			if(!a[i+k-1]&&a[i+k-2])c++;
			res=min(res,2*c-(!a[i]));
			//cout<<i<<" "<<i+k-1<<": "<<c<<"\n";
		}
		c=0;
		fore(i,0,k){
			if(b[i]==0){
				if(!i||b[i-1])c++;
			}
		}
		ll resi=2*c-(!b[0]);
		fore(i,1,n-k+1){
			if(b[i]&&!b[i-1])c--;
			if(!b[i+k-1]&&b[i+k-2])c++;
			resi=min(res,2*c-(!b[i]));
		}
		//cout<<res<<" "<<resi+1<<"\n";
		cout<<min(res,resi+1)<<"\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
