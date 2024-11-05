#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Structure to store value and weight of items
struct Item {
    int value, weight;
};

// Function to sort items based on value-to-weight ratio
bool compare(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

// Function to calculate maximum value in knapsack
double fractionalKnapsack(int W, vector<Item>& items) {
    sort(items.begin(), items.end(), compare);  // Sort items by value-to-weight ratio

    double totalValue = 0.0;  // Variable to store total value
    int currentWeight = 0;    // Track current weight of the knapsack

    for (auto& item : items) {
        if (currentWeight + item.weight <= W) {
            // Take full item if it fits
            currentWeight += item.weight;
            totalValue += item.value;
        } else {
            // Take fraction of item if full item doesn't fit
            int remainingWeight = W - currentWeight;
            totalValue += item.value * ((double)remainingWeight / item.weight);
            break;  // Knapsack is full, stop
        }
    }
    return totalValue;
}

int main() {
    int choice, W;
    vector<Item> items; // List of items
    int n;

    do {
        cout << "\n--- Menu ---\n";
        cout << "1. Input items\n";
        cout << "2. Solve fractional knapsack\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            // Input number of items and their values/weights
            cout << "Enter number of items: ";
            cin >> n;
            items.clear(); // Clear previous items
            for (int i = 0; i < n; i++) {
                int value, weight;
                cout << "Enter value and weight of item " << i + 1 << ": ";
                cin >> value >> weight;
                items.push_back({value, weight});
            }
            break;

        case 2:
            // Input knapsack capacity and calculate maximum value
            if (!items.empty()) {
                cout << "Enter knapsack capacity: ";
                cin >> W;
                double maxValue = fractionalKnapsack(W, items);
                cout << "Maximum value in knapsack = " << maxValue << endl;
            } else {
                cout << "Please input items first!\n";
            }
            break;

        case 3:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice, try again.\n";
        }
    } while (choice != 3);  // Keep running until the user chooses to exit

    return 0;
}

/* OUTPUT

--- Menu ---
1. Input items
2. Solve fractional knapsack
3. Exit
Enter your choice: 1
Enter number of items: 3
Enter value and weight of item 1: 20 30
Enter value and weight of item 2: 35 60
Enter value and weight of item 3: 22 50

--- Menu ---
1. Input items
2. Solve fractional knapsack
3. Exit
Enter your choice: 2
Enter knapsack capacity: 50
Maximum value in knapsack = 31.6667

--- Menu ---
1. Input items
2. Solve fractional knapsack
3. Exit
Enter your choice: 3
Exiting...

*/
