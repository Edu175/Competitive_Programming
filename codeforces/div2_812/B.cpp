#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) for(auto edu:v)cout<<edu<<" "; cout<<"\n"
#define pres cout<<res<<"\n"
using namespace std;
typedef long long ll;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		vector<ll>a(n);
		ll maxi=0;
		ll l,r;
		fore(i,0,n){
			cin>>a[i];
			if(a[i]>maxi)maxi=a[i],l=i,r=i;
		}
		vector<ll>b=a;
		sort(ALL(b));
		reverse(ALL(b));
		ll flag=1;
		ll j=1;
		//imp(a);
		//imp(b);
		while(j<n&&flag&&(l||r<n-1)){
			//cout<<l-1<<" "<<r+1<<" "<<j<<": ";
			ll fi=0;
			if(l>0){
				if(a[l-1]==b[j])j++,l--,fi=1;//,cout<<l<<"\n";
			}
			if(r<n-1){
				if(a[r+1]==b[j])j++,r++,fi=1;//,cout<<r<<"\n";
			}
			if(fi==0)flag=0;
		}
		if(flag)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
