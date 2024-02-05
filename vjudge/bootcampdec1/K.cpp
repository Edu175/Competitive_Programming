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
	fore(n,1,101){
		if(n>1)cout<<",\n\n";
		cout<<"{\n";
		if(n==2){
			cout<<"{-1}\n}";
			continue;
		}
		ll a[n][n]={};
		ll cnt=1;
		fore(i,0,n){
			for(ll j=i%2;j<n;j+=2)a[i][j]=cnt++;
		}
		fore(i,0,n){
			for(ll j=(i%2)^1;j<n;j+=2)a[i][j]=cnt++;
		}
		fore(i,0,n){
			cout<<"{";
			fore(j,0,n){
				if(j)cout<<",";
				cout<<a[i][j];
			}
			cout<<"}";
			if(i<n-1)cout<<",";
			cout<<"\n";
		}
		cout<<"}";
	}
	return 0;
}
