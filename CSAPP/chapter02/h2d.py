# -*- coding: UTF-8 -*-
__author__ = 'DXY'

import sys

for i in range(1, len(sys.argv)):
    val = int(sys.argv[i], 16)
    print "0x%x=%d" % (val, val)
