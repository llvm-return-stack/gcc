/* Macros for DWARF2 return stack unwinding on ARM64.

Copyright (C) 2018 Fraunhofer AISEC.
Author: Philipp Zieris <philipp.zieris@aisec.fraunhofer.de>

This program is free software; you can redistribute it and/ormodify it under
the terms of the GNU General Public License as published by the Free Software
Foundation; either version 3, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE.  See the GNU General Public License for more details.

Under Section 7 of GPL version 3, you are granted additional permissions
described in the GCC Runtime Library Exception, version
3.1, as published by the Free Software Foundation.

You should have received a copy of the GNU General Public License and a copy of
the GCC Runtime Library Exception along with this program; see the files
COPYING3 and COPYING.RUNTIME respectively.  If not, see
<http://www.gnu.org/licenses/>.  */

/* Enable return stack unwinding.  */
#define __LIBGCC_UNWIND_WITH_RETURN_STACK__ 1

/* Register numbers of the return stack pointer and program counter.  */
#define RSP_REGNUM 28
#define PC_REGNUM 30

/* Inline assembly to manipulate the return stack pointer.  */
#define asm_read_rsp(rsp) \
  asm volatile ("mov %0, x28" : "=r" (rsp))
#define asm_adjust_rsp(offset) \
  asm volatile ("add x28, x28, %0" : : "r" (offset) : "x28")
#define asm_write_rsp(rsp) \
  asm volatile ("mov x28, %0" : : "r" (rsp) : "x28")

