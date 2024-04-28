#include <iostream>
#include <vector>
#include <omp.h>

using namespace std;

// Function to perform parallel reduction for minimum value
int parallelMin(const vector<int>& arr) {
    int min_val = arr[0];
    #pragma omp parallel for reduction(min:min_val)
    for (size_t i = 0; i < arr.size(); ++i) {
        if (arr[i] < min_val) {
            min_val = arr[i];
        }
    }
    return min_val;
}

// Function to perform parallel reduction for maximum value
int parallelMax(const vector<int>& arr) {
    int max_val = arr[0];
    #pragma omp parallel for reduction(max:max_val)
    for (size_t i = 0; i < arr.size(); ++i) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }
    return max_val;
}

// Function to perform parallel reduction for sum
int parallelSum(const vector<int>& arr) {
    int sum = 0;
    #pragma omp parallel for reduction(+:sum)
    for (size_t i = 0; i < arr.size(); ++i) {
        sum += arr[i];
    }
    return sum;
}

// Function to compute average using parallel reduction
double parallelAverage(const vector<int>& arr) {
    int sum = parallelSum(arr);
    return static_cast<double>(sum) / arr.size();
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int min_val = parallelMin(arr);
    int max_val = parallelMax(arr);
    int sum = parallelSum(arr);
    double avg = parallelAverage(arr);

    cout << "Minimum value: " << min_val << endl;
    cout << "Maximum value: " << max_val << endl;
    cout << "Sum: " << sum << endl;
    cout << "Average: " << avg << endl;

    return 0;
}