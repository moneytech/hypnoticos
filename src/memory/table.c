//
// HypnoticOS
// Copyright (C) 2019  jk30
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//

#include <string.h>
#include <stdlib.h>
#include <hypnoticos/memory.h>

// TODO Condense tables

void MemoryNewTable() {
  MemoryTableIndex_t *mti, *next;
  uint64_t table_size = sizeof(MemoryTable_t) * MEMORY_TABLE_NEW_TABLE_ENTRIES;

  for(mti = &MemoryTableIndices; mti->next != NULL; mti = mti->next);

  next = malloc(sizeof(MemoryTableIndex_t));
  next->next = NULL;
  next->prev = mti;
  next->addr = malloc(table_size);
  next->size = table_size;

  memset(next->addr, 0, table_size);

  mti->next = next;
}
