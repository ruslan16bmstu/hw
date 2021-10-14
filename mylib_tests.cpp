#include <gtest/gtest.h>

extern "C" {
#include "mylib.h"
}

TEST(autor_is_perf_test, Assert_1) {

  database Database;

  Database.db_size = 1;
  Database.autor_is_performer_count = 0;
  Database.track_ptr = (track *)malloc(sizeof(track) * Database.db_size);

  Database.track_ptr[0].autor = (char *)malloc(strlen("abc") + 1);
  strcpy(Database.track_ptr[0].autor, "abc");

  Database.track_ptr[0].performer = (char *)malloc(strlen("abc") + 1);
  strcpy(Database.track_ptr[0].performer, "abc");

  Database.track_ptr[0].title = (char *)malloc(strlen("xyz") + 1);
  strcpy(Database.track_ptr[0].title, "xyz");

  Database.track_ptr[0].duration = 45;

  Database.track_ptr[0].autor_is_performer_flag = 0;

  output *Output = autor_is_perf_output(&Database);

  EXPECT_EQ(strcmp(Output->titles[0], "xyz"), 0);

  free_output(Output);
  free_data(&Database);
}

TEST(autor_is_perf_test, Assert_2) {

  database Database;

  Database.db_size = 3;
  Database.autor_is_performer_count = 0;
  Database.track_ptr = (track *)malloc(sizeof(track) * Database.db_size);

  // track #1
  Database.track_ptr[0].autor = (char *)malloc(strlen("abc") + 1);
  strcpy(Database.track_ptr[0].autor, "abc");

  Database.track_ptr[0].performer = (char *)malloc(strlen("abc") + 1);
  strcpy(Database.track_ptr[0].performer, "abc");

  Database.track_ptr[0].title = (char *)malloc(strlen("xyz") + 1);
  strcpy(Database.track_ptr[0].title, "xyz");

  Database.track_ptr[0].duration = 45;

  // track #2
  Database.track_ptr[1].autor_is_performer_flag = 0;

  Database.track_ptr[1].autor = (char *)malloc(strlen("autor") + 1);
  strcpy(Database.track_ptr[1].autor, "autor");

  Database.track_ptr[1].performer = (char *)malloc(strlen("performer") + 1);
  strcpy(Database.track_ptr[1].performer, "performer");

  Database.track_ptr[1].title = (char *)malloc(strlen("title") + 1);
  strcpy(Database.track_ptr[1].title, "title");

  Database.track_ptr[1].duration = 80;

  Database.track_ptr[1].autor_is_performer_flag = 0;

  //track #3

  Database.track_ptr[2].autor = (char *)malloc(strlen("Eminem") + 1);
  strcpy(Database.track_ptr[2].autor, "Eminem");

  Database.track_ptr[2].performer = (char *)malloc(strlen("Eminem") + 1);
  strcpy(Database.track_ptr[2].performer, "Eminem");

  Database.track_ptr[2].title = (char *)malloc(strlen("Venom") + 1);
  strcpy(Database.track_ptr[2].title, "Venom");

  Database.track_ptr[2].duration = 60;

  Database.track_ptr[2].autor_is_performer_flag = 0;

  output *Output = autor_is_perf_output(&Database);


  EXPECT_EQ(strcmp(Output->titles[0], "xyz"), 0);
  EXPECT_EQ(strcmp(Output->titles[1], "Venom"), 0);

  free_output(Output);
  free_data(&Database);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}