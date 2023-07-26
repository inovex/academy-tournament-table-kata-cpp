#include "DefaultTableEntryComparer.h"

bool DefaultTableEntryComparer::greaterThan(
    const ITableEntry &leftTableEntry,
    const ITableEntry &rightTableEntry) const
{
  return leftTableEntry.getPoints() > rightTableEntry.getPoints();
}