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
	ll n,k; cin>>n>>k;
	string s; cin>>s;
	ll a[n],seg=0;
	vector<ll>c(2);
	fore(i,0,n){
		a[i]=(s[i]=='Y');
		c[a[i]]++;
		if(a[i]&&(!i||!a[i-1]))seg++;
	}
	vector<ll>gap;
	//cout<<seg<<"\n";
	if(k>=c[0]){
		//cout<<"pasa\n";
		k-=c[0];
		c[1]=n-k;
		seg=(c[1]>0);
		ll q=0,flag=0;
		//cout<<"upd ";
		ll p=0,j=n-1;
		while(p<n&&a[p])p++;
		while(j>=0&&a[j])j--;
		ll np=min(p+n-1-j,n);
		fore(i,0,n-1){
			if(!a[i])flag=1;
			if(a[i]&&flag){
				q++;
				if(!a[i+1])gap.pb(q),q=0;//,cout<<i<<" ";
			}
		}
		//cout<<"\n";
		sort(ALL(gap));
		reverse(ALL(gap));
		k-=np;
		fore(i,0,SZ(gap)){
			if(!gap[i])continue;
			if(k>0)seg++;
			k-=gap[i];
		}
	}
	else{
		if(!c[1]&&k)seg=1;
		c[1]+=k;
		ll q=0,flag=0;
		//cout<<"upd ";
		fore(i,0,n-1){
			if(a[i])flag=1;
			if(!a[i]&&flag){
				q++;
				if(a[i+1])gap.pb(q),q=0;//,cout<<i<<" ";
			}
		}
		//cout<<"\n";
		sort(ALL(gap));
		fore(i,0,SZ(gap)){
			if(!gap[i])continue;
			k-=gap[i];
			if(k>=0)seg--;
		}
	}
	//imp(gap);
	//cout<<c[1]<<" "<<seg<<"\n";
	cout<<c[1]-seg<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
