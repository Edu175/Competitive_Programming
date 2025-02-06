#include <bits/stdc++.h>
#define fore(i,a,b) for(ll i=a,jet=b; i<jet;i++)
#define fst first
#define snd second
#define pb push_back
#define mset(a,v) memset((a),(v),sizeof(a))
#define ALL(x) x.begin(),x.end()
#define SZ(x) ((ll)x.size())
#define JET ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef vector<ll> vv;
typedef pair<ll,ll> ii;

int vis[300000];
int n,m;
void arriba(vector<vv>& a){
	fore(j,0,m){
		int aux=0;
		fore(i,0,n){
			if(a[i][j]!=-1){
				ll r = a[i][j];
				a[i][j]=-1;
				a[aux][j]=r;
				aux++;
			}
		}
	}
}

void abajo(vector<vv>& a){
	fore(j,0,m){
		int aux=n-1;
		for(int i = n-1;i>=0;i--){
			if(a[i][j]!=-1){
				ll r = a[i][j];
				a[i][j]=-1;
				a[aux][j]=r;
				aux--;
			}
		}
	}
}


void izquierda(vector<vv> &a){
	fore(i,0,n){
		int aux=0;
		fore(j,0,m){
			if(a[i][j]!=-1){
				ll r=a[i][j];
				a[i][j]=-1;
				a[i][aux]=r;
				aux++;
			}
		}
	}
}

void derecha(vector<vv> &a){
	fore(i,0,n){
		int aux=m-1;
		for(int j=m-1;j>=0;j--){
			if(a[i][j]!=-1){
				ll r=a[i][j];
				a[i][j]=-1;
				a[i][aux]=r;
				aux--;
			}
		}
	}
}

void doit(int i, vector<vv>& a){
	if(i==0){
		arriba(a);
	}
	if(i==1) izquierda(a);
	if(i==2) abajo(a);
	if(i==3) derecha(a);
}

