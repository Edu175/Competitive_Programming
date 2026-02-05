#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto i:v)cout<<i<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;

void first(){
	ll t; cin>>t;
	while(t--){
		ll n,msg; cin>>n>>msg;
		vector<vv> a(n,vv(n)),b=a;
		fore(i,0,n)fore(j,0,n){
			char c; cin>>c;
			a[i][j]=c-'0';
			b[j][i]=a[i][j];
		}
		vv mn(2),mx(2); // row, column
		fore(w,0,2){
			auto &g=(w?b:a);
			fore(i,0,n){
				if(g[i]<g[mn[w]])mn[w]=i;
				if(g[i]>g[mx[w]])mx[w]=i;
			}
		}
		if(msg){
			cout<<mx[0]+1<<" "<<mn[1]+1<<"\n";
		}
		else {
			cout<<mn[0]+1<<" "<<mx[1]+1<<"\n";
		}
	}
}

void second(){
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		string r,c; cin>>r>>c;
		if(r>=c)cout<<"1\n";
		else cout<<"0\n";
	}
}

int main(){FIN;
	string type; cin>>type;
	if(type=="first")first();
	else second();
	return 0;
}
