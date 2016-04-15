/*
 * msicon.h
 */

/* Prologue */
#ifndef GAUCHE_MSICON_H
#define GAUCHE_MSICON_H

#include <gauche.h>
#include <gauche/extend.h>

SCM_DECL_BEGIN

/*
 * The following entry is a dummy one.
 * Replace it for your declarations.
 */

extern ScmObj test_msicon(void);
extern void set_window_icon(LPCTSTR classname, LPCTSTR windowname, LPCTSTR iconfilename);

/* Epilogue */
SCM_DECL_END

#endif  /* GAUCHE_MSICON_H */