int main(){
	JET
	cin>>n>>m;
	vector<vv> a(n,vv(m));
	vv arr;
	fore(i,0,n){
		fore(j,0,m){
			char c; cin>>c;
			if(c=='.'){
				a[i][j]=-1;
			}
			else{
				a[i][j]=SZ(arr);
				// cout<<SZ(arr)<<endl;
				c=='B'? arr.pb(1):arr.pb(0);
			}
		}
	}
	// doit(1,a);
	// cout<<"--------------------\n";
	// fore(i,0,n){
	// 	fore(j,0,m){
	// 		cout<<a[i][j]<<" ";
	// 	}
	// 	cout<<"\n";
	// }
	// cout<<"--------------------\n";
	
	ll k; cin>>k;
	vv b; 
	fore(i,0,k){
		char c; cin>>c;
		if(c=='G') b.pb(0);
		if(c=='L') b.pb(1);
		if(c=='D') b.pb(2);
		if(c=='P') b.pb(3);
	}
	int dir=b[0];
	doit(dir,a);
	int idx=1;
	bool bo=true;
	ii contra = {dir,-1};
	bool gt=true;
	while(idx<SZ(b)){
		if(b[idx]==dir){
			bo=true;
			idx++;
			continue;
		}
		if(b[idx]%2==dir%2){
			bo=false;
			idx++;
			continue;
		}
		contra.snd = b[idx];
		gt=false;
		break;
	}
	if(!bo){
		dir < 2 ? dir+=2:dir-=2;
		doit(dir,a);
		contra.fst=dir;
		// cout<<contra.snd<<"aaaaa\n";
		if(contra.snd!=-1) doit(contra.snd,a);
	}
	else{
		if(contra.snd!=-1) doit(contra.snd,a);
	}
	vv v;
	int hacer[2];
	hacer[0]=0;
	hacer[1]=0;
	ii ori_con = contra;
	map<int,ii> mp;
	fore(i,0,n) fore(j,0,m){
		if(a[i][j]!=-1) mp[a[i][j]]={i,j};
	}
	while(idx<SZ(b)){
		if(SZ(v)==4){
			if(v[0]%2==0) hacer[0]++;
			else hacer[1]++;			
			contra = ori_con;
			v.clear();
		}
		if(b[idx]==contra.fst || b[idx]==contra.snd){idx++;continue;}
		if(SZ(v)!=0 && v.back()%2==b[idx]%2) v.pop_back();
		else v.pb(b[idx]);
		if(contra.fst%2==b[idx]%2) contra.fst = b[idx];
		else contra.snd = b[idx]; 
		idx++;
	}
	if(gt) goto pin;
	if(ori_con.fst %2!=0) swap(ori_con.fst,ori_con.snd);
	
	if(hacer[0]>hacer[1]){
		ll mov = hacer[0]-hacer[1];
		// cout<<"--------------------\n";
		// fore(i,0,n){
		// fore(j,0,m){
		// 	cout<<a[i][j]<<" ";
		// }
		// cout<<"\n";
		// }
		// cout<<"--------------------\n";
		ori_con.fst==0 ? doit(2,a):doit(0,a);
		ori_con.snd==1 ? doit(3,a):doit(1,a);
		ori_con.fst==2 ? doit(2,a):doit(0,a);
		ori_con.snd==3 ? doit(3,a):doit(1,a);
		// cout<<"--------------------\n";
		// fore(i,0,n){
		// fore(j,0,m){
		// 	cout<<a[i][j]<<" ";
		// }
		// cout<<"\n";
		// }
		// cout<<"--------------------\n";
		vv aux;
		fore(i,0,n){
			fore(j,0,m){
				if(a[i][j]!=-1 && !vis[a[i][j]]){
					aux.pb(a[i][j]);
					vis[a[i][j]]=1;
					ii sig = mp[a[i][j]];
					while(!vis[a[sig.fst][sig.snd]]){
						aux.pb(a[sig.fst][sig.snd]);
						vis[a[sig.fst][sig.snd]]=1;
						sig = mp[a[sig.fst][sig.snd]];
					}
					
				}
				// if(SZ(aux)) for(auto x:aux)cout<<x<<" ";
				// cout<<"\n";
				ll mv;
				if(SZ(aux)) mv=mov%SZ(aux);
				fore(p,0,SZ(aux)){
					ii pos = mp[aux[p]];
					a[pos.fst][pos.snd] = aux[(p+mv)%SZ(aux)];
				}
				aux.clear();
			}
		}
		// cout<<"--------------------\n";
		// fore(i,0,n){
		// fore(j,0,m){
		// 	cout<<a[i][j]<<" ";
		// }
		// cout<<"\n";
		// }
		// cout<<"--------------------\n";
	}	
	else{
		ll mov = hacer[1]-hacer[0];
		ori_con.snd==1 ? doit(3,a):doit(1,a);
		ori_con.fst==0 ? doit(2,a):doit(0,a);
		ori_con.snd==3 ? doit(3,a):doit(1,a);
		ori_con.fst==2 ? doit(2,a):doit(0,a);
		
		
	
		vv aux;
		fore(i,0,n){
			fore(j,0,m){
				if(a[i][j]!=-1 && !vis[a[i][j]]){
					aux.pb(a[i][j]);
					vis[a[i][j]]=1;
					ii sig = mp[a[i][j]];
					while(!vis[a[sig.fst][sig.snd]]){
						aux.pb(a[sig.fst][sig.snd]);
						vis[a[sig.fst][sig.snd]]=1;
						sig = mp[a[sig.fst][sig.snd]];
					}
					
				}
				ll mv;
				if(SZ(aux)) mv=mov%SZ(aux);
				fore(p,0,SZ(aux)){
					ii pos = mp[aux[p]];
					a[pos.fst][pos.snd] = aux[(p+mv)%SZ(aux)];
				}
				aux.clear();
			}
		}
	}
	pin:
	// fore(i,0,n){
	// 	fore(j,0,m){
	// 		if(a[i][j]==-1) cout<<'.';
	// 		else{
	// 			// cout<<a[i][j]<<SZ(arr)<<endl;
	// 			if(arr[a[i][j]]==1) cout<<'B';
	// 			else cout<<'C';
	// 		}
	// 	}
	// 	cout<<"\n";
	// }
	// cout<<SZ(v)<<"\n";
	for(auto x:v){
		doit(x,a);
	}
	
	fore(i,0,n){
		fore(j,0,m){
			if(a[i][j]==-1) cout<<'.';
			else{
				// cout<<a[i][j]<<SZ(arr)<<endl;
				if(arr[a[i][j]]==1) cout<<'B';
				else cout<<'C';
			}
		}
		cout<<"\n";
	}
	return 0;
}