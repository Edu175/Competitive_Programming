#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b; i<jet;i++)
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

#define oper min

const int K=10;
int st[K][1<<K]; int n;
void st_init(vector<int> a){
	// cout<<SZ(a)<<endl;
	fore(i,0,SZ(a)) st[0][i]=a[i];
	fore(k,1,K)fore(i,0,SZ(a)-(1<<k)+1)
		st[k][i]=oper(st[k-1][i],st[k-1][i+(1<<(k-1))]);
}
int st_query(int s,int e){
	int k=31-__builtin_clz(e-s);
	return oper(st[k][s],st[k][e-(1<<k)]);
}

int main(){
	JET
	int m; cin>>n>>m;
	char a[n][m];
	fore(i,0,n)fore(j,0,m) cin>>a[i][j];
	int bajar[n][m];
	int derecha[n][m];
	int noult[n][m];
	fore(i,0,n){
		derecha[i][m-1]=1;
		noult[i][m-1]=1;
		for(ll j=m-2;j>=0;j--){
			if(a[i][j]==a[i][j+1]) derecha[i][j]=derecha[i][j+1]+1;
			else derecha[i][j]=1;
		}
	}
	fore(i,0,m){
		bajar[n-1][i]=1;
		for(ll j=n-2;j>=0;j--){
			if(a[j][i]==a[j+1][i]){
				bajar[j][i]=bajar[j+1][i]+1;
				noult[j][i]=min(derecha[j][i],noult[j+1][i]);
			} 
			else{
				bajar[j][i]=1;
				noult[j][i]=derecha[j][i];
			}
		}
	}
	
	vector<int> ss[m];
	fore(i,0,n){
		fore(j,0,m){
			ss[j].pb(derecha[i][j]);
		}
	}
	ll rta=0;
	// cout<<"\n\n";
	// fore(i,0,n){
	// 	fore(j,0,m)cout<<bajar[i][j]<<" ";
	// 	cout<<"\n";
	// }
	// cout<<"\n\n\n";
	// fore(i,0,n){
	// 	fore(j,0,m)cout<<derecha[i][j]<<" ";
	// 	cout<<"\n";
	// }
	// cout<<"\n\n\n";
	fore(j,0,m){
		st_init(ss[j]);
		fore(i,0,n){
			int f1=bajar[i][j];
			if(i+f1<n && bajar[i+f1][j]==f1 && i+f1+f1<n && bajar[i+f1+f1][j]>=f1 ){
				rta+=min(min(noult[i][j],noult[i+f1][j]),st_query(i+f1+f1,i+f1+f1+f1));
				// cout<<"as "<<derecha[i+f1+f1][j]<<"\n";
				// cout<<"en i: "<<i<<" j:"<<j<<" consegui "<<min(min(derecha[i][j],derecha[i+f1][j]),derecha[i+f1+f1][j])<<"\n";
			}			
		}
	}
	cout<<rta<<"\n";
	return 0;
}



// 4 3
// aaa
// bbb
// ccb
// ddd


// 1 1 1 
// 1 1 2 
// 1 1 1 
// 1 1 1 



// 3 2 1 
// 3 2 1 
// 2 1 1 
// 3 2 1 



// as 2
// en i: 0 j:0 consegui 2
// as 1
// en i: 0 j:1 consegui 1
// as 1
// en i: 0 j:2 consegui 1
// as 3
// en i: 1 j:0 consegui 2
// as 2
// en i: 1 j:1 consegui 1
// 7
