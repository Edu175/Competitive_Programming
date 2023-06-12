#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> dameLongitudes(vector<string> v);

template <typename T>
void mostrar(const vector<T>&v)
{
    for (int i=0;i<int(v.size()); i++)
    {
        if (i > 0)
            cout << " ";
        cout << v[i];
    }
    cout << endl;
}

int main()
{
    int n; cin >> n;
    vector<string> v(n);
    for (int i=0;i<n;i++)
        cin >> v[i];
    vector<int> ret = dameLongitudes(v);
    mostrar(ret);
    return 0;
}
