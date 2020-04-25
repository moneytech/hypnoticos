//
// HypnoticOS
// Copyright (C) 2020  jk30
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

#include <stddef.h>
#include <string.h>
#include <directory.h>
#include <hypnoticos/function.h>
#include <hypnoticos/dispatcher.h>
#include <hypnoticos/fs.h>
#include <hypnoticos/hypnoticos.h>

/**
 * Retrieve details of a directory entry for a KernelFunctionDirectoryGet
 * instance.
 * @param  p             The process
 * @param  lock_entry_id The index lock ID of the directory.
 * @param  offset        The offset in the list.
 * @param  index_addr    The address where the FsIndex_t structure should be
 *                       placed.
 * @return               0 on failure, 1 on success.
 */
uint64_t KernelFunctionDirectoryEntry(DispatcherProcess_t *p, uint64_t lock_entry_id, uint64_t offset, uint64_t index_addr)
{
  DispatcherOpenIndex_t *lock_entry;
  FsIndex_t *ptr;

  // Get the index lock entry
  if((lock_entry = DispatcherIndexLockRetrieve(p, lock_entry_id)) == NULL)
    return 0;

  // Check that the offset exists
  uint64_t max_offset;
  for(max_offset = 0; lock_entry->directory_data[max_offset] != NULL; max_offset++);
  if(offset > max_offset) {
    return 0;
  } else if(offset == max_offset) {
    return DIRECTORY_END;
  }

  // Translate va to pa
  ptr = GET_PA(index_addr);
  if(ptr == NULL) {
    WARNING();
    return 0;
  }

  // Update the pointer
  memcpy(ptr, lock_entry->directory_data[offset], sizeof(FsIndex_t));

  return 1;
}
