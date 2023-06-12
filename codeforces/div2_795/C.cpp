#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(long long i=a,ggdem=b;i<ggdem;++i)
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
		string s; cin>>s;
		ll l,r;
		ll u=0;
		ll fl=0;
		fore(i,0,n){
			if(s[i]=='1'){
				u++;
				if(!fl)l=i,fl=1;
				r=i;
			}
		}
		ll res=u*11;
		ll flag=0;
		if(res){
			if(n-1-r<=k)res-=10,k-=n-1-r,flag=1;
			if(r!=l||!flag){
				if(l<=k)res--;
			}
		}
		cout<</*l<<" "<<r<<" "<<k<<" "<<*/res<<"\n";
	}
	return 0;
}
