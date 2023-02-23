#include <stdio.h>
// this is the complete missing function
int search(int numbers[], int low, int high, int value) {
  // low is less than or equal to high
  while (low <= high) {
    // mid is low plus high minus low divided by 2
    int mid = low + (high - low) / 2;
    // if the mid number equals the value
    if (numbers[mid] == value) {
      //returns the mid
      return mid;
      //all else if mid number is less than the value
    } else if (numbers[mid] < value) {
      // low is mid plus 1
      low = mid + 1;
    } else {
      //high is mid minus 1
      high = mid - 1;
    }
  }
  //returns -1
  return -1;
}

// this is the given void printArray
void printArray(int numbers[], int sz) {
  // integer i
  int i;
  // this print out Number array:
  printf("Number array : ");
  // i standards
  for (i = 0; i < sz; ++i) {
    // this prints out the numbers
    printf("%d ", numbers[i]);
  }
  // tab down
  printf("\n");
}
// this is the int void
int main(void) {
  // int i and numInputs
  int i, numInputs;
  // character of strings
  char *str;
  // average
  float average;
  // value
  int value;
  // index
  int index;
  // if its NULL
  int *numArray = NULL;
  // counting the numbers
  int countOfNums;
  // this opens the input.txt
  FILE *inFile = fopen("input.txt", "r");
  // scan the file
  fscanf(inFile, " %d\n", &numInputs);
  // input to 0
  while (numInputs-- > 0) {
    // scan the file
    fscanf(inFile, " %d\n", &countOfNums);
    // size of the numbers
    numArray = (int *)malloc(countOfNums * sizeof(int));
    // average is 0
    average = 0;
    // i standards
    for (i = 0; i < countOfNums; i++) {
      // scan the inFile
      fscanf(inFile, " %d", &value);
      // number of array to value
      numArray[i] = value;
      // average
      average += numArray[i];
    }
    // print the array and number count
    printArray(numArray, countOfNums);
    // value is when average divided by the number
    value = average / countOfNums;
    // index
    index = search(numArray, 0, countOfNums - 1, value);
    // index is greater than 0 or equal
    if (index >= 0) {
      // this prints if it is in the number array
      printf("Item %d exists in the number array at index %d!\n", value, index);
    } else {
      // prints out if its not in the number array
      printf("Item %d does not exist in the number array!\n", value);
    }
    // free the array memory
    free(numArray);
  }
  // close the file and code
  fclose(inFile);
}
