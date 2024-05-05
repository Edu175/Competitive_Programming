#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<endl;}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k,pos[2]; cin>>n>>k>>pos[0]>>pos[1];
		vector<ll>a(n),p(n);
		fore(i,0,n)cin>>p[i],p[i]--;
		fore(i,0,n)cin>>a[i];
		//imp(a);
		//imp(p);
		ll s[2]={0,0};
		ll _k=k;
		fore(h,0,2){
			vector<ll>vis(n);
			ll x=pos[h]; x--;
			k=_k;
			ll res=k*a[x];
			ll sum=a[x];
			vis[x]=1; x=p[x]; k--;
			while(!vis[x]&&k){
				vis[x]=1;
				res=max(res,sum+k*a[x]);
				sum+=a[x];
				x=p[x];
				k--;
			}
			s[h]=res;
		}
		//cout<<s[0]<<" "<<s[1]<<"\n";
		if(s[0]>s[1])cout<<"Bodya\n";
		if(s[0]<s[1])cout<<"Sasha\n";
		if(s[0]==s[1])cout<<"Draw\n";
		//cout<<endl;
	}
	return 0;
}
