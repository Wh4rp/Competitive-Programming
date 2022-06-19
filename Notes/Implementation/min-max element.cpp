#include "../../Template.cpp"
// Min-Max Element

// Using min-max build-in function
int v[10] = {4, 5, 6, 7, 8, 9, 1, 2, 3, 0};
auto pointer_min = min_element(v, v + 10); // returns pointer to the first element of the min-element
auto pointer_max = max_element(v, v + 10); // returns pointer to the first element of the max-element

int index_min = min_element(v, v + 10) - v; // returns the index of the min-element
int index_max = max_element(v, v + 10) - v; // returns the index of the max-element

int value_min = *min_element(v, v + 10); // returns the value of the min-element
int value_max = *max_element(v, v + 10); // returns the value of the max-element
