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
const ll MAXN=50005;
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
fore(n,2,MAXN)if(n%2==0){
	cout<<n<<endl;
	//ll n; cin>>n;
	uf_init();
	vector<ll> to(n,-1);
	fore(i,0,n/2){
		ll a=i,b=i+n/2,c=(2*i)%n,d=(2*i-1+n)%n;
		assert(uf_find(a)!=uf_find(b));
		//cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
		if(uf_find(a)!=uf_find(c)&&uf_find(b)!=uf_find(d)){
			//cout<<a<<"--"<<c<<" "<<b<<"--"<<d<<endl;
			to[a]=c,to[b]=d;
			uf_join(a,c);
			uf_join(b,d);
		}
		else {
			assert(uf_find(a)!=uf_find(d)&&uf_find(b)!=uf_find(c));
			//cout<<a<<"--"<<d<<" "<<b<<"--"<<c<<endl;
			to[a]=d,to[b]=c;
			uf_join(a,d);
			uf_join(b,c);
		}
	}
	/*cout<<"0";
	for(ll x=to[0];x;x=to[x])cout<<" "<<x;
	cout<<"\n";*/
}
	return 0;
}
