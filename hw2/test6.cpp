int global_var = 10;

int add(int a, int b);

void print_array(int arr, int size);

int main() {
    int local_var = 20;
    int result = add(global_var, local_var);
    int numbers[5] = {1, 2, 3, 4, 5};
    
    printf("Result: %d\n", result);
    print_array(numbers, 5);

    return 0;
}

int add(int a, int b) {
    return a + b;
}

void print_array(int arr, int size) {
    printf("Array: ");
    int i;
    for (i = 0; i < size; i++)  {
        printf("%d ", arr[i]);
    }
    
    printf("\n");
}

