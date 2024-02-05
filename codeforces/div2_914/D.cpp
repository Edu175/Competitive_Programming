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
typedef pair<ll,ll> ii;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll>a(n),b(n);
		fore(i,0,n)cin>>a[i],a[i]--;
		fore(i,0,n)cin>>b[i],b[i]--;
		vector<ll>vis(n);
		ll flag=1;
		fore(v,0,n){
			fore(i,0,n){
				if(b[i]==v){
					if(vis[i])continue;
					ll l=i,r=i;
					while(l>0&&vis[l-1]==0&&a[l-1]<=v)l--;
					while(r<n-1&&vis[r+1]==0&&a[r+1]<=v)r++;
					ll did=0;
					fore(j,l,r+1)if(a[j]==v)did=1;
					//cout<<v<<" "<<i<<": "<<l<<" "<<r<<": "<<did<<"\n";
					if(!did)flag=0;
					fore(j,l,r+1)if(b[j]==v)vis[j]=1;
				}
			}
		}
		if(flag)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
