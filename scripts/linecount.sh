#!/bin/bash
cd ../
find . -regex ".*\.\(h\|cpp\)" | xargs wc -l 