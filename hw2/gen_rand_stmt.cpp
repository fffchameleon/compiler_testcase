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

///////////////////////////////////////////////////////////

void rand_stmt(int dep, bool noskip = false) {
    function<void()> expr = []() { return rand_expr(myrand()%5 + 1); };
    int i = myrand() % 15;
    if (dep == 0) {
        i = myrand()%4;
        if (i == 3) i = 0;
        else i += 7;
    }
    while (noskip && i > 10) {
        i = myrand()%15;
    }
    switch (i) {
    case 0: // expr stmt
        expr();
        cout << " " << ";";
        break;
    case 1: // if stmt
        cout << " " << "if" << "("; expr(); cout << " " << ")" << "{";
        rand_stmt(dep-1);
        cout << " " << "}";
        break;
    case 2: // if-else
        cout << " " << "if" << "("; expr(); cout << " " << ")" << "{";
        rand_stmt(dep-1);
        cout << " " << "}" << "else" << "{";
        rand_stmt(dep-1);
        cout << " " << "}";
        break;
    case 3: // switch
    {
        int n = myrand()%5, d = myrand()%2;
        cout << " " << "switch" << "("; expr(); cout << " " << ") {";
        while (n--) {
            cout << " " << "case"; expr(); cout << " " << ":";
            if (myrand()%2) rand_stmt(dep-1);
        }
        if (d) {
            cout << " " << "default :";
            if (myrand()%2) rand_stmt(dep-1);
        }
        cout << " " << "}";
    }
        break;
    case 4: // while
        cout << " " << "while ("; expr(); cout << " " << ")";
        rand_stmt(dep-1, true);
        break;
    case 5: // do-while
        cout << " " << "do";
        rand_stmt(dep-1, true);
        cout << " " << "while ("; expr(); cout << " " << ") ;";
        break;
    case 6: // for
        cout << " " << "for (";
        if (myrand()%2) expr();
        cout << " " << ";";
        if (myrand()%2) expr();
        cout << " " << ";";
        if (myrand()%2) expr();
        cout << " " << ")";
        rand_stmt(dep-1, true);
        break;
    case 7: // return
        cout << " " << "return";
        if (myrand()%2) expr();
        cout << " " << ";";
        break;
    case 8: // break;
        cout << " " << "break; ";
        break;
    case 9: // continue;
        cout << " " << "continue; ";
        break;
    case 10: // compound
    {
        int n = myrand()%10;
        cout << " " << "{";
        while (n--) {
            if (myrand()%2) rand_stmt(dep-1);
            else cout << " " << "int a = 87;";
        }
        cout << " " << "}";
    }
        break;
    }
}

int main() {
    cout << "int main() {" << endl;
    for (int i = 0; i < 30; i++) {
        rand_stmt(myrand()%20 + 10);
    }
    cout << "}" << endl;
    return 0;
}

