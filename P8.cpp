#include <bits/stdc++.h>
using namespace std;

static void pattern(int n, int i) {
    if(n == 0)
        return;

    pattern(n/2, i);

    for(int j = 0; j < i; j++)
        cout << "  ";

    for(int k = 0; k < n; k++)
        cout << "* ";; cout << endl;

    pattern(n/2, i + (n/2));
}

int main() {
    int n, i; cin >> n >> i;
    double k;
    if(n == 0)
        return 0;
    k =(log(n) / log(2));
    if(k * 10 % 10 == 0)
        pattern(n, i);

    return 0;
}
