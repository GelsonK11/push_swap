/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkiala <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 14:14:28 by gkiala            #+#    #+#             */
/*   Updated: 2024/09/03 14:14:31 by gkiala           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

// A utility function to get the maximum 
// value in arr[]
int getMax(int arr[], int n) {
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

// A function to do counting sort of arr[] 
// according to the digit represented by exp
void countSort(int arr[], int n, int exp) {
    int output[n]; // Output array
    int count[10] = {0}; // Initialize count array as 0

    // Store count of occurrences in count[]
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Change count[i] so that count[i] now 
    // contains actual position of this digit
    // in output[]
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the output array to arr[], 
    // so that arr[] now contains sorted 
    // numbers according to current digit
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

// The main function to sort arr[] of size 
// n using Radix Sort
void radixSort(int arr[], int n) {
  
    // Find the maximum number to know 
    // the number of digits
    int m = getMax(arr, n); 

    // Do counting sort for every digit
    // exp is 10^i where i is the current 
    // digit number
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

// A utility function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver code
int main() {
int arr[] = {34, 7, 23, 32, 5, 62, 32, 16, 1, 8, 28, 3, 20, 31, 2, 17, 12, 19, 40, 29, 50, 45, 60, 55, 35, 30, 43, 48, 56, 70, 64, 77, 90, 85, 94, 72, 84, 81, 68, 75, 76, 78, 61, 80, 57, 67, 63, 53, 66, 69, 73, 71, 52, 74, 51, 49, 58, 54, 82, 86, 87, 92, 97, 99, 91, 95, 96, 98, 83, 88, 93, 100, 65, 44, 46, 41, 42, 47, 59, 21, 22, 26, 27, 25, 24, 23, 30, 33, 37, 40, 19, 18};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Function call
    radixSort(arr, n);
    printArray(arr, n);
    return 0;
}

      






