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

#ifndef __HYPNOTIOS_MEMORY_H
#define __HYPNOTIOS_MEMORY_H

#include <stddef.h>
#include <stdint.h>
#include <multiboot.h>

#define MEMORYBLOCK_TYPE_AVAILABLE        1

#define MEMORY_TABLE_INITIAL_ENTRIES          100       // It may be better to have a smaller number here to make try to avoid a conflict with the kernel/mmap (this is relevant for now - TODO)
#define MEMORY_TABLE_NEW_TABLE_ENTRIES        1000

typedef struct _MemoryBlock_t MemoryBlock_t;
struct _MemoryBlock_t {
  uint32_t start; /*!< The start of the memory block */
  uint32_t length; /*!< The length of the memory block */
  uint8_t type; /*!< The memory block's type */

  MemoryBlock_t *prev; /*!< Previous in the linked list (NULL if this is the first entry) */
  MemoryBlock_t *next; /*!< Next in the linked list (NULL if no more entries) */
};
extern MemoryBlock_t MemoryBlocks;

typedef struct _MemoryTableIndex_t MemoryTableIndex_t;
typedef struct _MemoryTable_t MemoryTable_t;
struct _MemoryTableIndex_t {
  MemoryTable_t *addr; /*!< Address of an array of MemoryTable_t structures */
  uint32_t size; /*!< The size of the table */

  MemoryTableIndex_t *prev; /*!< Previous entry in the linked list (NULL if this is the first) */
  MemoryTableIndex_t *next; /*!< Next entry in the linked list (NULL if this is the last) */
} __attribute__((packed));
struct _MemoryTable_t {
  uint32_t addr; /*!< Address of this memory allocation */
  uint32_t size; /*!< Size of this memory allocation */
  uint8_t status; /*!< Status of this entry in the table (0 = empty, 1 = in use) */
} __attribute__((packed));
extern MemoryTableIndex_t MemoryTableIndices;

void MemoryAllocated(void *addr, size_t size);
MemoryTable_t *MemoryFind(void *addr);
void *MemoryFindSpace(size_t size);
void MemoryNewBlock(uint32_t mmap_addr, uint32_t mmap_length, uint32_t start, uint32_t length, uint8_t type);
void MemoryNewTable();

#endif