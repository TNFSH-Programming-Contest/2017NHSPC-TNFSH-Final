#!/usr/bin/env python3
import os
from sys import argv

folder = argv[1]
os.chdir(folder)
files = os.listdir()
files.sort()
cnt = 1
for f in files:
	if f.endswith('.in'):
		print(f)
		os.rename(f, str(cnt)+".in")
		os.rename(f[:-3]+".out", str(cnt)+".out")
		cnt += 1
