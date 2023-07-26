#pragma once

#include "GameResult.h"
#include "TableEntry.h"

class IPointDistributionBehavior
{
public:
  virtual void addPointsToTableEntries(
      const std::shared_ptr<ITableEntry> &homeTeamTableEntry,
      const std::shared_ptr<ITableEntry> &awayTeamTableEntry,
      const GameResult &gameResult) = 0;
};

class DefaultPointDistributionBehavior : public IPointDistributionBehavior
{
public:
  void addPointsToTableEntries(
      const std::shared_ptr<ITableEntry> &homeTeamTableEntry,
      const std::shared_ptr<ITableEntry> &awayTeamTableEntry,
      const GameResult &gameResult);
};