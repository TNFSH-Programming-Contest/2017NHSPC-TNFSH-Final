@echo off
del problem.inc.synctex problem.en.log
xelatex problem.en.tex
xelatex problem.en.tex
pause