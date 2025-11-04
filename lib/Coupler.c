#include <stdio.h>
#include <float.h>

int checkContains(int val, int size, int array[]) {
  for(int i = 0 ; i < size; i++){
    if(array[i] == val){
      return 1;
    }
  }
  return 0;
}
void findMinOfMatrix(int rows, int cols, float matrix[rows][cols],
                     int indices[2], int numExcludedRows, int numExcludedCols, int excludedRows[] , int excludedCols[]) {
  int rowOfMin = -1;
  int colOfMin = -1;
  float min = FLT_MAX;

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (matrix[i][j] < min && !checkContains(i,numExcludedRows,excludedRows)&& !checkContains(j,numExcludedCols,excludedCols)) {
        rowOfMin = i;
        colOfMin = j;
        min = matrix[i][j];
      }
    }
  }
  indices[0] = rowOfMin;
  indices[1] = colOfMin;
}
void coupler(int rows, int cols, float matrix[rows][cols]) {
  int found = 0;
  int min = cols < rows ? cols : rows;
  int couples[min][2];

	int excludedCols[cols];
	int	numExcludedCols = 0;

	int excludedRows[rows];
	int	numExcludedRows = 0;
	
  while (found < min) {
    int indices[2];
    findMinOfMatrix(rows, cols, matrix, indices,numExcludedRows,numExcludedCols,excludedRows,excludedCols);

		excludedRows[numExcludedRows++] = indices[0];
		excludedCols[numExcludedCols++] = indices[1];

    couples[found][0] = indices[0];
    couples[found][1] = indices[1];

    for (int i = 0; i < rows; i++) {
      if (i != indices[0]) {
        matrix[i][indices[1]] = 1.;
      }
    }
    for (int i = 0; i < cols; i++) {
      if (i != indices[1]) {
        matrix[indices[0]][i] = 1.;
      }
    }
    found++;
  }
  for (int i = 0; i < min; i++) {
    printf("%d, %d\n", couples[i][0], couples[i][1]);
  }
}
