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
		ll n; cin>>n;
		vector<ll>a(n);
		fore(i,0,n)cin>>a[i];
		vector<ll>b=a; b.pb(-1);
		sort(ALL(b));
		ll mex=b[n]+1;
		fore(i,1,SZ(b)){
			if(b[i]-b[i-1]>1){
				mex=b[i-1]+1;
				break;
			}
		}
		ll l=n+1,r=-1;
		fore(i,0,n)if(a[i]==mex+1){
			l=min(l,i),r=max(r,i);
		}
		//cout<<mex<<" "<<l<<" "<<r<<": ";
		if(r==-1){
			if(mex==n)cout<<"No\n";
			else cout<<"Yes\n";
			continue;
		}
		fore(i,l,r+1)a[i]=mex;
		b=a; b.pb(-1);
		sort(ALL(b));
		ll mex1=b[n]+1;
		//imp(b);
		fore(i,1,SZ(b)){
			//cout<<i<<": "<<b[i]-b[i-1]<<"\n";
			if(b[i]-b[i-1]>1){
				mex1=b[i-1]+1;
				break;
			}
		}
		//cout<<mex1<<" ";
		if(mex1==mex+1)cout<<"Yes\n";
		else cout<<"No\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
