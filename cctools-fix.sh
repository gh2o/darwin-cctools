#!/bin/sh

cd "`dirname "$0"`"
cd cctools
find . -name \*.c -o -name \*.h | xargs sed -i -e 's/#import/#include/g'
