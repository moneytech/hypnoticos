#
# HypnoticOS
# Copyright (C) 2019  jk30
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
#

LIBC_OBJS=fcntl/open.o
LIBC_OBJS+=stdio/fgetc.o stdio/fileno.o stdio/fprintf.o stdio/fputc.o stdio/fputs.o stdio/getc.o stdio/getchar.o stdio/printf.o stdio/putchar.o stdio/puts.o stdio/stdstreams.o stdio/vfprintf.o stdio/vsnprintf.o
LIBC_OBJS+=stdlib/calloc.o stdlib/free.o stdlib/malloc.o stdlib/realloc.o
LIBC_OBJS+=string/memcmp.o string/memcpy.o string/memset.o string/strcat.o string/strcmp.o string/strcpy.o string/strlen.o
LIBC_OBJS+=sys_stat/stat.o
LIBC_OBJS+=unistd/read.o unistd/sleep.o unistd/write.o
