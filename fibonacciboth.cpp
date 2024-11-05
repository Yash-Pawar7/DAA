#include<iostream>
using namespace std;

int StepsRecursive=0;
// Recursive function to calculate Fibonacci number
int fibonacciRecursive(int n) {
    StepsRecursive++;
	if (n <= 1) {
        return n;  // Base case: if n is 0 or 1, return n
    }
    // Recursive case: sum of the previous two Fibonacci numbers
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

int main() {
    int choice;
    long long int n, first, second, next, steps;

    do {
        cout << "\n----MENU-----\n";
        cout << "1. Calculate Fibonacci Numbers (Iterative)\n";
        cout << "2. Calculate Fibonacci Numbers (Recursive)\n";
        cout << "3. Show Total Step Count (Iterative)\n";
        cout << "4. EXIT\n";
        cout << "Enter your Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:  // Iterative Fibonacci Calculation
            steps = 0;  // Reset step count
            first = 0;  // Initialize first and second numbers to 0 and 1
            second = 1;
            cout << "Enter the number of Fibonacci Terms: ";
            cin >> n;
			cout << "Fibonacci Series (Iterative): ";

            for (int i = 0; i < n; i++) {
                steps++;  // Increment step count

                if (i <= 1) {
                    next = i;
                } else {
                    next = first + second;  // Fibonacci logic
                    first = second;  // Move first forward
                    second = next;   // Move second forward
                }

                cout << next << " ";  // Print the Fibonacci number
            }
            cout << "\n";
            break;

        case 2:  // Recursive Fibonacci Calculation
            StepsRecursive=0;
			cout << "Enter the number of Fibonacci Terms: ";
            cin >> n;
            cout << "Fibonacci Series (Recursive): ";
            for (int i = 0; i < n; i++) {
                cout << fibonacciRecursive(i) << " ";  // Call recursive function
            }
            cout << "\n";
            break;

        case 3:  // Show Total Step Count for Iterative Method
            cout << "Total Steps taken (Iterative): " << steps << endl;
            break;

        case 4:  // Exit the program
            cout << "Exiting the Program....\n";
            break;

        default:  // Handle invalid choices
            cout << "Invalid Choice\n";
        }
    } while (choice != 4);  // Continue until the user chooses to exit

    return 0;
}

/* OUTPUT

----MENU-----
1. Calculate Fibonacci Numbers (Iterative)
2. Calculate Fibonacci Numbers (Recursive)
3. Show Total Step Count (Iterative)
4. EXIT
Enter your Choice: 1
Enter the number of Fibonacci Terms: 5
Fibonacci Series (Iterative): 0 1 1 2 3

----MENU-----
1. Calculate Fibonacci Numbers (Iterative)
2. Calculate Fibonacci Numbers (Recursive)
3. Show Total Step Count (Iterative)
4. EXIT
Enter your Choice: 2
Enter the number of Fibonacci Terms: 4
Fibonacci Series (Recursive): 0 1 1 2

----MENU-----
1. Calculate Fibonacci Numbers (Iterative)
2. Calculate Fibonacci Numbers (Recursive)
3. Show Total Step Count (Iterative)
4. EXIT
Enter your Choice: 4
Exiting the Program....

*/
