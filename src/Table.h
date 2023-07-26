#pragma once

#include "DefaultGoalStatisticCaretaker.h"
#include "DefaultPointDistributionBehavior.h"
#include "DefaultTableEntryComparer.h"
#include "GameResult.h"
#include "TableEntry.h"
#include <list>
#include <map>
#include <string>

class Table
{
private:
  std::map<std::shared_ptr<ITeam>, std::shared_ptr<TableEntry>> tableEntries;
  std::list<std::shared_ptr<ITableEntry>> sortTableEntries() const;
  std::unique_ptr<IPointDistributionBehavior> pointDistributionBehavior;
  std::unique_ptr<ITableEntryComparer> tableEntryComparer;
  std::unique_ptr<IGoalStatisticCaretaker> goalStatisticCaretaker;
  void maintainGoalsStatistic(const GameResult &result);
  void addPointsToTeams(const GameResult &result);
  void createTableEntriesForResultIfNotExistent(const GameResult &result);
  void createTableEntryIfTeamEntryNotExists(std::shared_ptr<ITeam> team);

public:
  Table();
  std::list<std::shared_ptr<ITableEntry>> getTable() const;
  void bookGameResultToTable(const GameResult &result);
  std::shared_ptr<ITableEntry>
  getTableEntryForTeam(const std::shared_ptr<ITeam> &team) const;
  std::string toString() const;
};
