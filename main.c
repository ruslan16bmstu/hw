#include "mylib.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int main(int argc, char **argv) {
  int size = 0;

  printf("Введите количество записей: ");
  scanf("%d", &size);

  database Database;
  Database.trackPtr = (track *)malloc(sizeof(track) * size);

  dataInit(&Database, size);

  output *Output = autorIsPerfOutput(&Database);

  if (Output != NULL) {
    for (int i = 0; i < Output->size; ++i) {
      printf("%s\n", Output->titles[i]);
    }
  }

  freeOutput(Output);

  freeData(&Database);

  return 0;
}
