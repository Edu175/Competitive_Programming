#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,jet=b;i<jet;i++)
#define SZ(x) ((int) x.size())
#define ALL(x) x.begin(),x.end();
#define mset(a,v) memset((a),(v),sizeof(a))
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
const int MAXN=1e5;
int UF[MAXN];
ii A[MAXN];
void init(){mset(UF,-1);}
ii ufind(int x){
	if(UF[x]<0) return A[x];
	else{
		ii res;
		res=ufind(UF[x]);
		UF[x]=res.fst;
		if(A[x].snd>res.snd) {return A[x]=res;}
		return A[x]={res.fst, A[x].snd}; 
	}
}

void ujoin(int x, int y){
	UF[y]=x;
	ufind(y);
	
}
int main(){
	JET
	int n,m; cin>>n>>m;
	init();
	fore(i,0,n) {cin>>A[i].snd; A[i].fst=i;}
	fore(i,0,m){
		char a;
		cin>>a;
		if(a=='+'){
			int ij,j; cin>>ij>>j;ij--;j--;
			ujoin(ij,j);
			
		}
		else{
			int j; cin>>j;j--;
			ufind(j);
			cout<<A[j].snd<<"\n";
			
		}
	}
}