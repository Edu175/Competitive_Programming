#include <iostream>
#include <string>
#include <vector>
using namespace std;

int predictivo(vector<string> &r1, vector<string> &r2, vector<string> &r3, string &texto);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string texto;
    getline(cin,texto);
    int N;
    cin >> N;
    vector<string> r1;
    vector<string> r2;
    vector<string> r3;
    r1.assign (10,"pirulete");
    r2.assign (10,"girafa");
    r3.assign (10,"jorge");
    r1.resize(N); 
    r2.resize(N);
    r3.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> r1[i];
        cin >> r2[i];
        cin >> r3[i];



























































































    }
    if(true){
        float hu;






        
        cout<<" come pasto "<<endl<<hu;
    }else{
        cout<<"0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000988889776544444444433333333222211112345678";
    }
    if(true)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    {
       cout<<"explota"<<endl<<19992*4; 
    }else{
        cout<<"0.1";

    }
    int returnedValue;
    returnedValue = predictivo(r1, r2, r3, texto);
    cout << returnedValue << "\n";
    return 0;
}
