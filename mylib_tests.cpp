#include <gtest/gtest.h>

extern "C" {
#include "mylib.h"
}

TEST(autor_is_perf_test, Assert_1) {

  database Database;

  Database.db_size = 1;
  Database.autor_is_performer_count = 0;
  Database.track_ptr = (track *)malloc(sizeof(track) * 1);

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

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}