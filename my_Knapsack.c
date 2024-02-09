#include <stdio.h>
#include <stdbool.h>

#define NUMBER_OF_ITEMS 5
#define MAX_WEIGHT 20

/**
 * @param weights[] Array containing weights of items.
 * @param values[] Array containing values of items.
 * @param selected_bool[] Boolean array indicating selected items.
 * @return the Maximum total value that can be obtained.
 */
int knapSack(int weights[], int values[], int selected_bool[]) {
    int arr[NUMBER_OF_ITEMS+1][MAX_WEIGHT+1];//storing and reusing intermediate results
    for (int i = 0; i <=NUMBER_OF_ITEMS ; ++i) {// Loop through the items
        for (int j = 0; j <=MAX_WEIGHT ; ++j) {// Loop through the weights
            if (i == 0 || j == 0) // Base case: when there are no items or the knapsack weight is 0
                arr[i][j]=0;
            else if(weights[i-1]<=j)// If the current item's weight is less than or equal to the current knapsack weight
// Select the maximum value between including and excluding the current item
                arr[i][j]=(values[i - 1] + arr[i - 1][j - weights[i - 1]]) > arr[i - 1][j] ?
                          (values[i - 1] + arr[i - 1][j - weights[i - 1]]) : arr[i - 1][j];
            else // If the current item's weight is greater than the current knapsack weight
                arr[i][j] = arr[i - 1][j]; // Exclude the current item

        }

    }
    int ans=arr[NUMBER_OF_ITEMS][MAX_WEIGHT];// Initialize the result to the maximum value
    int max= MAX_WEIGHT;// Initialize the current knapsack weight
    for (int i = NUMBER_OF_ITEMS; i >0 && ans>0 ;i--) { // Loop through the items in reverse order
        if(ans!=arr[i-1][max]){ // If the current item contributes to the maximum value
            selected_bool[i - 1] = true; // Mark the current item as selected
            ans -= values[i - 1]; // Deduct the value of the selected item from the total value
            max -= weights[i - 1]; // Deduct the weight of the selected item from the current knapsack weight
        }

    }
    return arr[NUMBER_OF_ITEMS][MAX_WEIGHT]; // Return the maximum total value
}
int main() {
    char items[NUMBER_OF_ITEMS] = {'a', 'b', 'c', 'd', 'e'};
    int values[NUMBER_OF_ITEMS], weights[NUMBER_OF_ITEMS];
    int selected_bool[NUMBER_OF_ITEMS] = {0};

    // Input values and weights
    for (int i = 0; i < NUMBER_OF_ITEMS; i++) {
        char item;
        scanf(" %c %d %d", &item, &values[i], &weights[i]);
        }
    }

    // Calculate maximum total value and select items by calling knapsack method
    int max = knapSack(weights, values, selected_bool);

    // Print results
    printf("Maximum profit: %d\n", max);
    printf("Selected items: ");
    for (int i = 0; i < NUMBER_OF_ITEMS; i++) {
        if (selected_bool[i])
            printf("%c ", items[i]);
    }
    printf("\n");
    return 0;
}
