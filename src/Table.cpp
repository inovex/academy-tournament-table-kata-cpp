#include "Table.h"

Table::Table()
    : pointDistributionBehavior(
          std::make_unique<DefaultPointDistributionBehavior>()),
      tableEntryComparer(std::make_unique<DefaultTableEntryComparer>()),
      goalStatisticCaretaker(
          std::make_unique<DefaultGoalStatisticCaretaker>()) {}

std::list<std::shared_ptr<ITableEntry>> Table::sortTableEntries() const
{
  std::list<std::shared_ptr<ITableEntry>> tableEntryList;

  for (auto iterator = tableEntries.begin(); iterator != tableEntries.end();
       iterator++)
  {
    tableEntryList.push_back(
        std::static_pointer_cast<ITableEntry>(iterator->second));
  }

  tableEntryList.sort([&](const std::shared_ptr<ITableEntry> &left,
                          const std::shared_ptr<ITableEntry> &right)
                      { return tableEntryComparer->greaterThan(*left, *right); });

  return tableEntryList;
}

void Table::maintainGoalsStatistic(const GameResult &result)
{
  goalStatisticCaretaker->maintainGoalStatistic(
      getTableEntryForTeam(result.getHomeTeam()), result.getHomeTeamGoals(),
      result.getAwayTeamGoals());
  goalStatisticCaretaker->maintainGoalStatistic(
      getTableEntryForTeam(result.getAwayTeam()), result.getAwayTeamGoals(),
      result.getHomeTeamGoals());
}

void Table::addPointsToTeams(const GameResult &result)
{
  pointDistributionBehavior->addPointsToTableEntries(
      getTableEntryForTeam(result.getHomeTeam()),
      getTableEntryForTeam(result.getAwayTeam()), result);
}

void Table::createTableEntriesForResultIfNotExistent(const GameResult &result)
{
  std::shared_ptr<ITeam> homeTeam = result.getHomeTeam();
  std::shared_ptr<ITeam> awayTeam = result.getAwayTeam();

  createTableEntryIfTeamEntryNotExists(homeTeam);
  createTableEntryIfTeamEntryNotExists(awayTeam);
}

void Table::createTableEntryIfTeamEntryNotExists(std::shared_ptr<ITeam> team)
{
  if (tableEntries.find(team) != tableEntries.end())
  {
    return;
  }

  TableEntry entry;
  entry.setTeam(team);
  tableEntries[team] = std::make_shared<TableEntry>(entry);
}

std::list<std::shared_ptr<ITableEntry>> Table::getTable() const
{
  return sortTableEntries();
}

void Table::bookGameResultToTable(const GameResult &result)
{
  createTableEntriesForResultIfNotExistent(result);

  addPointsToTeams(result);

  maintainGoalsStatistic(result);
}

std::shared_ptr<ITableEntry>
Table::getTableEntryForTeam(const std::shared_ptr<ITeam> &team) const
{
  auto iterator = tableEntries.find(team);

  if (iterator == tableEntries.end())
  {
    return nullptr;
  }

  return std::static_pointer_cast<ITableEntry>(iterator->second);
}

std::string Table::toString() const
{
  std::list<std::shared_ptr<ITableEntry>> tableEntries = sortTableEntries();
  std::string tableAsString;

  for (std::list<std::shared_ptr<ITableEntry>>::const_iterator iterator =
           tableEntries.begin();
       iterator != tableEntries.end(); iterator++)
  {
    tableAsString += (*iterator)->toString() + "\n";
  }

  return tableAsString;
}