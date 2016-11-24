#!/bin/sh
basepath=`pwd`

if [[ $# -ne 1 ]]
then
  echo "ERROR: Please name the build directory as the first parameter."
  exit -1
fi

builddir=${1}
cd ${builddir}

# clean existing coverage files
rm -rf ./coverage
mkdir coverage

for file in `find . -name "*.c.gc*"`
do
    rm -rf ${file}
done

# execute test
./example_unittest

# create gcov output
for file in `find . -name "*.c.o"`
do
    gcov ${file}
    mv *.gcov ./coverage/
done

# collect result files
for file in `find . -name "*.c.gc*"`
do
    mv ${file} ./coverage/
done
