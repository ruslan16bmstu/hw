#include "mylib.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int main(int argc, char **argv) {
  int size = 0;

  printf("Введите количество записей: ");
  scanf("%d", &size);

  database Database;
  Database.track_ptr = (track *)malloc(sizeof(track) * size);

  data_init(&Database, size);

  output *Output = autor_is_perf_output(&Database);

  if (Output != NULL) {
    for (int i = 0; i < Output->size; ++i) {
      printf("%s\n", Output->titles[i]);
    }
  }

  free_output(Output);

  free_data(&Database);

  return 0;
}
