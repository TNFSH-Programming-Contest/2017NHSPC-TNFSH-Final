#!/usr/bin/env python3
import os
from sys import argv
import filecmp

exe = argv[1]
files = os.listdir()
files.sort()
for f in files:
	if f.endswith('.in'):
		os.system("%s < %s > /tmp/judge.out"%(exe,f))
		if filecmp.cmp("/tmp/judge.out","%s.out"%(f[:-3])):
			print("testdata %s: AC"%(f[:-3]))
		else:
			print("testdata %s: <<<<<WA>>>>>"%(f[:-3]))
