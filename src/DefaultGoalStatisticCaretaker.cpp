#include "DefaultGoalStatisticCaretaker.h"

void DefaultGoalStatisticCaretaker::maintainGoalStatistic(
    const std::shared_ptr<ITableEntry> &tableEntry, int scoredGoals,
    int takenGoals)
{
  tableEntry->addGoalsScored(scoredGoals);
  tableEntry->addGoalsAgainst(takenGoals);
}
