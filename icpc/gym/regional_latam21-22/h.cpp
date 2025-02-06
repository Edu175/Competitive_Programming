#include <bits/stdc++.h>
#define  fore(i,a,b) for(ll i=a, jet=b; i<jet; i++)
#define pb push_back
#define fst first 
#define snd second
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define ET ios::sync_with_stdio(0);cout.tie(0);cin.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vv;
typedef ll td; typedef vv vi; typedef vector<td> vd;
const td INF=1e15;
bool zero(td x){return x==0;}
struct Hungarian{
	int n; vector<vd> cs; vi L, R;
	Hungarian(int N, int M):n(max(N,M)),cs(n,vd(n)),L(n),R(n){
		fore(x,0,N)fore(y,0,M)cs[x][y]=INF;
	}
	void set(int x, int y, td c){cs[x][y]=c;}
	td assign(){
		int mat=0; vd ds(n),u(n),v(n); vi dad(n),sn(n);
		fore(i,0,n)u[i]=*min_element(ALL(cs[i]));
		fore(j,0,n){v[j]=cs[0][j]-u[0];fore(i,1,n)v[j]=min(v[j],cs[i][j]-u[i]);}
		L=R=vi(n,-1);
		fore(i,0,n)fore(j,0,n)
			if(R[j]==-1&&zero(cs[i][j]-u[i]-v[j])){L[i]=j;R[j]=i;mat++;break;}
		for(;mat<n;mat++){
			int s=0,j=0,i;
			while(L[s]!=-1)s++;
			fill(ALL(dad),-1); fill(ALL(sn),0);
			fore(k,0,n)ds[k]=cs[s][k]-u[s]-v[k];
			for(;;){
				j=-1;
				fore(k,0,n)if(!sn[k]&&(j==-1||ds[k]<ds[j]))j=k;
				sn[j]=1;i=R[j];
				if(i==-1)break;
				fore(k,0,n)if(!sn[k]){
					auto new_ds=ds[j]+cs[i][k]-u[i]-v[k];
					if(ds[k]>new_ds){ds[k]=new_ds;dad[k]=j;}
				}
			}
			fore(k,0,n)if(k!=j&&sn[k]){auto w=ds[k]-ds[j];v[k]+=w,u[R[k]]-=w;}
			u[s]+=ds[j];
			while(dad[j]>=0){int d=dad[j];R[j]=R[d];L[R[j]]=j;j=d;}
			R[j]=s;L[s]=j;
		}
		td value=0; fore(i,0,n)value+=cs[i][L[i]];
		return value;
	}
};

int main(){
	ET
	ll n; cin>>n;
	ll a[n][n];
	fore(i,0,n)fore(j,0,n)cin>>a[i][j];
	ll m=(n+1)/2;
	Hungarian hu(m,m);
	fore(i,0,n)if(!(i&1)){
		fore(j,0,n)if(!(j&1)){
			ll res=0;
			if(j)res+=a[j-1][i];
			if(j<n-1)res+=a[i][j+1];
			hu.set(i/2,j/2,res);
		}
	}
	cout<<hu.assign()<<"\n";
}