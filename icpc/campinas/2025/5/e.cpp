#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
vector<ii> a; 

bool can(int x){
	ll acc=a[x].fst;
	fore(i,0,SZ(a)){
		if(x==i) continue;
		if(a[i].fst>=acc) return false;
		acc+=a[i].fst;
	}
	return true;
}

int main(){
	JET
	int n; cin>>n;
	a.resize(n);
	bool b=true;
	int valor=-1;;
	fore(i,0,n){
		cin>>a[i].fst;
		a[i].snd=i;
		if(valor!=-1 && valor!=a[i].fst) b=false;
		valor=a[i].fst;
	}
	if(b){
		fore(i,0,n) cout<<'N';
		cout<<"\n";
		return  0;
	}	
	sort(ALL(a));
	ll l=0, r=n-1;
	char rta[n];
	fore(i,0,n) rta[i]='T';
	while(l<r){
		ll m=(l+r)/2;
		if(can(m)) r=m;
		else l=m+1;
	}
	fore(i,0,r){
		rta[a[i].snd]='N';
	}
	for(auto x:rta) cout<<x;
	cout<<"\n";
	return 0;
}