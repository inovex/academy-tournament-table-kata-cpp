#pragma once

#include "TableEntry.h"

class IGoalStatisticCaretaker
{
public:
  virtual void
  maintainGoalStatistic(const std::shared_ptr<ITableEntry> &tableEntry,
                        int scoredGoals, int takenGoals) = 0;
};

class DefaultGoalStatisticCaretaker : public IGoalStatisticCaretaker
{
public:
  void maintainGoalStatistic(const std::shared_ptr<ITableEntry> &tableEntry,
                             int scoredGoals, int takenGoals);
};