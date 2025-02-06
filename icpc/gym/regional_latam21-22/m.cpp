#include <bits/stdc++.h>
#define  fore(i,a,b) for(ll i=a, jet=b; i<jet; i++)
#define pb push_back
#define fst first 
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define ET ios::sync_with_stdio(0);cout.tie(0);cin.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
typedef ll node;
const ll INF=1e9+5;

int main(){
	ET
	ll n; cin>>n;
	vector<ii>a(n),sa;
	fore(i,0,n)cin>>a[i].snd>>a[i].fst,sa.pb({a[i].fst,i});
	sort(ALL(sa));
	vv pos(n);
	fore(i,0,n)pos[sa[i].snd]=i;
	vv st(n);
	ll sum=0;
	fore(i,0,n){
		ll idx=sa[i].snd;
		sum+=a[idx].snd;
		st[i]=a[idx].fst-sum;
	}
	vv res(n),vis(n);
	fore(i,0,n){
		vv minp(n+1);minp[0]=INF;
		fore(j,1,n+1)minp[j]=min(minp[j-1],st[j-1]);
		if(minp.back()<0){cout<<"*\n";return 0;}
		fore(j,0,n)if(!vis[j]){
			if(minp[pos[j]]>=a[j].snd){
				res[i]=j;
				vis[j]=1;
				st[pos[j]]=INF;
				fore(k,0,pos[j])st[k]-=a[j].snd;
				break;
			}
		}
	}
	for(auto i:res)cout<<i+1<<" ";;cout<<"\n";
}