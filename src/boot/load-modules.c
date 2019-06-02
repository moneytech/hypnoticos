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

#include <multiboot.h>
#include <hypnoticos/dispatcher.h>
#include <hypnoticos/boot.h>
#include <hypnoticos/hypnoticos.h>

uint8_t BootLoadModules() {
  multiboot_module_t *module;
  uint32_t i;
  DispatcherProcess_t *p;

  for(i = 0; i < BootModulesCount; i++) {
    module = (multiboot_module_t *) ((uint32_t) BootModulesAddr + (sizeof(multiboot_module_t) * i));
    if(!(p = DispatcherProcessNewFromFormat("module", (char *) ((uint64_t) module->mod_start), module->mod_end - module->mod_start))) {
      WARNING();
      continue;
    }
  }

  return 1;
}
