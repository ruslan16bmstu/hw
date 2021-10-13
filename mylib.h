#pragma once
#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define MAX_BUF_SIZE 128

typedef struct output {
  char **titles;
  int size;
} output;

typedef struct track {
  char *autor;     // автор
  char *performer; // исполнитель
  char *title;     // название трека
  int duration;    // длительность трека
  bool autor_is_performer_flag;
} track;

typedef struct database {
  track *track_ptr;
  int db_size;
  int autor_is_performer_count;
} database;

void free_data(database *data);

void data_init(database *data, const int size);

output *autor_is_perf_output(database *data);

void free_output(output *Output);

void file_input(database *Database);