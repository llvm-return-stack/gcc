/* Macros for DWARF2 return stack unwinding on x86-64.

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

#ifdef __x86_64__

/* Enable return stack unwinding for x86_64.  */
#define __LIBGCC_UNWIND_WITH_RETURN_STACK__ 1

/* Register numbers of the return stack pointer and program counter.  */
#define RSP_REGNUM 15
#define PC_REGNUM 16

/* Inline assembly to manipulate the return stack pointer.  */
#define asm_read_rsp(rsp) \
  asm volatile ("movq %%r15, %0" : "=r" (rsp))
#define asm_adjust_rsp(offset) \
  asm volatile ("addq %0, %%r15" : : "r" (offset) : "r15")
#define asm_write_rsp(rsp) \
  asm volatile ("movq %0, %%r15" : : "r" (rsp) : "r15")

#endif /* __x86_64__ */
