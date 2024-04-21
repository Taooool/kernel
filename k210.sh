#!/bin/bash
#cd $TOP/xv6-riscv
make clean
make run
rm $TOP/kernel
cp -p ./target/kernel $TOP/kernel
echo "k210.sh finished"
