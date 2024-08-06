#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<gdljh<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=2005;
int uf[MAXN];
void uf_init(){mset(uf,-1);}
int uf_find(int x){return uf[x]<0?x:uf[x]=uf_find(uf[x]);}
bool uf_join(int x, int y){
	x=uf_find(x);y=uf_find(y);
	if(x==y)return false;
	if(uf[x]>uf[y])swap(x,y); // y -> x
	uf[x]+=uf[y];uf[y]=x;
	return true;
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll>a(n);
		fore(i,0,n)uf[i]=-1;
		fore(i,0,n)cin>>a[i];
		vector<ii>res;
		for(ll x=n-1;x;x--){
			vector<ll>v(x,-1);
			fore(i,0,n){
				ll j=v[a[i]%x];
				if(j!=-1&&uf_find(i)!=uf_find(j)){
					uf_join(i,j);
					res.pb({i,j});
					break;
				}
				v[a[i]%x]=i;
			}
		}
		reverse(ALL(res));
		cout<<"YES\n";
		for(auto i:res)cout<<i.fst+1<<" "<<i.snd+1<<"\n";
	}
	return 0;
}
