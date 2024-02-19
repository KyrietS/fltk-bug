# Bug reproduction

Eaach call to fl_height(int, int) decreases the size of a current font when scale is set to 1.25

**IMPORTANT**: 

Set Windows display scale to 125% to reproduce the bug.

Right click on desktop -> Display settings -> Scale and layout -> 125%

## Build
```
git clone git@github.com:KyrietS/fltk-bug.git

cd fltk-bug

cmake -S . -B build
cmake --build build
```
