/* File: h-system.h */

#ifndef INCLUDED_H_SYSTEM_H
#define INCLUDED_H_SYSTEM_H

/*
 * Include the basic "system" files.
 *
 * Make sure all "system" constants/macros are defined.
 * Make sure all "system" functions have "extern" declarations.
 *
 * This file is a big hack to make other files less of a hack.
 * This file has been rebuilt -- it may need a little more work.
 *
 * It is (very) unlikely that VMS will work without help, primarily
 * because VMS does not use the "ASCII" character set.
 */


#include <stdio.h>
#include <ctype.h>
#include <errno.h>
#include <stdlib.h>


#ifdef SET_UID

# include <sys/types.h>

# if defined(Pyramid) || defined(sun) || defined(NCR3K) || \
     defined(linux) || defined(ibm032) || defined(__osf__) || \
     defined(ISC) || defined(SGI) || defined(USE_EMX)
#  include <sys/time.h>
# endif

# if !defined(sgi) && !defined(ultrix)
#  include <sys/timeb.h>
# endif

#endif


#include <time.h>



#ifdef MACINTOSH
# include <unix.h>
#endif

#if defined(WINDOWS) || defined(MSDOS) || defined(USE_EMX)
# include <io.h>
# ifndef WIN32
#  include <pwd.h>
#  include <unistd.h>
# endif
#endif

#ifdef AMIGA
# include <pwd.h>
#endif

#if !defined(MACINTOSH) && !defined(AMIGA) && \
    !defined(ACORN) && !defined(VM)
# if defined(__TURBOC__) || defined(__WATCOMC__)
#  include <mem.h>
# else
#  include <memory.h>
# endif
#endif

#if !defined(__MWERKS__) && !defined(ACORN)
# include <fcntl.h>
#endif


#ifdef SET_UID

# ifndef USG
#  include <sys/param.h>
#  include <sys/file.h>
# endif

# ifdef linux
#  include <sys/file.h>
# endif

# include <pwd.h>

# include <unistd.h>

# include <sys/stat.h>

# if defined(SOLARIS)
#  include <netdb.h>
# endif

#endif


#ifdef SET_UID

# ifdef USG
#  include <string.h>
# else
#  include <strings.h>
extern char *strstr();
extern char *strchr();
extern char *strrchr();
# endif

#else

# include <string.h>

#endif



#if !defined(linux) && !defined(__MWERKS__) && !defined(ACORN) && \
    !defined(__FreeBSD__)
extern long atol();
#endif


#include <stdarg.h>


#endif

