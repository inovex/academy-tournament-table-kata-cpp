#pragma once

#include "CoefficientClient.h"
#include "TableEntry.h"

class ITableEntryComparer
{
public:
  virtual bool greaterThan(const ITableEntry &leftTableEntry,
                           const ITableEntry &rightTableEntry) const = 0;
};

class DefaultTableEntryComparer : public ITableEntryComparer
{
private:
  const std::shared_ptr<ICoefficientClient> coefficientClient;
  int CalculateGoalDifference(const ITableEntry &tableEntry) const;

public:
  DefaultTableEntryComparer(){};
  DefaultTableEntryComparer(
      const std::shared_ptr<ICoefficientClient> _coefficientClient)
      : coefficientClient(_coefficientClient){};
  bool greaterThan(const ITableEntry &leftTableEntry,
                   const ITableEntry &rightTableEntry) const;
};