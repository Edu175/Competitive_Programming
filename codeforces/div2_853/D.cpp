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
const ll MAXN=2e3+5;

vector<ll>a; ll n;
ll op(ll x, ll y){//con x cambio y
	ll k=x-y;
	vector<ll>b=a;
	fore(i,0,n){
		b[i]=b[i]^(i+k>=n||i+k<0?0:a[i+k]);
	}
	a=b;
	//imp(a);
	return k;
}
int main(){FIN;
	ll t; cin>>t;
	while(t--){
		//cout<<"scan\n";
		cin>>n;
		a.resize(n);
		string s; cin>>s;
		fore(i,0,n)a[i]=s[i]-'0';
		vector<ll>b(n);
		cin>>s;
		ll flag=0;
		fore(i,0,n){
			b[i]=s[i]-'0';
			if(b[i])flag=1;
		}
		//cout<<"p\n";
		ll p=0;
		while(p<n&&a[p]==0)p++;
		if(a==b){
			cout<<"0\n";
			continue;
		}
		if(p==n||!flag){
			cout<<"-1\n";
			continue;
		}
		//cout<<"res u\n";
		vector<ll>res;
		ll u=-1;
		fore(i,0,n)if(b[i])u=i;
		//cout<<p<<" "<<u<<"\n";
		if(u<=p){// p b, u a
			//cout<<"reves\n";
			fore(i,0,n)if(b[i]){
				p=i;
				break;
			}
			fore(i,0,n)if(a[i])u=i;
			for(ll i=p;i>=0;i--)if(a[i]!=b[i])res.pb(op(u,i));
			fore(i,p+1,n)if(a[i]!=b[i])res.pb(op(p,i));
		}
		else{
			fore(i,u,n)if(a[i]!=b[i])res.pb(op(p,i));
			for(ll i=u-1;i>=0;i--)if(a[i]!=b[i])res.pb(op(u,i));
		}
		cout<<SZ(res)<<"\n";
		imp(res);
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
