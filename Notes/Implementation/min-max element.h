#include "../../Template.cpp"
// Min-Max Element

// Using min-max build-in function
int v[10] = {4, 5, 6, 7, 8, 9, 1, 2, 3, 0}, n = 10;
auto pointer_min = min_element(v, v + 10); // returns pointer to the first element of the min-element
auto pointer_max = max_element(v, v + 10); // returns pointer to the first element of the max-element

int index_min = min_element(v, v + 10) - v; // returns the index of the min-element
int index_max = max_element(v, v + 10) - v; // returns the index of the max-element

int value_min = *min_element(v, v + 10); // returns the value of the min-element
int value_max = *max_element(v, v + 10); // returns the value of the max-element

// Using min-max self-defined function
// Min
int index_min = 0, value_min = INT_MAX;
rep(i, n){
  if(v[i] < value_min){
    value_min = v[i];
    index_min = i;
  }
}
// Max
int index_max = 0, value_max = INT_MIN;
rep(i, n){
  if(v[i] > value_max){
    value_max = v[i];
    index_max = i;
  }
}