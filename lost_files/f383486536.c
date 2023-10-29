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
	ll n; cin>>n;
	vector<ll> a(n);
	//vector<ll>sp(n+1);
	//vector<ll>p;
	vector<ll>c(3);
	ll s=0,is=0;
	ll res=0;
	fore(i,0,n){
		cin>>a[i];
		if(i&&(i==n-1||!a[i])){
			//cout<<s<<","<<i<<": "<<is<<"\n";
			//imp(c);
			if(a[s]){
				is=1;
				res++;
			}
			else if(a[i]){
				is=1;
				res++;
			}
			else if(s==i-1){
				if(!is)res++;
				is=0;
			}
			else if(c[2]){
				is=1;
				res++;
			}
			else {
				res++;
			}
			s=i;
			c[0]=1,c[1]=0,c[2]=0;
		}
		else c[a[i]]++;
	}
	res+=(!is);
	cout<<res<<"\n";
	return 0;
}
