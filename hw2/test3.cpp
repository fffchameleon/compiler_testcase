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
            result = num1 + num2;
            printf("Result: %d\n", result);
            break;
        case 2:
            result = num1 - num2;
            printf("Result: %d\n", result);
            break;
        case 3:
            result = num1 * num2;
            printf("Result: %d\n", result);
            break;
        case 4:
            if (num2 != 0) {
                result = num1 / num2;
                printf("Result: %d\n", result);
            } else {
                printf("Cannot divide by zero.\n");
            }
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}

