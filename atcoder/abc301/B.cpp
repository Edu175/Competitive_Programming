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

int main(){FIN;
	ll n; cin>>n;
	vector<ll>a(n);
	fore(i,0,n)cin>>a[i];
	fore(i,0,n-1){
		//cout<<"iii "<<i<<": ";
		cout<<a[i]<<" ";
		if(a[i]<a[i+1]){
			for(ll j=a[i]+1;j<a[i+1];j++)cout<<j<<" ";
		}
		else{
			for(ll j=a[i]-1;j>a[i+1];j--)cout<<j<<" ";
		}
	}
	cout<<a[n-1]<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
