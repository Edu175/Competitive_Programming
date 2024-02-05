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
		ll n,k,d; cin>>n>>k>>d;
		vector<ll>a(n),v(k);
		fore(i,0,n)cin>>a[i];
		fore(i,0,k)cin>>v[i],v[i]--;
		vector<ll>h(n);
		fore(i,0,k)h[v[i]]++;
		vector<ll>s(n);
		s[n-1]=h[n-1];
		for(ll i=n-2;i>=0;i--)s[i]=s[i+1]+h[i];
		map<ll,ll>mp;
		fore(i,0,n){
			ll x=i+1-a[i];
			if(x<0)continue;
			if(x==0){
				mp[0]++;
				continue;
			}
			if(s[i]==0)continue;
			ll r=(x/s[i])*k;
			x%=s[i];
			if(x==0)x=s[i],r-=k;
			fore(j,0,k){
				x-=v[j]>=i;
				if(x==0){
					r+=j+1;
					break;
				}
			}
			mp[r]++;
		}
		ll res=(d-1)/2;
		for(auto i:mp)if(i.fst<d){
			//cout<<i.fst<<" "<<i.snd<<": "<<i.snd+(d-i.fst-1)/2<<"\n";
			res=max(res,i.snd+(d-i.fst-1)/2);
		}
		cout<<res<<"\n";
	}
	return 0;
}
