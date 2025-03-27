#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define N 4 // Number of cities

int min_cost = INT_MAX; // Global variable to store minimum cost
int best_path[N]; // Stores the best path
// Function to swap elements (for permutations)
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to calculate total distance of a given path
int calculate_cost(int graph[N][N], int path[N]) {
    int cost = 0;
    for (int i = 0; i < N - 1; i++)
        cost += graph[path[i]][path[i + 1]];
    cost += graph[path[N - 1]][path[0]]; // Return to start
    return cost;
}

// Function to generate permutations of cities and find the best path
void tsp_permutation(int graph[N][N], int path[N], int l, int r) {
    if (l == r) {
        int cost = calculate_cost(graph, path);
        if (cost < min_cost) {
            min_cost = cost;
            for (int i = 0; i < N; i++)
                best_path[i] = path[i];
        }
        return;
    }
    
    for (int i = l; i <= r; i++) {
        swap(&path[l], &path[i]);
        tsp_permutation(graph, path, l + 1, r);
        swap(&path[l], &path[i]); // Backtrack
    }
}

int main() {
    // Distance matrix (Graph representation)
    int graph[N][N] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    int path[N] = {0, 1, 2, 3}; // Initial order of cities
    
    tsp_permutation(graph, path, 1, N - 1); // Start permutations from index 1

    // Display the best path
    printf("Shortest Path: ");
    for (int i = 0; i < N; i++)
        printf("%d -> ", best_path[i]);
    printf("%d\n", best_path[0]); // Returning to start city
    printf("Minimum Cost: %d\n", min_cost);

    // Simulate two persons traveling
    int person1_time = min_cost * 2; // Person 1 takes double time
    int person2_time = min_cost * 1.5; // Person 2 takes 1.5x time

    printf("\nPerson 1 reaches in: %d units\n", person1_time);
    printf("Person 2 reaches in: %d units\n", person2_time);
    
    if (person1_time < person2_time)
        printf("Person 1 reaches faster!\n");
    else
        printf("Person 2 reaches faster!\n");

    return 0;
}

