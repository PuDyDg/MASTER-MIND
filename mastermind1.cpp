#include "bits/stdc++.h"
#define int long long
using namespace std;

int RAND() {
    return (rand() % 1000000000 + 12) * 1235LL % 123152 * 3242344543241;
}
int a[100][100];
int pos[100];
string s[100];
vector <int> id;
bool used[100];
void IN() {


    system("cls");
    for (int i = 0 ; i < 4 ; i++)
        cout << id[i] << " ";
    cout << "\n\n";
    for (int t = 6 ; t >= 1 ; t--) {
        for (int i = 1 ; i <= 4 ; i++)
            cout << a[t][i] << " ";
        if (s[t].size()) cout << "    " << s[t];
        cout << "\n";
    }
}
signed main() {

    srand(time(NULL));


    for (int i = 1 ; i <= 6 ; i++) id.push_back(i);
    random_shuffle(id.begin(), id.end());

    for (int i = 0 ; i < 4 ; i++)
        pos[id[i]] = i+1;
    
    
    bool win = 0;
    for (int test = 1 ; test <= 6 ; test++) {

        IN();
       
        for (int i = 1 ; i <= 4 ; i++)
            cin >> a[test][i];
        
        int have = 0, truepos = 0;

        for (int i = 1 ; i <= 4 ; i++) {
            have += (pos[a[test][i]] != 0);
            truepos += (pos[a[test][i]] == i);
        }
        
        have -= truepos;
        if (truepos == 4) win = 1;
        for (int i = 1 ; i <= 4 ; i++) {
            if (truepos) s[test] += "x ", truepos--;
            else if (have) s[test] +=  "o ", have--;
            else s[test] += ". ";
        }
            
        if (win) break;
    }
    IN();

    if (win) cout << "YOU WIN!!!";
    else cout << "YOU LOSE!!!";
    
    return 0;
}