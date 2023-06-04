int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    if (b != 0) {
        return a / b;
    } else {
        printf("Cannot divide by zero.\n");
        return 0;
    }
}

int main() {
    int choice;
    int num1, num2, result;

    printf("Enter your choice:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    scanf("%d", &choice);

    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    switch (choice) {
        case 1:
            result = add(num1, num2);
            printf("Result: %d\n", result);
            break;
        case 2:
            result = subtract(num1, num2);
            printf("Result: %d\n", result);
            break;
        case 3:
            result = multiply(num1, num2);
            printf("Result: %d\n", result);
            break;
        case 4:
            result = divide(num1, num2);
            printf("Result: %d\n", result);
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}

