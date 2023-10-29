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
	ll n,k; cin>>n>>k;
	ll a[n];
	fore(i,0,n)cin>>a[i];
	sort(a,a+n);
	ll l=0,r=0;
	ll ki=k,res=1,resi=1;
	ll num=a[0];
	while(r<n&&l<n){
		if(resi>res)res=resi,num=a[r];
		if((a[r+1]-a[r])*resi<=ki){
			ki-=(a[r+1]-a[r])*resi;
			//cout<<r+1<<" "<<r<<" "<<a[r+1]-a[r]<<" | ";
			resi++;
			r++;
		}
		else {
			while(l<=r&&(a[r+1]-a[r])*resi>ki){
				resi--;
				ki+=a[r]-a[l];
				l++;
			}
		}
		//cout<<l<<" "<<r<<": "<<resi<<" "<<ki<<"\n";
		if(resi>res)res=resi,num=a[r];
	}
	if(resi>res)res=resi,num=a[r];
	cout<<res<<" "<<num<<"\n";
	return 0;
}
///"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
