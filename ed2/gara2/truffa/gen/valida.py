#!/usr/bin/env pypy

from limiti import *

import sys
import os

def usage():
    print >> sys.stderr, "Usage: %s file_input.txt [subtask_number]" % \
        os.path.basename(sys.argv[0])
    exit(1)


def run(f, st):
    assert( len(f) == 2 )
    N = int(f[0])
    assert( 1 <= N <= MAXN )
    riga = map(int, f[1].split())
    assert( len(riga) == N )
    assert( all([-MAXV <= r <= MAXV and r != 0 for r in riga]) )

if __name__ == "__main__":
    if len(sys.argv) < 2:
        usage()

    # Di default, ignora i subtask
    st = 0

    if len(sys.argv) == 3:
        st = int(sys.argv[2])

    f = open(sys.argv[1]).readlines()
    run(f, st)
