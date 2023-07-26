#include "DefaultTableEntryComparer.h"

bool DefaultTableEntryComparer::greaterThan(
    const ITableEntry &leftTableEntry,
    const ITableEntry &rightTableEntry) const
{
  return leftTableEntry.getTeam()->getName() >
         rightTableEntry.getTeam()->getName();
}