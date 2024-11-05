#include <iostream>
#include <vector>
#include <cstdlib> /
#include <ctime>   
using namespace std;

// Function to swap two elements
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Deterministic partition function (chooses the last element as pivot)
int deterministicPartition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Choose the last element as pivot
    int i = low - 1; // Pointer for the smaller element

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) { // If current element is smaller than pivot
            i++; // Increment the index of smaller element
            swap(arr[i], arr[j]); // Swap
        }
    }
    swap(arr[i + 1], arr[high]); // Place pivot in correct position
    return i + 1; // Return the partition index
}

// Randomized partition function (chooses a random pivot)
int randomizedPartition(vector<int>& arr, int low, int high) {
    int randomIndex = low + rand() % (high - low); // Randomly select an index
    swap(arr[randomIndex], arr[high]); // Swap with the last element
    return deterministicPartition(arr, low, high); // Use deterministic partition
}

// Quick Sort implementation
void quickSort(vector<int>& arr, int low, int high, bool randomized) {
    if (low < high) {
        int pivotIndex;
        if (randomized) {
            pivotIndex = randomizedPartition(arr, low, high); // Randomized partition
        } else {
            pivotIndex = deterministicPartition(arr, low, high); // Deterministic partition
        }
        quickSort(arr, low, pivotIndex - 1, randomized); // Sort left part
        quickSort(arr, pivotIndex + 1, high, randomized); // Sort right part
    }
}

// Function to print the array
void printArray(const vector<int>& arr) {
    for (int num : arr)
        cout << num << " "; // Print each element
    cout << endl; // Move to the next line
}

int main() {
    srand(time(0)); // Seed the random number generator
    int choice;

    do {
        cout << "\n--- Menu ---\n";
        cout << "1. Sort Array Using Deterministic Quick Sort\n";
        cout << "2. Sort Array Using Randomized Quick Sort\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice; // Read user's choice

        switch (choice) {
            case 1: // Deterministic Quick Sort
            case 2: // Randomized Quick Sort
                {
                    int n; // Declare the number of elements
                    cout << "Enter number of elements: ";
                    cin >> n; // Get the number of elements
                    vector<int> arr(n); // Create a vector of size n

                    cout << "Enter the elements of the array:\n";
                    for (int i = 0; i < n; i++) {
                        cin >> arr[i]; // Input the array elements
                    }

                    // Sort using the selected method
                    quickSort(arr, 0, n - 1, choice == 2);
                    cout << "Sorted array: ";
                    printArray(arr); // Print the sorted array
                }
                break;

            case 3: // Exit
                cout << "Exiting the program...\n";
                break;

            default: // Invalid choice
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 3); // Repeat until user chooses to exit

    return 0; // End of program
}

/*OUTPUT:


--- Menu ---
1. Sort Array Using Deterministic Quick Sort
2. Sort Array Using Randomized Quick Sort
3. Exit
Enter your choice: 1
Enter number of elements: 5
Enter the elements of the array:
2
5
1
80
4
Sorted array: 1 2 4 5 80

--- Menu ---
1. Sort Array Using Deterministic Quick Sort
2. Sort Array Using Randomized Quick Sort
3. Exit
Enter your choice: 2
Enter number of elements: 5
Enter the elements of the array:
2
5
2
78
80
Sorted array: 2 2 5 78 80

--- Menu ---
1. Sort Array Using Deterministic Quick Sort
2. Sort Array Using Randomized Quick Sort
3. Exit
Enter your choice: 3
Exiting the program...

*/
