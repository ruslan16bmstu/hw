#include <gtest/gtest.h>

extern "C" {
#include "mylib.h"
}

TEST(autor_is_perf_test, Assert_1) {

  database Database;

  Database.dataSize = 1;
  Database.autorIsPerformerCount = 0;
  Database.trackPtr = (track *)malloc(sizeof(track) * Database.dataSize);

  Database.trackPtr[0].autor = (char *)malloc(strlen("abc") + 1);
  strcpy(Database.trackPtr[0].autor, "abc");

  Database.trackPtr[0].performer = (char *)malloc(strlen("abc") + 1);
  strcpy(Database.trackPtr[0].performer, "abc");

  Database.trackPtr[0].title = (char *)malloc(strlen("xyz") + 1);
  strcpy(Database.trackPtr[0].title, "xyz");

  Database.trackPtr[0].duration = 45;

  Database.trackPtr[0].autorIsPerformerFlag = 0;

  output *Output = autorIsPerfOutput(&Database);

  EXPECT_EQ(strcmp(Output->titles[0], "xyz"), 0);

  freeOutput(Output);
  freeData(&Database);
}

TEST(autor_is_perf_test, Assert_2) {

  database Database;

  Database.dataSize = 3;
  Database.autorIsPerformerCount = 0;
  Database.trackPtr = (track *)malloc(sizeof(track) * Database.dataSize);

  // track #1
  Database.trackPtr[0].autor = (char *)malloc(strlen("abc") + 1);
  strcpy(Database.trackPtr[0].autor, "abc");

  Database.trackPtr[0].performer = (char *)malloc(strlen("abc") + 1);
  strcpy(Database.trackPtr[0].performer, "abc");

  Database.trackPtr[0].title = (char *)malloc(strlen("xyz") + 1);
  strcpy(Database.trackPtr[0].title, "xyz");

  Database.trackPtr[0].duration = 45;

  // track #2
  Database.trackPtr[1].autorIsPerformerFlag = 0;

  Database.trackPtr[1].autor = (char *)malloc(strlen("autor") + 1);
  strcpy(Database.trackPtr[1].autor, "autor");

  Database.trackPtr[1].performer = (char *)malloc(strlen("performer") + 1);
  strcpy(Database.trackPtr[1].performer, "performer");

  Database.trackPtr[1].title = (char *)malloc(strlen("title") + 1);
  strcpy(Database.trackPtr[1].title, "title");

  Database.trackPtr[1].duration = 80;

  Database.trackPtr[1].autorIsPerformerFlag = 0;

  //track #3

  Database.trackPtr[2].autor = (char *)malloc(strlen("Eminem") + 1);
  strcpy(Database.trackPtr[2].autor, "Eminem");

  Database.trackPtr[2].performer = (char *)malloc(strlen("Eminem") + 1);
  strcpy(Database.trackPtr[2].performer, "Eminem");

  Database.trackPtr[2].title = (char *)malloc(strlen("Venom") + 1);
  strcpy(Database.trackPtr[2].title, "Venom");

  Database.trackPtr[2].duration = 60;

  Database.trackPtr[2].autorIsPerformerFlag = 0;

  output *Output = autorIsPerfOutput(&Database);


  EXPECT_EQ(strcmp(Output->titles[0], "xyz"), 0);
  EXPECT_EQ(strcmp(Output->titles[1], "Venom"), 0);

  freeOutput(Output);
  freeData(&Database);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}