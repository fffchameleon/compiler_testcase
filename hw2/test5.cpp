int globalVar;

int add(int a, int b);

int main() {
    int localVar = 10;
    int result = add(globalVar, localVar);
    return result;
}

int add(int a, int b) {
    return a + b;
}

