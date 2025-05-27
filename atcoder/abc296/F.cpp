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

int main(){FIN;
	ll n; cin>>n;
	vector<ll>a(n),b(n);
	vector<ll>oc(n);
	ll flag=0;
	fore(i,0,n){
		cin>>a[i],a[i]--,oc[a[i]]++;
		if(oc[a[i]]==2)flag++;
	}
	fore(i,0,n)cin>>b[i],b[i]--;
	vector<ll>as=a,bs=b;
	sort(ALL(as)),sort(ALL(bs));
	//cout<<"ifs\n";
	if(as!=bs){
		cout<<"No\n";
		return 0;
	}
	if(flag>0){
		cout<<"Yes\n";
		return 0;
	}
	vector<ii>c;
	fore(i,0,n)c.pb({a[i],b[i]});
	sort(ALL(c));
	ll q=0;
	vector<ll>vis(n);
	fore(x,0,n)if(!vis[x]){
		q++;
		for(ll y=x;!vis[y];y=c[y].snd)vis[y]=1;
	}
	// cout<<q<<" "<<n-q<<": ";
	if((n-q)%2==0)cout<<"Yes\n";
	else cout<<"No\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
