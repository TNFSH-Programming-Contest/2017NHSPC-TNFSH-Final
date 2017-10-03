#!/usr/bin/env python3
import os
from sys import argv
import filecmp

exe = argv[1]
files = os.listdir()
files.sort()
for f in files:
	if f.endswith('.in'):
		print("%s < %s > %s.out"%(exe,f,f[:-3]))
		os.system("%s < %s > %s.out"%(exe,f,f[:-3]))
