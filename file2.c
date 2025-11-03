#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define ARRAY_SIZE 10

void fill_array(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
}

void print_array(const int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubble_sort(int *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

int string_count_vowels(const char *str) {
    int count = 0;
    for (int i = 0; str[i]; i++) {
        char c = str[i];
        if (c == 'a' || c == 'e' || c == 'i' ||
            c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' ||
            c == 'I' || c == 'O' || c == 'U') {
            count++;
        }
    }
    return count;
}

double average(const int *arr, int size) {
    if (size == 0) return 0.0;
    int sum = 0;
    for (int i = 0; i < size; i++) sum += arr[i];
    return (double) sum / size;
}

int main() {
    int numbers[ARRAY_SIZE];
    fill_array(numbers, ARRAY_SIZE);

    printf("Original array:\n");
    print_array(numbers, ARRAY_SIZE);

    bubble_sort(numbers, ARRAY_SIZE);
    printf("Sorted array:\n");
    print_array(numbers, ARRAY_SIZE);

    printf("Average value: %.2f\n", average(numbers, ARRAY_SIZE));

    const char *text = "Artificial intelligence is fascinating.";
    printf("Text: \"%s\"\n", text);
    printf("Vowel count: %d\n", string_count_vowels(text));

    printf("Square root of 81 is %.2f\n", sqrt(81.0));

    return 0;
}

