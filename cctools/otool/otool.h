/*
 * Copyright © 2009 Apple Inc. All rights reserved.
 *
 * @APPLE_LICENSE_HEADER_START@
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 
 * 1.  Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer. 
 * 2.  Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution. 
 * 3.  Neither the name of Apple Inc. ("Apple") nor the names of its
 * contributors may be used to endorse or promote products derived from this
 * software without specific prior written permission. 
 * 
 * THIS SOFTWARE IS PROVIDED BY APPLE AND ITS CONTRIBUTORS "AS IS" AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL APPLE OR ITS CONTRIBUTORS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * @APPLE_LICENSE_HEADER_END@
 */
#import <stuff/bool.h>

/* Name of this program for error messages (argv[0]) */
extern char *progname;

/*
 * The flags to indicate the actions to perform.
 */
extern enum bool fflag; /* print the fat headers */
extern enum bool aflag; /* print the archive header */
extern enum bool hflag; /* print the exec or mach header */
extern enum bool lflag; /* print the load commands */
extern enum bool Lflag; /* print the shared library names */
extern enum bool Dflag; /* print the shared library id name */
extern enum bool tflag; /* print the text */
extern enum bool dflag; /* print the data */
extern enum bool oflag; /* print the objctive-C info */
extern enum bool Oflag; /* print the objctive-C selector strings only */
extern enum bool rflag; /* print the relocation entries */
extern enum bool Sflag; /* print the contents of the __.SYMDEF file */
extern enum bool vflag; /* print verbosely (symbolicly) when possible */
extern enum bool Vflag; /* print dissassembled operands verbosely */
extern enum bool cflag; /* print the argument and environ strings of a core file */
extern enum bool iflag; /* print the shared library initialization table */
extern enum bool Wflag; /* print the mod time of an archive as an decimal number */
extern enum bool Xflag; /* don't print leading address in disassembly */
extern enum bool Zflag; /* don't use simplified ppc mnemonics in disassembly */
extern enum bool Bflag; /* force Thumb disassembly (ARM objects only) */
extern char *pflag; 	/* procedure name to start disassembling from */
extern char *segname,
     *sectname;	    /* name of the section to print the contents of */

uint32_t m68k_usrstack(void);
uint32_t m88k_usrstack(void);
uint32_t i386_usrstack(void);
uint32_t hppa_usrstack(void);
uint32_t sparc_usrstack(void);
