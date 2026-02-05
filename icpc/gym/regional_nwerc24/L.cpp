#include <bits/stdc++.h> 
#define fore(i,a,b) for(ll i = a,jet = b;i<jet;i++)
#define snd second 
#define fst first
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll) x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
const int maxn=2e5+5;
int n,m,x,y; 
int a[maxn],b[maxn];
bool can(int h){
	vv cnt(n);
	fore(i,0,n){
		cnt[i]=(i<h?y:x);
	}
	
	for(int i=m-1; i>=0; i--){
		if(!SZ(cnt)||a[SZ(cnt)-1]<b[i]) return false;
		if(!--cnt.back()) cnt.pop_back();
	}
	return true;
}
int main(){
	JET
	cin>>n>>m>>x>>y;
	fore(i,0,n)cin>>a[i];
	sort(a,a+n);
	
	fore(i,0,m)cin>>b[i];	
	sort(b,b+m);
	
	int l=0, r=n;
	while(l<=r){
		int h=(l+r)>>1;
		if(can(h)) l=h+1;
		else r=h-1;	
	}
	if(r<0) cout<<"impossible\n";
	else cout<<r<<"\n";
	return 0;
}