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
const ll MAXN=2e5+5;

// _Find_first()
int main(){FIN;
	ll n; cin>>n;
	vector<ll>a(n);
	fore(i,0,n)cin>>a[i];
	bitset<MAXN>b;
	//cout<<b._Find_first()<<"\n";
	b[0]=1;
	ll res=0,sum=0;//,mini=MAXN*3;
	fore(i,0,MAXN){
		if(sum<i)break;
		if(i<n)sum+=a[i];
		if(b[i])res=max(res,sum-i);
		//mini=min(mini,(ll)(b>>(n-a[i]))._Find_first()+n);
		/*cout<<i<<":\n";
		fore(i,0,n)cout<<b[i];
		cout<<"\n";*/
		if(i<n)b|=b<<a[i],b[i]=0;
		/*fore(i,0,n)cout<<b[i];
		cout<<"\n\n";*/
		
	}
	//fore(i,0,n)cout<<b[i];
	//cout<<"\n";
	//if(mini<n+MAXN)res=max(res,sum-mini);
	cout<<res<<"\n";
	return 0;
}
