#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second 
#define fore(i,a,b) for(ll i=a,jet=b ;i<jet;i++)
#define SZ(x) ((int) x.size())
#define ALL(x) x.begin(),x.end()
#define  mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

typedef long double td; typedef vector<int> vi; typedef vector<td> vd;
const td INF=0;
bool zero(td x){return fabs(x)<1e-9;}
struct Hungarian{
	int n; vector<vd>cs; vi L,R;
	Hungarian(int N, int M): n(max(N,M)),cs(n,vd(n)),L(n),R(n){
		fore(x,0,N)fore(y,0,M)cs[x][y]=INF;
	}
	void set(int x, int y, td c){cs[x][y]=-c;}
	td assign(){
		int mat=0; vd ds(n),u(n),v(n); vi dad(n),sn(n);
		fore(i,0,n)u[i]=*min_element(ALL(cs[i]));
		fore(j,0,n){v[j]=cs[0][j]-u[0];fore(i,1,n)v[j]=min(v[j],cs[i][j]-u[i]);}
		L=R=vi(n,-1);
		fore(i,0,n)fore(j,0,n){
			if(R[j]==-1&&zero(cs[i][j]-u[i]-v[j])){L[i]=j;R[j]=i;mat++;break;}
		}
		for(;mat<n;mat++){
			int s=0,j=0,i;
			while(L[s]!=-1)s++;
			fill(ALL(dad),-1); fill(ALL(sn),0);
			fore(k,0,n)ds[k]=cs[s][k]-u[s]-v[k];
			for(;;){
				j=-1;
				fore(k,0,n)if(!sn[k]&&(j==-1||ds[k]<ds[j]))j=k;
				sn[j]=1; i=R[j];
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
		td value=0;fore(i,0,n)value+=cs[i][L[i]];
		return value;
	}
};

int main(){FIN;
	ll n; cin>>n;
	vector<vector<ll>>a(n,vector<ll>(n));
	fore(i,0,n)fore(j,0,n)cin>>a[i][j];
	Hungarian hu(n,n);
	fore(i,0,n)fore(j,0,n)hu.set(i,j,log(a[i][j]));
	td ans=hu.assign();
	// cerr<<exp(ans)<<"\n";
	fore(i,0,n)cout<<hu.R[i]+1<<" ";
	cout<<"\n";
	return 0;
} 