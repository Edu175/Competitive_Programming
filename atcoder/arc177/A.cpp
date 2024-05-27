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
typedef long long ll;
typedef pair<ll,ll> ii;
vector<ll>p={500,100,50,10,5,1};
int main(){FIN;
	ll c[6];
	fore(i,0,6)cin>>c[i];
	reverse(c,c+6);
	ll n; cin>>n;
	vector<ll>a(n);
	fore(i,0,n)cin>>a[i];
	ll flag=1;
	fore(i,0,n){
		fore(j,0,6){
			while(c[j]&&a[i]>=p[j])a[i]-=p[j],c[j]--;
		}
		flag&=a[i]==0;
	}
	if(flag)cout<<"Yes\n";
	else cout<<"No\n";
	return 0;
}
