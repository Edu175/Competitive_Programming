#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define imp(v) {for(auto gdljh:v)cout<<cv(gdljh)<<" "; cout<<"\n";}
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;
vector<double> apuesta(vector<int> &x, vector<int> &y);

int maint(){
	int N,V; srand((ll)&N); cin>>N>>V;
	ll cnt=0;
	while(1){
		int N,V,M; srand((ll)&N); cin>>N>>V>>M;
		int n=rand()%(N-2)+3;
		vector<ii>a;
		if(n&1)a.pb({0,0});
		fore(i,0,n/2){
			ll x=rand()%(2*V+1)-V,y=rand()%(2*V+1)-V;
			ll m=rand()%M+1;
			a.pb({x*m,y*m});
			m=-(rand()%M+1);
			a.pb({x*m,y*m});
		}
		random_shuffle(ALL(a));
		vector<int>x,y;
		fore(i,0,n)x.pb(a[i].fst),y.pb(a[i].snd);
		cout<<n<<"\n";
		fore(i,0,n)cout<<a[i].fst<<" "<<a[i].snd<<endl;
		apuesta(x,y);
		cout<<"ok "<<++cnt<<endl<<endl;
	}
	
	return 0;
}

int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> x(N), y(N);
    for (int i=0; i<N; i++)
        cin >> x[i] >> y[i];
    vector<double> ret = apuesta(x,y);
    if (ret.empty())
        cout << "VACIO\n";
    else
    {
        bool pri = true;
        for (double value : ret)
        {
            if (pri)
                pri = false;
            else
                cout << " ";
            cout << fixed << setprecision(4) << value;
        }
        cout << "\n";
    }
    return 0;
}
