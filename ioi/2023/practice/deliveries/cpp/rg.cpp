#include "deliveries.h"
#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ioi=b;i<ioi;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto asd:v)cout<<asd<<" ";cout<<"\n"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

int main(){
	ll N,W,D; srand((ll)&N); cin>>N>>W>>D;
	ll n=rand()%N+1;
	ll arr[n];
	fore(i,0,n)arr[i]=rand()%D;
	vector<ll>a={0};
	vector<ll>vis(n);
	vis[0]=1;
	vector<ii>ed;
	fore(i,0,n-1){
		ll p=rand()%(n-1-i);
		fore(j,0,n){
			if(vis[j])continue;
			if(!p){
				ed.pb({a[rand()%SZ(a)],j});
				vis[j]=1;
				a.pb(j);
			}
			p--;
		}
	}
	cout<<n<<" 1\n";
	imp(a);
	for(auto [x,y]:ed){
		cout<<x<<" "<<y<<" "<<rand()%W+1<<"\n";
	}
	cout<<"0 "<<arr[0]<<"\n";
	return 0;
}
