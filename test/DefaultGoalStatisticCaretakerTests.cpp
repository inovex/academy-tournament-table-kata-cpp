#include "DefaultGoalStatisticCaretaker.h"
#include "gtest/gtest.h"

TEST(DefaultGoalStatisticCaretakerTests,
     maintainGoalStatistic_SomeGoals_AddGoalsToTableEntry) {
  int scoredGoals = 3;
  int takenGoals = 2;
  auto tableEntry = std::make_shared<TableEntry>();
  DefaultGoalStatisticCaretaker defaultGoalStatisticCaretaker;

  defaultGoalStatisticCaretaker.maintainGoalStatistic(tableEntry, scoredGoals,
                                                      takenGoals);

  ASSERT_EQ(scoredGoals, tableEntry->getGoalsScored());
  ASSERT_EQ(takenGoals, tableEntry->getGoalsAgainst());
}