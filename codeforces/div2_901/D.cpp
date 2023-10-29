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
const ll MAXN=5005,INF=1e5;

ll dp[MAXN];
ll a[MAXN];//,oc[MAXN];

ll f(ll mex){
	ll &res=dp[mex];
	if(res!=-1)return res;
	if(mex==0)return res=0;
	res=INF;
	ll q=1;
	for(ll i=mex-1;i>=0;i--){
		if(!i||a[i]!=a[i-1]){
			ll nw=(!i?0:a[i-1]+1);
			res=min(res,(a[mex-1]+1)*(q-1)+nw+f(i));
			//cout<<mex<<" "<<i<<": "<<q<<": "<<(a[mex-1]+1)*(q-1)+nw<<"\n";
			q=1;
		}
		else q++;
	}
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		fore(i,0,n+3){
			dp[i]=-1;
		}
		fore(i,0,n)cin>>a[i];
		sort(a,a+n);
		//a[n]=a[n-1]+1;
		ll mex=0,pos=n;
		fore(i,0,n){
			if(a[i]==mex)mex++;
			else if(a[i]>mex){
				pos=i;
				break;
			}
		}
		//fore(i,0,n)cout<<a[i]<<" ";
		//cout<<"\n";
		//cout<<pos<<"\n";
		cout<<f(pos)<<"\n";
	}
	return 0;
}
