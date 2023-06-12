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
ll dis(ii p1,ii p2){
	ll x= (p2.fst-p1.fst);
	ll y=p2.snd-p1.snd;
	return x*x+y*y;
}
bool is_sq(vector<ll>v){
	vector<pair<ll,ll>>p(4);
	fore(i,0,SZ(v)){
		p[i].fst=v[i]/9,p[i].snd=v[i]%9;
	}
	map<ll,ll>mp;
	fore(i,0,4){
		fore(j,i+1,4)mp[dis(p[i],p[j])]++;
	}
	
	if(SZ(mp)!=2)return 0;
	/*for(auto i:p)cout<<i.fst<<","<<i.snd<<" ";
	cout<<"\n";
	for(auto i:mp)cout<<i.fst<<","<<i.snd<<" ";
	cout<<"\n\n";*/
	ll a[2];ll j=0;
	for(auto i:mp){
		a[j]=i.snd,j++;
	}
	if(a[1]>a[0])swap(a[1],a[0]);
	//cout<<a[1]<<" "<<a[0]<<"\n";
	return (a[1]==2&&a[0]==4);
}

int main(){//FIN;
	ll n=81;
	char a[n];
	fore(i,0,n)cin>>a[i];
	ll res=0;
	fore(i,0,n){
		if(a[i]=='.')continue;
		fore(j,i+1,n){
			if(a[j]=='.')continue;
			fore(k,j+1,n){
				if(a[k]=='.')continue;
				fore(l,k+1,n){
					if(a[l]=='.')continue;
					if(is_sq({i,j,k,l}))res++;//,cout<<i<<" "<<j<<" "<<k<<" "<<l<<"\n";
				}
			}
		}
	}
	cout<<res<<"\n";
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
