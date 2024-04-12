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
		ll k; cin>>k;
		ll n=1ll<<k;
		vector<ll>a(n),pos(n);
		fore(i,0,n)cin>>a[i],a[i]--,pos[a[i]]=i;
		vector<ll>res(k+1,n+5);
		vector<ll>st(4ll<<k);
		for(ll x=n-1;x>=0;x--){
			ll p=1,s=0,t=0;
			// cout<<x<<":\n";
			while(p<2*n){
				// cout<<t<<"| "<<p<<" "<<s<<" = "<<st[p]+s<<" | "<<st[2*p]<<" , "<<st[2*p+1]<<"\n";
				if(st[p]+s==0){res[t]=min(res[t],x);break;}
				if(p>=n)break;
				t++;
				ll l=st[2*p],r=st[2*p+1];
				if(l==r){
					p=2*p;
					s/=2;
				}
				if(l<r){
					ll d=r-l-1;
					s++;
					if(s>=d)s=d+(s-d)/2;
					p=2*p;
				}
				if(l>r){
					ll d=l-r-1;
					s++;
					if(s>=d)s=d+(s-d)/2;
					p=2*p+1;
				}
			}
			p=pos[x]+n;
			while(p)st[p]++,p/=2;
		}
		// fore(t,1,k+1)cout<<(1ll<<k)-(1ll<<t)+1<<" ";;cout<<"\n";
		//imp
		ll mn=n+5;
		fore(i,1,k+1){
			mn=min(mn,res[i]);
			cout<<mn+1<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
