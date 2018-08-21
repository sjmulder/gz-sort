To build, open a command promt and:

    cd path\to\gz-sort
    vcvars64
    nmake /f win32\Makefile

To have a 'dist' directory created and all distribution files copied to it:

    nmake /f win32\Makefile dist

To clean up:

    nmake /f win32\Makefile clean

Ported bij Sijmen J. Mulder <ik@sjmulder.nl>.

