# Project Description: Search Algorithms

## Introduction
This project is aimed at helping you understand and implement various search algorithms. You will be working on different search algorithms to search for a value in arrays and linked lists. Through this project, you will gain a deeper understanding of how different search algorithms work, their time and space complexities, and when to use one algorithm over another.

## Learning Objectives
By the end of this project, you are expected to be able to explain to anyone:

1. What a search algorithm is.
2. What a linear search is and how it works.
3. What a binary search is and how it works.
4. The best search algorithm to use depending on your needs.
5. The time and space complexities associated with these search algorithms.

## Requirements
### General
- You are allowed to use text editors such as vi, vim, or emacs.
- Your code will be compiled on Ubuntu 20.04 LTS using `gcc` with the options `-Wall -Werror -Wextra -pedantic -std=gnu89`.
- All your code files should end with a new line.
- You must provide a `README.md` file at the root of your project folder.
- Your code should follow the Betty style and will be checked using `betty-style.pl` and `betty-doc.pl`.
- Do not use global variables.
- Each file should contain no more than 5 functions.
- You are only allowed to use the `printf` function from the standard library. You cannot use other functions like `strdup`, `malloc`, etc.

### Prototypes and Headers
- The prototypes of all your functions should be included in your header file named `search_algos.h`.
- Include guards should be used in all header files.

## Project Tasks
### 0. Linear Search
Implement a function that searches for a value in an array of integers using the Linear search algorithm. Your function should return the first index where the value is located or -1 if the value is not present in the array or if the array is NULL. You must also print the value being compared each time.

### 1. Binary Search
Implement a function that searches for a value in a sorted array of integers using the Binary search algorithm. Your function should return the index where the value is located, or -1 if the value is not present in the array or if the array is NULL. You must also print the array being searched each time it changes.

### 2. Big O #0
Answer the question: What is the time complexity (worst case) of a linear search in an array of size `n`?

### 3. Big O #1
Answer the question: What is the space complexity (worst case) of an iterative linear search algorithm in an array of size `n`?

### 4. Big O #2
Answer the question: What is the time complexity (worst case) of a binary search in an array of size `n`?

### 5. Big O #3
Answer the question: What is the space complexity (worst case) of a binary search in an array of size `n`?

### 6. Big O #4
Answer the question: What is the space complexity of the given function/algorithm?

int **allocate_map(int n, int m) {
    int **map;
    map = malloc(sizeof(int *) * n);
    for (size_t i = 0; i < n; i++) {
        map[i] = malloc(sizeof(int) * m);
    }
    return (map);
}

### 7. Jump Search
Write a function that searches for a value in a sorted array of integers using the Jump search algorithm. Your function should return the first index where the value is located or -1 if the value is not present in the array or if the array is NULL. You must use the square root of the size of the array as the jump step and print the value being compared each time.

### 8. Big O #5
Answer the question: What is the time complexity (average case) of a jump search in an array of size `n`, using the step = sqrt(n)?

### 9. Interpolation Search
Implement a function that searches for a value in a sorted array of integers using the Interpolation search algorithm. Your function should return the first index where the value is located or -1 if the value is not present in the array or if the array is NULL. You should also print the value being compared each time.

### 10. Exponential Search
Write a function that searches for a value in a sorted array of integers using the Exponential search algorithm. Your function should return the first index where the value is located or -1 if the value is not present in the array or if the array is NULL. You must use powers of 2 as exponential ranges to search in your array and print the value being compared each time.

### 11. Advanced Binary Search
Write a function that searches for a value in a sorted array of integers. This function should return the index of the first occurrence of

 the value if it exists in the array, or -1 if it doesn't. You must use the Binary search algorithm and the value you return must be the lowest possible index. In other words, if there are multiple elements with the same value, you should return the index of the first occurrence. You should also print the array being searched each time it changes.

### 12. Jump Search in a singly linked list
Write a function that searches for a value in a singly linked list using the Jump search algorithm. Your function should return a pointer to the first node where the value is located or NULL if the value is not present in the list. You must use the square root of the size of the list as the jump step and print the value being compared each time.

### 13. Linear search in a singly linked list
Write a function that searches for a value in a singly linked list using the Linear search algorithm. Your function should return a pointer to the first node where the value is located or NULL if the value is not present in the list. You must also print the value being compared each time.

### 14. Time complexity for the jump search
Answer the question: What is the time complexity of a jump search in a singly linked list of size `n`, using the step = sqrt(n)?

### 15. Time complexity for the jump search
Answer the question: What is the time complexity of a jump search in an array of size `n`, using the step = sqrt(n) and when the jump step is located at the end of the array or beyond?

### 16. Advanced Linear Search
Write a function that searches for a value in a sorted singly linked list using the Linear search algorithm. Your function should return a pointer to the first node where the value is located or NULL if the value is not present in the list. You should also print the value being compared each time.

