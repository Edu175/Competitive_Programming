#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=(1ll<<15)+5;
int uf[MAXN];
void uf_init(){memset(uf,-1,sizeof(uf));}
int uf_find(int x){return uf[x]<0?x:uf[x]=uf_find(uf[x]);}
bool uf_join(int x, int y){
	x=uf_find(x);y=uf_find(y);
	if(x==y)return false;
	if(uf[x]>uf[y])swap(x,y); // y -> x
	uf[x]+=uf[y];uf[y]=x;
	return true;
}

int main(){FIN;
	ll B; cin>>B;
	uf_init();
	ll n=1ll<<B;
	vector<ll>to(n,-1);
	fore(i,0,n/2){
		ll a=i,b=i+n/2,c=(2*i)%n,d=(2*i+1)%n;
		if(uf_find(a)!=uf_find(c))to[a]=c,to[b]=d,uf_join(a,c),uf_join(b,d);
		else to[a]=d,to[b]=c,uf_join(a,d),uf_join(b,c);
	}
	string s(B,'0');
	for(ll x=to[0];x;x=to[x])s.pb('0'+(x&1));
	cout<<s<<"\n";
	return 0;
}
