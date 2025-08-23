#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define pb push_back
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define mset(a,v) memset((a),(v),sizeof(a))
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
string RGB="RGB";
const ll INF=1e11;
int main(){
	JET
	ll n; cin>>n;
	ii a[n]; fore(i,0,n) {
		cin>>a[i].fst;
		char x; cin>>x;
		fore(j,0,3) if(RGB[j]==x) a[i].snd=j;
	}
	ll f=INF,u[3]; mset(u,-1);
	ll r=0;
	fore(i,0,n){
		if(a[i].snd!=1) continue;
		if(u[1]==-1){f=i; u[1]=i; continue;}
		r+=a[i].fst-a[u[1]].fst;
		u[1]=i;
	}
	r*=3;
	ll m[3]; fore(i,0,3) m[i]=0;
	fore(i,0,n){
		if(a[i].snd!=1)if(u[a[i].snd]==-1){u[a[i].snd]=i; continue;}
		if(i<=f){
			if(a[i].snd==1) {
				fore(j,0,3) if(j!=1)if(u[j]!=-1){
					r+=a[i].fst-a[u[j]].fst;
				}
				fore(j,0,3)if(j!=1) u[j]=i;
				continue;	
			}
			
			r+=a[i].fst-a[u[a[i].snd]].fst;
			u[a[i].snd]=i;
			continue;
		}
		if(i>=u[1]){
			if(a[i].snd==1) {
				fore(j,0,3)if(j!=1)if(u[j]!=-1){m[j]=max(m[j],a[i].fst-a[u[j]].fst);}
			fore(j,0,3)if(j!=1){r-=m[j]; m[j]=0; u[j]=i;}
				continue;
			}
			r+=a[i].fst-a[u[a[i].snd]].fst;
			u[a[i].snd]=i;
			continue;
		}
		
		if(a[i].snd==1) {
			fore(j,0,3)if(j!=1){m[j]=max(m[j],a[i].fst-a[u[j]].fst);}
			fore(j,0,3)if(j!=1){r-=m[j]; m[j]=0; u[j]=i;}
			continue;
		}
		m[a[i].snd]=max(m[a[i].snd],a[i].fst-a[u[a[i].snd]].fst);
		u[a[i].snd]=i;
	}
	cout<<r<<"\n";
	return 0;
}