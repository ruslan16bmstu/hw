#pragma once
#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define MAX_BUF_SIZE 128

typedef struct output_t {
  char **titles;
  int size;
} output;

typedef struct track_t {
  char *autor;     // автор
  char *performer; // исполнитель
  char *title;     // название трека
  int duration;    // длительность трека
  bool autorIsPerformerFlag;
} track;

typedef struct database_t {
  track *trackPtr;
  int dataSize;
  int autorIsPerformerCount;
} database;

void freeData(database *data);

void dataInit(database *data, const int size);

bool autorIsPerf(database *Database);

output *autorIsPerfOutput(database *data);

void freeOutput(output *Output);