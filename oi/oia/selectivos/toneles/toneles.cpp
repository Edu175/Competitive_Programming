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

int main(){FIN;
	ifstream cin;   cin.open("toneles.in", ios::in);
	ofstream cout; cout.open("toneles.out", ios::out);
	ll l,n; cin>>l>>n;
	vector<ll> a(n+1);
	queue<ll>q;
	fore(i,0,n){
		cin>>a[i];
		if(a[i]!=l)q.push(i);
	}
	q.push(n);
	ll res=0,f=-1;
	fore(i,0,n){
		//cout<<i<<": "; imp(a);
		//if(!a[i])continue;
		ll e=-1; //ll db=res;
		if(q.front()==i)q.pop();
		while(a[i]){
			ll w=q.front(),x=(w==n?a[i]:min(a[i],l-a[w]));
			a[w]+=x; if(w!=n&&a[w]==l)q.pop();
			a[i]-=x;
			e=w;
		}
		if(e!=-1)res+=e-i;
		if(f==-1&&e!=-1)f=e;
		//cout<<e<<" "<<e-i<<"\n";
	}
	//imp(a);
	cout<<res<<"\n"<<f<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
