#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
#define pres cout<<res<<"\n"
using namespace std;
typedef long long ll;

double pit (pair<ll,ll>p,pair<ll,ll>q){
	ll a=abs(p.fst-q.fst);
	ll b=abs(p.snd-q.snd);
	return sqrt(a*a+b*b);
}

int main(){FIN;
	ll n,k; cin>>n>>k;
	ll l[k];
	pair<ll,ll> a[n];
	fore(i,0,k)cin>>l[i];
	fore(i,0,n)cin>>a[i].fst>>a[i].snd;
	double res=0;
	fore(i,0,n){
		double mini=10000005;
		bool flag=0;
		fore(j,0,k){
			//if(i!=l[j]-1){
				mini=min(mini,pit(a[i],a[l[j]-1]));
				flag=1;
			//}
		}
		if(flag)res=max(res,mini);
	}
	cout<<fixed<<setprecision(15)<<res<<"\n";
	return 0;
}
