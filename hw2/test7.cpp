// Global Variable Declarations
const int const_global = 10;
signed long long int a;
unsigned short int b;
float c;
double d;
void *ptr;
char ch;
int arr[2][2] = {{1, 2}, {3, 4}};
int *pointer;

// Function Declarations
void printArray(int* array);
int sum(int x, int y);

// Function Definitions
int sum(int x, int y) {
    return x+y;
}

void printArray(int* array) {
   for(i=0; i<2; i++) {
       for(j=0; j<2; j++) {
           printf("%d ", array[i][j]);
       }
       printf("\n");
   }
}

int* return_ptr() {
  return NULL;
}

int main() {
    // Scalar Declaration
    int num1 = 10, num2 = 20, result;
    int* a, *p, c;
    int arr1[2][2] = {{5, 6}, {7, 8}};
    
    result = sum(num1, num2); // function invocation
    printf("The sum is: %d\n", result);

    printArray(arr);

    // if statement
    if(result > 20) {
        printf("Result is greater than 20\n");
    } else {
        printf("Result is not greater than 20\n");
    }

    // switch statement
    switch(result) {
        case 20:
            printf("Result is 20\n");
            break;
        case 30:
            printf("Result is 30\n");
            break;
        default:
            printf("Result is not 20 or 30\n");
    }

    // while statement
    while(num1 < 15) {
        num1++;
    }

    // do-while statement
    do {
        num2--;
    } while(num2 > 15);

    // for statement
    for(i=0; i<10; i++) {
       printf("%d ", i);
    }
    for(;;) {
       printf("%d ", i);
    }

    // compound statement
    {
        int a = 5;
        printf("\nValue of a: %d\n", a);
    }

    return 0;
}

