#include <stdio.h>
// this is the binary recursive function
int binarySearch(int numbers[], int low, int high, int value) {
  // if low is higher than high
  if (low > high) {
    // returns -1
    return -1;
  }
  // this is mid equal to low plus high divided 2
  int mid = (low + high) / 2;
  // if the mid number equal value
  if (numbers[mid] == value) {
    // returns the mid values
    return mid;
    // if the mid numbers are less than the actual value
  } else if (numbers[mid] < value) {
    // this returns the binarySearch mid + 1
    return binarySearch(numbers, mid + 1, high, value);
  } else {
    // returns binarySearch mid -1
    return binarySearch(numbers, low, mid - 1, value);
  }
}
// initiate the search again
int search(int numbers[], int low, int high, int value) {
  // returns binarySearch
  return binarySearch(numbers, low, high, value);
}
// this is the void printArray
void printArray(int numbers[], int sz) {
  //int i
  int i;
  //print out the Number Array
  printf("Number array : ");
  //i standards
  for (i = 0; i < sz; ++i) {
    //prints out the numbers
    printf("%d ", numbers[i]);
  }
  //tab down
  printf("\n");
}
//this is the main 
int main(void) {
  //int it and numInputs
  int i, numInputs;
  //character strings
  char *str;
  //average of the numbers  
  float average;
  //values
  int value;
  //index for postion of numbers
  int index;
  //if numArray is NUL
  int *numArray = NULL;
  //counting of the numbers
  int countOfNums;
  //opens the input.txt
  FILE *inFile = fopen("input.txt", "r");
  //scan the file
  fscanf(inFile, " %d\n", &numInputs);
// loop 
  while (numInputs-- > 0) {
    //file scan
    fscanf(inFile, " %d\n", &countOfNums);
    // dynamic allocated memory 
    numArray = (int *)malloc(countOfNums * sizeof(int));
    // average is 0
    average = 0;
// i standards 
    for (i = 0; i < countOfNums; i++) {
      //scan file
      fscanf(inFile, " %d", &value);
      //number of arrays is value
      numArray[i] = value;
      //average equals pus the number of Arrays 
      average += numArray[i];
    }
// print Array
    printArray(numArray, countOfNums);
    // value is average divided by countofNums
    value = average / countOfNums;
    //index is added and subtracted
    index = search(numArray, 0, countOfNums - 1, value);
// if index is greater or equal to 0
    if (index >= 0) {
      //prints this out if item does exist i array
      printf("Item %d exists in the number array at index %d!\n", value,
             index + 1);
    } else {
      //prints out if item does not exist
      printf("Item %d does not exist in the number array!\n", value);
    }
// free the number of array
    free(numArray);
  }
//close the and finished the code
  fclose(inFile);
}

