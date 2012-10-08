  #!/usr/bin/perl

 #
 # Copyright (c) 2008 James Molloy, JÃ¶rg PfÃ¤hler, Matthew Iselin
 #
 # Permission to use, copy, modify, and distribute this software for any
 # purpose with or without fee is hereby granted, provided that the above
 # copyright notice and this permission notice appear in all copies.
 #
 # THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 # WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 # MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 # ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 # WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 # ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 # OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 #

 # Permission to use, copy, modify, and distribute this software for any
 # purpose with or without fee is hereby granted, provided that the above
 # copyright notice and this permission notice appear in all copies.
 #
 # THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 # WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 # MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 # ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 # WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 # ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 # OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 #

 All rights reserved.
# See (LICENSE)
#
#


open(mnm_c,">mnemonics.c") || die "Couldn't create mnemonics.c.";
open(mnm_h,">mnemonics.h") || die "Couldn't create mnemonics.h.";

print mnm_c "/* Do not edit, generated by mnemonics.pl */ \n";
print mnm_c "const char* ud_mnemonics[] = \n{\n";

print mnm_h "/* Do not edit, Generated by mnemonics.pl */ \n\n";
print mnm_h "#ifndef UD_MNEMONICS_H\n";
print mnm_h "#define UD_MNEMONICS_H\n\n";
print mnm_h "extern const char* ud_mnemonics[];\n\n";
print mnm_h "enum ud_mnemonic_code \n{ \n";

while($mnm = <STDIN>) {
	chop($mnm);
        my $mnm_padded = sprintf("%-8s", $mnm);
	print mnm_c "  \"$mnm_padded\",\n";
	print mnm_h "  UD_I$mnm,\n";
}

print mnm_c "  \"I3vil\",\n";
print mnm_h "  UD_I3vil\n";

print mnm_c "};\n";
print mnm_h "};\n";
print mnm_h "#endif\n";

close(mnm_c);
close(mnm_h);
