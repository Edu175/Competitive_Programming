#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto messi:v)cout<<messi<<" "; cout<<endl
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=2e5+5;

ll a[MAXN],p[MAXN],vis[MAXN];

vector<ll>s;
void sw(ll i, ll j){
	vis[i]=vis[j]=1;
	s.pb(i),s.pb(j);
	swap(p[a[i]],p[a[j]]);
	swap(a[i],a[j]);
}

int main(){FIN;
	ll n; cin>>n;
	fore(i,0,n)cin>>a[i],a[i]--,p[a[i]]=i;
	vector<vector<ll>>res;
	while(1){
		//fore(i,0,n)cout<<a[i]<<" ";;cout<<endl;
		mset(vis,0);
		s.clear();
		fore(x,0,n){
			if(a[x]==x)continue;
			for(auto i=x;;){
				/*cout<<i<<": ";
				fore(i,0,n)cout<<a[i]<<" ";;cout<<endl;
				fore(i,0,n)cout<<vis[i]<<" ";;cout<<endl;*/
				if(p[i]==a[i]){
					if(!vis[i]&&!vis[p[i]])sw(i,p[i]);
					break;
				}
				ll pi=p[i];
				sw(p[i],a[i]);
				i=pi;
			}
		}
		/*imp(s);
		cout<<endl;*/
		if(!SZ(s))break;
		res.pb(s);
	}
	cout<<SZ(res)<<"\n";
	for(auto v:res){
		cout<<SZ(v)/2<<"\n";
		fore(i,0,SZ(v))if(i%2==0)cout<<v[i]+1<<" "<<v[i+1]+1<<"\n";
	}
	return 0;
}
