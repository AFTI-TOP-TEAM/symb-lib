#!/bin/bash
find ../ -regex ".*\.\(h\|cpp\|c\|hpp\)" | while read i; do clang-format -i -style=WebKit $i; done