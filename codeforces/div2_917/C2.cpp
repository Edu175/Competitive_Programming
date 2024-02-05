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
		ll cnt=0;
		fore(i,0,n)if(a[i]<i+1&&s[i])cnt++;
		ll res=(d-1)/2;
		fore(i,0,n)res+=a[i]==i+1;
		ll c=0;
		while(cnt){
			vector<ll>ai=a;
			fore(i,0,n)ai[i]+=s[i];
			fore(i,0,n)if(a[i]<i+1&&ai[i]>=i+1){
				ll r=0,q=i+1-a[i];
				vector<ll>hi(n);
				fore(j,0,k){
					q-=v[j]>=a[i];
					hi[v[j]]++;
					if(!q){
						r=j+1;
						break;
					}
				}
				ll sum=0,resi=0;
				for(ll i=n-1;i>=0;i--){
					sum+=hi[i];
					resi+=(a[i]+sum==i+1);
				}
				resi+=(d-(c+r)-1)/2;
				if(c+r<d)res=max(res,resi);
				cnt--;
			}
			a=ai,c+=k;
		}
		cout<<res<<"\n";
	}
	return 0;
}
