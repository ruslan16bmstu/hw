#include "mylib.h"

void free_data(database *Database) {
  if (Database == NULL) {
    return;
  }

  for (int i = 0; i < Database->db_size; ++i) {
    free(Database->track_ptr[i].autor);
    free(Database->track_ptr[i].performer);
    free(Database->track_ptr[i].title);
  }
  free(Database->track_ptr);

  Database = NULL;
  return;
}

void data_init(database *Database, const int size) {
  if (Database == NULL) {
    return;
  }

  Database->db_size = size;
  Database->autor_is_performer_count = 0;

  char buffer[MAX_BUF_SIZE];

  for (int i = 0; i < size; ++i) {
    printf("Введите имя автора: ");
    scanf("%127s", buffer);
    Database->track_ptr[i].autor = (char *)malloc(strlen(buffer) + 1);
    strcpy(Database->track_ptr[i].autor, buffer);

    printf("Введите имя исполнителя: ");
    scanf("%127s", buffer);
    Database->track_ptr[i].performer = (char *)malloc(strlen(buffer) + 1);
    strcpy(Database->track_ptr[i].performer, buffer);

    printf("Введите название трека: ");
    scanf("%127s", buffer);
    Database->track_ptr[i].title = (char *)malloc(strlen(buffer) + 1);
    strcpy(Database->track_ptr[i].title, buffer);

    printf("Введите длительность трека: ");
    scanf("%d", &Database->track_ptr[i].duration);

    Database->track_ptr[i].autor_is_performer_flag = 0;
  }
  return;
}

void autor_is_perf(database *Database) {
  if (Database == NULL) {
    return;
  }

  for (int i = 0; i < Database->db_size; ++i) {
    if (strcmp(Database->track_ptr[i].autor,
               Database->track_ptr[i].performer) == 0) {
      Database->track_ptr[i].autor_is_performer_flag = 1;
      Database->autor_is_performer_count++;
    } else {
      Database->track_ptr[i].autor_is_performer_flag = 0;
    }
  }
  return;
}

output *autor_is_perf_output(database *Database) {
  if (Database == NULL) {
    return NULL;
  } else {
    autor_is_perf(Database);

    output *Output;
    Output = (output *)malloc(sizeof(output));
    Output->size = Database->autor_is_performer_count;
    Output->titles =
        (char **)malloc(sizeof(char *) * Database->autor_is_performer_count);

    for (int i = 0; i < Database->autor_is_performer_count; ++i) {
      Output->titles[i] =
          (char *)malloc(strlen(Database->track_ptr[i].title) + 1);
      strcpy(Output->titles[i], Database->track_ptr[i].title);
    }
    return Output;
  }
}

void free_output(output *Output) {

  for (int i = 0; i < Output->size; ++i) {
    free(Output->titles[i]);
  }

  free(Output->titles);
  free(Output);
  Output = NULL;

  return;
}

/* void file_input(database* Database) {
    FILE *fin;
    fin = fopen("tests.txt", "r");

    if (fin == NULL){
        printf("Error fin");
        return;
    }

    Database->autor_is_performer_count = 0;

    if (fin != NULL) {
        if (fscanf(fin, "%d", &Database->db_size)) {
            Database->track_ptr = (track*)malloc(sizeof(track) *
Database->db_size);

            for (int i = 0; i < Database->db_size; ++i) {
                char buf_autor[MAX_BUF_SIZE];
                char buf_performer[MAX_BUF_SIZE];
                char buf_title[MAX_BUF_SIZE];

                if (fscanf(fin, "%s %s %s %d"),
                    buf_autor,
                    buf_performer,
                    buf_title,
                    &Database->track_ptr[i].duration) {

                        Database->track_ptr[i].autor =
(char*)malloc(strlen(buf_autor) + 1); strcpy(Database->track_ptr[i].autor,
buf_autor);

                        Database->track_ptr[i].performer =
(char*)malloc(strlen(buf_performer) + 1);
                        strcpy(Database->track_ptr[i].performer, buf_performer);

                        Database->track_ptr[i].title =
(char*)malloc(strlen(buf_title) + 1); strcpy(Database->track_ptr[i].title,
buf_title);

                        if (strcmp(Database->track_ptr[i].autor,
Database->track_ptr[i].performer) == 0) {
                            Database->track_ptr[i].autor_is_performer_flag = 1;
                            Database->autor_is_performer_count++;
                        }

                        else {
                            Database->track_ptr[i].autor_is_performer_flag = 0;
                        }
                }
            }
        }
    }
    fclose(fin);
    return;
} */