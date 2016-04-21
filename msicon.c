/*
 * msicon.c
 */

#include "msicon.h"
#include <tchar.h>
#include <locale.h>
#include <fcntl.h>

/*
 * The following function is a dummy one; replace it for
 * your C function definitions.
 */

ScmObj test_msicon(void)
{
    return SCM_MAKE_STR("msicon is working");
}


// set window icon
void set_window_icon(LPCTSTR classname, LPCTSTR windowname, LPCTSTR iconfilename) {
    HWND   hwnd;
    HANDLE icon;

#if 0
    // for printing wide characters
    int mode_old;
    _tsetlocale(LC_ALL, _T(""));
    fflush(stdout);
    mode_old = _setmode(_fileno(stdout), _O_TEXT);
    if (classname != NULL)    { _tprintf(_T("classname=%s\n"),    classname); }
    if (windowname != NULL)   { _tprintf(_T("windowname=%s\n"),   windowname); }
    if (iconfilename != NULL) { _tprintf(_T("iconfilename=%s\n"), iconfilename); }
    fflush(stdout);
    if (mode_old != -1) { _setmode(_fileno(stdout), mode_old); }
#endif

    // get window handle
    hwnd = FindWindow(classname, windowname);
    if (hwnd == NULL) { return; }
    //printf("hwnd=%d\n", hwnd);

    // load icon
    icon = LoadImage(NULL, iconfilename, IMAGE_ICON, 0, 0, LR_LOADFROMFILE);
    if (icon == NULL) { return; }
    //printf("icon=%d\n", icon);

    // set icon
    SendMessage(hwnd, WM_SETICON, ICON_SMALL, (LPARAM)icon);
    SendMessage(hwnd, WM_SETICON, ICON_BIG,   (LPARAM)icon);
}


/*
 * Module initialization function.
 */
extern void Scm_Init_msiconlib(ScmModule*);

void Scm_Init_msicon(void)
{
    ScmModule *mod;

    /* Register this DSO to Gauche */
    SCM_INIT_EXTENSION(msicon);

    /* Create the module if it doesn't exist yet. */
    mod = SCM_MODULE(SCM_FIND_MODULE("msicon", TRUE));

    /* Register stub-generated procedures */
    Scm_Init_msiconlib(mod);
}
