#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define pb push_back
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define SZ(x) ((ll)x.size())
#define ALL(x) x.begin(),x.end()
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

int main(){
	JET
	ll n,m,k; cin>>n>>m>>k;
	vector<ll>r(n,-1),c(m,-1);
	fore(i,0,k){
		ll x,y; cin>>x>>y; x--,y--;
		r[x]=max(r[x],y);
		c[y]=max(c[y],x);
	}
	ll x=n-1,y=m-1;
	ll res=1;
	while(x>=0&&y>=0){
		if(r[x]>=y)x--;
		else if(c[y]>=x)y--;
		else {
			if(x==0&&y==0)res=0;
			x--,y--;
		}
	}
	if(res)cout<<"Chaneka\n";
	else cout<<"Bhinneka\n";
	return 0;
}