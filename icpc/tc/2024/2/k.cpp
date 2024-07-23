#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define ALL(x) x.begin(),x.end()
#define SZ(x) (ll)x.size()
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
ii a[100];
int main(){
	JET
	
		int n; cin>>n;
		fore(i,0,n) {cin>>a[i].fst; a[i].snd=i;}
		sort(a,a+n);
		int m;
		cin>>m;
		fore(i,0,m){
			int k, pos; 
			cin>>k>>pos;pos--;
			vector <ii> b; int sz=-1;
			fore(i,0,k){
				b.pb(a[n-1-i]); sz++; swap(b[sz].fst, b[sz].snd);
			}
			sort(ALL(b));
			cout<<b[pos].snd<<"\n";
			
		}
	}