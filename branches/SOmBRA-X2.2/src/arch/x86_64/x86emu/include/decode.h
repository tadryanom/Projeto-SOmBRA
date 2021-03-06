/****************************************************************************
*
*						Realmode X86 Emulator Library
*
*            	Copyright (C) 1996-1999 SciTech Software, Inc.
* 				     Copyright (C) David Mosberger-Tang
* 					   Copyright (C) 1999 Egbert Eich
*
*  ========================================================================
*
*  Permission to use, copy, modify, distribute, and sell this software and
*  its documentation for any purpose is hereby granted without fee,
*  provided that the above copyright notice appear in all copies and that
*  both that copyright notice and this permission notice appear in
*  supporting documentation, and that the name of the authors not be used
*  in advertising or publicity pertaining to distribution of the software
*  without specific, written prior permission.  The authors makes no
*  representations about the suitability of this software for any purpose.
*  It is provided "as is" without express or implied warranty.
*
*  THE AUTHORS DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE,
*  INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO
*  EVENT SHALL THE AUTHORS BE LIABLE FOR ANY SPECIAL, INDIRECT OR
*  CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF
*  USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR
*  OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
*  PERFORMANCE OF THIS SOFTWARE.
*
*  ========================================================================
*
* Language:		ANSI C
* Environment:	Any
* Developer:    Kendall Bennett
*
* Description:  Header file for instruction decoding logic.
*
****************************************************************************/

#ifndef __X86EMU_DECODE_H
#define __X86EMU_DECODE_H

/*---------------------- Macros and type definitions ----------------------*/

/* Instruction Decoding */

#define OP_DECODE(a) \
  memcpy(M.x86.disasm_ptr, a, sizeof a - 1), \
  M.x86.disasm_ptr += sizeof a - 1

#define SEGPREF_DECODE \
  memcpy(M.x86.disasm_ptr, M.x86.decode_seg, 4), \
  M.x86.disasm_ptr += M.x86.default_seg ? 4 : 1

#define DECODE_HEX1(ofs) decode_hex1(&M.x86.disasm_ptr, ofs)
#define DECODE_HEX2(ofs) decode_hex2(&M.x86.disasm_ptr, ofs)
#define DECODE_HEX4(ofs) decode_hex4(&M.x86.disasm_ptr, ofs)
#define DECODE_HEX8(ofs) decode_hex8(&M.x86.disasm_ptr, ofs)
#define DECODE_HEX2S(ofs) decode_hex2s(&M.x86.disasm_ptr, ofs)
#define DECODE_HEX4S(ofs) decode_hex4s(&M.x86.disasm_ptr, ofs)
#define DECODE_HEX8S(ofs) decode_hex8s(&M.x86.disasm_ptr, ofs)
#define DECODE_HEX_ADDR(ofs) decode_hex_addr(&M.x86.disasm_ptr, ofs)

/*-------------------------- Function Prototypes --------------------------*/

#ifdef  __cplusplus
extern "C" {            			/* Use "C" linkage when in C++ mode */
#endif

void fetch_decode_modrm(int *mod, int *regh, int *regl) L_SYM;
u8 fetch_byte(void) L_SYM;
u16 fetch_word(void) L_SYM;
u32 fetch_long(void) L_SYM;
u8 fetch_data_byte(u32 offset) L_SYM;
u8 fetch_data_byte_abs(sel_t *seg, u32 offset) L_SYM;
u16 fetch_data_word(u32 offset) L_SYM;
u16 fetch_data_word_abs(sel_t *seg, u32 offset) L_SYM;
u32 fetch_data_long(u32 offset) L_SYM;
u32 fetch_data_long_abs(sel_t *seg, u32 offset) L_SYM;
void store_data_byte(u32 offset, u8 val) L_SYM;
void store_data_byte_abs(sel_t *seg, u32 offset, u8 val) L_SYM;
void store_data_word(u32 offset, u16 val) L_SYM;
void store_data_word_abs(sel_t *seg, u32 offset, u16 val) L_SYM;
void store_data_long(u32 offset, u32 val) L_SYM;
void store_data_long_abs(sel_t *seg, u32 offset, u32 val) L_SYM;
u8 fetch_io_byte(u32 offset) L_SYM;
u16 fetch_io_word(u32 offset) L_SYM;
u32 fetch_io_long(u32 offset) L_SYM;
void store_io_byte(u32 port, u8 val) L_SYM;
void store_io_word(u32 port, u16 val) L_SYM;
void store_io_long(u32 port, u32 val) L_SYM;
u8* decode_rm_byte_register(int reg) L_SYM;
u16* decode_rm_word_register(int reg) L_SYM;
u32* decode_rm_long_register(int reg) L_SYM;
sel_t *decode_rm_seg_register(int reg) L_SYM;
u32 decode_rm00_address(int rm) L_SYM;
u32 decode_rm01_address(int rm) L_SYM;
u32 decode_rm10_address(int rm) L_SYM;
u32 decode_sib_address(int sib, int mod) L_SYM;
u32 decode_rm_address(int mod, int rl) L_SYM;

void decode_hex(char **p, u32 ofs) L_SYM;
void decode_hex1(char **p, u32 ofs) L_SYM;
void decode_hex2(char **p, u32 ofs) L_SYM;
void decode_hex4(char **p, u32 ofs) L_SYM;
void decode_hex8(char **p, u32 ofs) L_SYM;
void decode_hex_addr(char **p, u32 ofs) L_SYM;
void decode_hex2s(char **p, s32 ofs) L_SYM;
void decode_hex4s(char **p, s32 ofs) L_SYM;
void decode_hex8s(char **p, s32 ofs) L_SYM;

void decode_descriptor(descr_t *d, u32 dl, u32 dh);

void emu_process_debug(unsigned start, unsigned len) L_SYM;


#ifdef  __cplusplus
}                       			/* End of "C" linkage for C++   	*/
#endif

#endif /* __X86EMU_DECODE_H */
