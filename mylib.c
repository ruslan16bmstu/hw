#include "mylib.h"

void freeData(database *Database) {
  if (Database == NULL) {
    return;
  }

  for (int i = 0; i < Database->dataSize; ++i) {
    free(Database->trackPtr[i].autor);
    free(Database->trackPtr[i].performer);
    free(Database->trackPtr[i].title);
  }
  free(Database->trackPtr);

  Database = NULL;
  return;
}

void dataInit(database *Database, const int size) {
  if (Database == NULL) {
    return;
  }

  Database->dataSize = size;
  Database->autorIsPerformerCount = 0;

  char buffer[MAX_BUF_SIZE];

  for (int i = 0; i < size; ++i) {
    printf("Введите имя автора: ");
    scanf("%127s", buffer);
    Database->trackPtr[i].autor = (char *)malloc(strlen(buffer) + 1);
    strcpy(Database->trackPtr[i].autor, buffer);

    printf("Введите имя исполнителя: ");
    scanf("%127s", buffer);
    Database->trackPtr[i].performer = (char *)malloc(strlen(buffer) + 1);
    strcpy(Database->trackPtr[i].performer, buffer);

    printf("Введите название трека: ");
    scanf("%127s", buffer);
    Database->trackPtr[i].title = (char *)malloc(strlen(buffer) + 1);
    strcpy(Database->trackPtr[i].title, buffer);

    printf("Введите длительность трека: ");
    scanf("%d", &Database->trackPtr[i].duration);

    Database->trackPtr[i].autorIsPerformerFlag = 0;
  }
  return;
}

bool autorIsPerf(database *Database) {
  if (Database == NULL) {
    return 0;
  }

  for (int i = 0; i < Database->dataSize; ++i) {
    if (strcmp(Database->trackPtr[i].autor,
               Database->trackPtr[i].performer) == 0) {
      Database->trackPtr[i].autorIsPerformerFlag = 1;
      Database->autorIsPerformerCount++;
    } else {
      Database->trackPtr[i].autorIsPerformerFlag = 0;
    }
  }
  return 1;
}

output *autorIsPerfOutput(database *Database) {
  if (Database == NULL) {
    return NULL;
  }

  if (!autorIsPerf(Database)) {
    return NULL;
  }

  output *Output;
  Output = (output *)malloc(sizeof(output));
  Output->size = Database->autorIsPerformerCount;
  Output->titles =
      (char **)malloc(sizeof(char *) * Database->autorIsPerformerCount);

  if (Output->titles == NULL) {
    return NULL;
  }

  int k = 0;
  for (int i = 0; i < Database->dataSize; ++i) {
    if (Database->trackPtr[i].autorIsPerformerFlag == 1) {
      Output->titles[k] =
          (char *)malloc(strlen(Database->trackPtr[i].title) + 1);
      strcpy(Output->titles[k], Database->trackPtr[i].title);
      ++k;
    }
  }
  return Output;
}

void freeOutput(output *Output) {
  for (int i = 0; i < Output->size; ++i) {
    free(Output->titles[i]);
  }

  free(Output->titles);
  free(Output);
  Output = NULL;

  return;
}
