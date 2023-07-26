#include "gtest/gtest.h"

#include "Table.h"

TEST(TableTests, Constructor_Default_CreatesEmptyTable)
{
  Table table;

  std::list<std::shared_ptr<ITableEntry>> tableList = table.getTable();

  ASSERT_TRUE(tableList.empty());
}