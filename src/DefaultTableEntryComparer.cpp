#include "DefaultTableEntryComparer.h"

bool DefaultTableEntryComparer::greaterThan(
    const ITableEntry &leftTableEntry,
    const ITableEntry &rightTableEntry) const
{
  if (leftTableEntry.getPoints() == rightTableEntry.getPoints())
  {
    int leftGoalDifference = CalculateGoalDifference(leftTableEntry);
    int rightGoalDifference = CalculateGoalDifference(rightTableEntry);

    if (leftGoalDifference == rightGoalDifference)
    {
      return coefficientClient->getCoefficient(leftTableEntry.getTeam()) >
             coefficientClient->getCoefficient(rightTableEntry.getTeam());
    }

    return leftGoalDifference > rightGoalDifference;
  }

  return leftTableEntry.getPoints() > rightTableEntry.getPoints();
  return leftTableEntry.getPoints() > rightTableEntry.getPoints();
}

int DefaultTableEntryComparer::CalculateGoalDifference(
    const ITableEntry &tableEntry) const
{
  return tableEntry.getGoalsScored() - tableEntry.getGoalsAgainst();
}