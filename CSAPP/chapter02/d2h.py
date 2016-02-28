# -*- coding: UTF-8 -*-
__author__ = 'DXY'

import sys

for i in range(1, len(sys.argv)):
    print "%d=0x%x" % (int(sys.argv[i]), int(sys.argv[i]))


