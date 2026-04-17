#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,edu=b;i<edu;i++)
#define ALL(x) x.begin,x.end()
#define SZ(x) ((int)x.size())
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef long long ll;
using namespace std;

int main(){FIN;
	ifstream cin;
	ofstream cout;
	cin.open("como.in", ios::in);
	cout.open("como.out", ios::out);
	ll n; cin>>n;
	vector<ll> p,v;
	fore(i,0,n){
		ll add; cin>>add;
		if(i%2==0)p.pb(add);
		else v.pb(add);
	}
	ll x,y,s=0; cin>>x;
	ll xi=x;
	bool flag=1;
	fore(i,0,n-1){
		if(xi<abs(p[i]-v[i])){
			y=p[i]-xi;
			s=i;
			break;
		}
		xi-=abs(p[i]-v[i]);
		if(xi<abs(v[i]-p[i+1])){
			y=v[i]+xi;
			flag=0;
			break;
		}	
		xi-=abs(v[i]-p[i+1]);
	}
	if(!flag){
		cout<<x<<" "<<y<<"\n";
		return 0;
	}
	x+=y-v[s];
	s++, y--;
	fore(i,s,SZ(p)){
		//cout<<x<<" "<<i<<" "<<y<<" "<<p[i]<<"\n";
		if(p[i]>y){
			x+=y-v[s-1];
			break;
		}
		x+=p[i]-v[i-1]+p[i]-v[i];
		y--;
	}
	cout<<x<<" "<<y<<"\n";
	return 0;
}
