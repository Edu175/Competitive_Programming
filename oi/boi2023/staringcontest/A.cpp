#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,boi=b;i<boi;i++)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define imp(v) for(auto skdauf:v)cout<<skdauf<<" ";cout<<"\n"
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
const ll MAXN=1505;
ll a[MAXN];

ll ask(ll i, ll j){
	cout<<"? "<<a[i]+1<<" "<<a[j]+1<<endl;
	ll ret; cin>>ret;
	return ret;
}

int main(){FIN;
	ll n; srand(175); cin>>n;
	fore(i,0,n)a[i]=i;
	random_shuffle(a,a+n);
	ll x=0,y=1,c=ask(x,y);
	vector<ll>res(n);
	fore(i,2,n){
		ll z=i,d=ask(x,z);
		ll _x=x,_y=y,_z=z;
		if(d<c)res[a[z]]=d;
		if(d==c)res[a[x]]=c,x=_y,y=_z,c=ask(x,y);
		if(d>c)res[a[y]]=c,y=_z,c=d;
	}
	res[a[x]]=c,res[a[y]]=c;
	cout<<"! ";
	fore(i,0,n)cout<<res[i]<<" ";
	cout<<endl;
	return 0;
}
