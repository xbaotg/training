#include <bits/stdc++.h>
using namespace std;

int main() {
    srand(time(NULL));

    int n, k;
    string s;

    for (int i = 0; i < 100; ++i) {
        // gen
        n = rand() % 1000 + 1;
        k = rand() % (n + 1) + 0;
        s.assign(n, ' ');

        char c[] = {'a', 'b'};
        for (auto &v : s) {
            v = c[rand() % 2 + 0];
        }

        ofstream inp("input", ios::out);
        inp << n << " " << k << endl;
        inp << s;
        inp.close();

        system("./ans.out");
        system("./test.out");

        if (system(("diff output output2")) != 0) 
            cout << "Wrong" << endl;
        else
            cout << "Ok" << endl;
    }
}
