#include <iostream> 
#include <vector> 
#include <string> 

using namespace std;

const int MAXN = 1e6 + 10;

int power_p[MAXN];

int get_hash(int start, int end, vector <int> &hashes) {
    int hash = hashes[end];
    // start = s
    // end = e
    // 0.............e
    //        s......e
    //    x
    int x = end - start + 1;
    if (start != 0) {
        hash -= hashes[start - 1] * power_p[x];
    }

    return hash;
}
int main() {
    


    string s = "abacaba";
    string w = "aba";

    for (int i = 0; i <= (int)s.size() - (int)w.size(); i++) {
        bool is_same = true;

        for (int j = 0; j < w.size(); j++) {
            if (w[j] != s[i + j]) {
                is_same = false;
                break;
            }
        }

        if (is_same) {
           // cout << i << " ";
        }
    }

    cout << endl;

    int p = 31;

    power_p[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        power_p[i] = p * power_p[i - 1];
    }

    vector <int> hashes;

    int hash = 0;

    /*
        s[i] -> {'a', .... 'z'} -> 26
        'a' => 1
        'b' => 2
        ...
        'z' => 26

    */


    /*
        abacaba

        0:
        hash => 0 * 31 = 0
        hash => 0 + 1 = 1

        1:
        hash => 1 * 31 = 31
        hash => 31 + 2 = 33



        a -> 1
        ab -> 33
        aba -> 1024
        abac -> 31747
        abaca -> 984158
        abacab -> 30508900
        abacaba -> 945775901
    */
    for (int i = 0; i < s.size(); i++) {
        hash *= p;
        hash += s[i] - 'a' + 1;

        hashes.push_back(hash);
        cout << i << " " << hash << endl;
    }

    int hash_w = 0;
    for (int i = 0; i < w.size(); i++) {
        hash_w *= p;
        hash_w += w[i] - 'a' + 1;
    }


    cout << "Hash value of W :" << hash_w << endl;

    vector <int> result;
    for (int i = 0; i <= (int)s.size() - (int)w.size(); i++) {
        bool is_same;

        cout << i << " " << i + (int)w.size() - 1 << " = " << get_hash(i, i + (int)w.size() - 1, hashes) << endl;

        is_same = (get_hash(i, i + (int)w.size() - 1, hashes) == hash_w);
    
        if (is_same) {
            result.push_back(i);
            
        }
    }
    
    for (auto i: result) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}