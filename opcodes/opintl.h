/* opintl.h - opcodes specific header for gettext code.
   Copyright (C) 1998-2025 Free Software Foundation, Inc.

   Written by Tom Tromey <tromey@cygnus.com>

   This file is part of the GNU opcodes library.

   This library is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3, or (at your option)
   any later version.

   It is distributed in the hope that it will be useful, but WITHOUT
   ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
   or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public
   License for more details.

   You should have received a copy of the GNU General Public License
   along with this file; see the file COPYING.  If not, write to the
   Free Software Foundation, 51 Franklin Street - Fifth Floor, Boston,
   MA 02110-1301, USA.  */

#ifdef ENABLE_NLS
# include <libintl.h>
/* Note the redefinition of gettext and ngettext here to use PACKAGE.

   This is because the code in this directory is used to build a
   library which will be linked with code in other directories to form
   programs.  We want to maintain a separate translation file for this
   directory however, rather than being forced to merge it with that
   of any program linked to libopcodes.  This is a library, so it
   cannot depend on the catalog currently loaded.

   In order to do this, we have to make sure that when we extract
   messages we use the OPCODES domain rather than the domain of the
   program that included the opcodes library, (eg OBJDUMP).  Hence we
   use dgettext (PACKAGE, String) and define PACKAGE to be 'opcodes'.
   (See the code in configure).  */
# undef gettext
# define gettext(Msgid) dgettext (PACKAGE, Msgid)
# undef ngettext
# define ngettext(Msgid1, Msgid2, n) dngettext (PACKAGE, Msgid1, Msgid2, n)
# define _(String) gettext (String)
# ifdef gettext_noop
#  define N_(String) gettext_noop (String)
# else
#  define N_(String) (String)
# endif
#else
# define gettext(Msgid) (Msgid)
# define dgettext(Domainname, Msgid) (Msgid)
# define dcgettext(Domainname, Msgid, Category) (Msgid)
# define ngettext(Msgid1, Msgid2, n) \
  (n == 1 ? Msgid1 : Msgid2)
# define dngettext(Domainname, Msgid1, Msgid2, n) \
  (n == 1 ? Msgid1 : Msgid2)
# define dcngettext(Domainname, Msgid1, Msgid2, n, Category) \
  (n == 1 ? Msgid1 : Msgid2)
# define textdomain(Domainname) do {} while (0)
# define bindtextdomain(Domainname, Dirname) do {} while (0)
# define _(String) (String)
# define N_(String) (String)
#endif
