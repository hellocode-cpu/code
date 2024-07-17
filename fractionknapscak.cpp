#include <iostream>
#include <vector>
#include <algorithm>

struct Item {
    int value;
    int weight;
};

// Comparator function to sort items based on value/weight ratio
bool compare(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int W, std::vector<Item>& arr, int n) {
    // Sort items based on value/weight ratio in decreasing order
    std::sort(arr.begin(), arr.end(), compare);

    double max_val = 0.0;
    for (int i = 0; i < n; i++) {
        if (W >= arr[i].weight) {
            W -= arr[i].weight;
            max_val += arr[i].value;
        } else {
            max_val += arr[i].value * ((double)W / arr[i].weight);
            break;
        }
    }
    return max_val;
}

int main() {
    int n, W;
    std::cout << "Enter the number of items: ";
    std::cin >> n;

    std::cout << "Enter the maximum weight of the knapsack: ";
    std::cin >> W;

    std::vector<Item> arr(n);
    for (int i = 0; i < n; i++) {
        std::cout << "Enter value and weight for item " << i + 1 << ": ";
        std::cin >> arr[i].value >> arr[i].weight;
    }

    double max_value = fractionalKnapsack(W, arr, n);
    std::cout << "Maximum value in knapsack: " << max_value << std::endl;

    return 0;
}
