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
template<class x> ostream & operator<<(ostream & out, vector<x> v){
    out<<"{ ";
    for(auto y : v) out<<y<<" ";
    out<<"}";
    return out;
}	

ll n;
ll ask1(ll x){//i1
	if(x<2||x>2*n)return 1;
	cout<<"+ "<<x<<endl;
	ll ret; cin>>ret;
	return ret;
}
ll ask2(ll i, ll j){//i0
	i++,j++;
	cout<<"? "<<i<<" "<<j<<endl;
	ll ret; cin>>ret;
	return ret;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n;
		vector<ll>p(n);
		if(n%2){//i1
			if(ask1(n)==-2)break;
			if(ask1(n+2)==-2)break;
			fore(i,0,n){
				if(i%2)p[i]=n-1-i;
				else p[i]=i;
				p[i]++;
			}
		}
		else {//i1
			if(ask1(n+1)==-2)break;
			if(ask1(n-1)==-2)break;
			fore(i,0,n){
				if(i%2==0)p[i]=n-i;
				else p[i]=i;
			}
		}
		fore(i,0,n)p[i]--;//i0
		//imp(p);
		ll j=ask2(0,1);
		if(j==-2)break;
		ll a[n];
		a[0]=0,a[1]=j;
		ll br=0,d=min(j,(ll)0);
		fore(i,2,n){
			ll x=ask2(1,i);
			if(x==-2){
				br=1;
				break;
			}
			ll y=ask2(0,i);
			if(y==-2){
				br=1;
				break;
			}
			vector<ll>v={-y,y,j-x,j+x};
			sort(ALL(v));
			//cout<<i<<": "<<v<<"\n";
			fore(h,1,SZ(v))if(v[h]==v[h-1])a[i]=v[h];
			d=min(d,a[i]);
		}
		if(br)break;
		/*imp(a);
		cout<<d<<"\n";
		for(auto i:a)cout<<i-d<<" ";
		cout<<"\n";*/
		/*vector<ll>h(n);
		fore(i,0,n)h[a[i]-d]=i;
		imp(h);*/
		ll res[2][n];
		fore(i,0,n)res[0][i]=p[a[i]-d];
		reverse(ALL(p));
		fore(i,0,n)res[1][i]=p[a[i]-d];
		cout<<"! ";
		fore(i,0,2)fore(j,0,n)cout<<res[i][j]+1<<" ";
		cout<<endl;
		ll ret; cin>>ret;
		if(ret==-2)break;
	}
	return 0;
}
//"¿Sabes qué es más genial que la magia? Matemáticas". - Spider-Man: No Way Home
//"You know what's cooler than magic? Math". - Spider-Man: No Way Home
