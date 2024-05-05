#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef int ll;
typedef pair<ll,ll> ii;
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
vector<int> z_function(string& s){
	int l=0,r=0,n=s.size();
	vector<int> z(s.size(),0); // z[i] = max k: s[0,k) == s[i,i+k)
	fore(i,1,n){
		if(i<=r)z[i]=min(r-i+1,z[i-l]);
		while(i+z[i]<n&&s[z[i]]==s[i+z[i]])z[i]++;
		if(i+z[i]-1>r)l=i,r=i+z[i]-1;
	}
	return z;
}
const ll K=18;//K such that 2^k>n
#define oper max
ll st[K][1ll<<K];
void st_init(vector<int> &a){
	ll n=SZ(a);
	fore(i,0,n)st[0][i]=a[i];
	fore(k,1,K)fore(i,0,n-(1ll<<k)+1)
		st[k][i]=oper(st[k-1][i],st[k-1][i+(1ll<<(k-1))]);
}
ll st_query(int s, int e){
	int k=31-__builtin_clz(e-s);
	return oper(st[k][s],st[k][e-(1<<k)]);
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,l,r; cin>>n>>l>>r; r++;
		string s; cin>>s;
		auto z=z_function(s);
		z[0]=n;
		st_init(z);
		vector<ll>ki(n+1);
		//imp(z);
		fore(k,1,n+1){
			ll p=0;
			while(p<n){
				ll l=p,r=n-1;
				while(l<=r){
					ll m=(l+r)/2;
					if(st_query(p,m+1)>=k)r=m-1;
					else l=m+1;
				}
				if(l==n)break;
				//if(k==2)cout<<p<<" --> "<<l<<"\n";
				ki[k]++;
				p=l+k;
			}
		}
		//imp(ki);
		fore(k,l,r){
			ll s=1,e=n;
			while(s<=e){
				ll m=(s+e)/2;
				if(ki[m]>=k)s=m+1;
				else e=m-1;
			}
			cout<<e<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
