#include<bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define fst first
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define pb push_back
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;
random_device rd;
mt19937 rng(rd());


int n;
int main(){
	ll t; cin>>t;
	while(t--){
		cin>>n;
		assert(n!=-1);
		int x,y,z;
		x = rng()%n;
		do{
			y = rng()%n;
		} while(x==y);
		do{
			z = rng()%n;
		}while(z==y || z==x);
		fore(i,0,75){
			cout<<"? "<<x+1<<" "<<y+1<<" "<<z+1<<endl;
			int a;
			cin>>a;
			if(a==0) break;
			int r = rng()%3;
			if(r==0) x=a-1;
			else if(r==1) y =a-1;
			else z = a-1;
		}
		cout<<"! "<<x+1<<" "<<y+1<<" "<<z+1<<endl;
	}
	return 0;
}