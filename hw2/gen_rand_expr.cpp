// by redleaf23477
#include <bits/stdc++.h>

// iostream macros
#define endl '\n'
#define var(x) "[" << #x << "=" << x << "]"
// chrono macros
#define chrono_now std::chrono::high_resolution_clock::now()
#define chrono_duration(t1, t2) std::chrono::duration<double>(t2-t1).count()
#define chrono_rand_seed chrono_now.time_since_epoch().count()
// random
std::mt19937_64 myrand(chrono_rand_seed);
// stl
#define range(seq) seq.begin(), seq.end()


using namespace std;
using LL = long long int;

void rand_expr(int dep) {
    vector<string> bin {
        "+", "-", "*", "/", "%", 
        "<", "<=", ">", ">=", "==", "!=", 
        "=",
        "&&", "||", 
        "^", "|",
        "<<", ">>"
    };
    vector<string> pre_un {
        "+", "-",
        "++", "--",
        "!", "~", 
        "*", "&"
    };
    vector<string> suf_un {
        "++", "--"
    };

    const int n = 32;
    int i = myrand() % n;
    if (dep == 0) i = 13 + myrand()%3;

    switch (i) {
    case 0: case 1: case 2: case 3: case 4: // binary
        rand_expr(dep-1);
        cout << " " << bin[myrand()%bin.size()];
        rand_expr(dep-1);
        break;
    case 5: case 6: case 7: // prefix unary
        cout << " " << pre_un[myrand()%pre_un.size()];
        rand_expr(dep-1);
        break;
    case 8: case 9: // suffix unary
        rand_expr(dep-1);
        cout << " " << suf_un[myrand()%suf_un.size()];
        break;
    case 10: // array
    {
        int dim = myrand()%5 + 1;
        cout << " " << "arr";
        while (dim--) {
            cout << " " << "["; rand_expr(dep-1); cout << " " << "]";
        }
    }
        break;
    case 11: // function call
    {
        int param = myrand()%10;
        if (param == 0) cout << " " << "foo()";
        else {
            cout << " " << "foo(";
            rand_expr(dep-1); param--;
            while (param--) {
                cout << " " << ",";
                rand_expr(dep-1);
            }
            cout << " " << ")";
        }
    }
        break;
    case 12: // cast
        cout << " " << "(int)";
        rand_expr(dep-1);
        break;
    case 13: // literal
        cout << " " << "878787878";
        break;
    case 14: // identifier
        cout << " " << "bar";
        break;
    case 15: // NULL
        cout << " " << "NULL";
        break;
    case 16: // ( expr )
        cout << " " << "(";
        rand_expr(dep-1);
        cout << " " << ")";
        break;
    default:
        rand_expr(dep-1);
        break;
    }
}

int main() {
    cout << " " << "int main() {" << endl;
    for (int i = 0; i < 100; i++) {
        rand_expr(myrand()%20 + 10);
        cout << " " << ";" << endl;
    }
    cout << " " << "}" << endl;
    return 0;
}

