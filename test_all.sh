#!/usr/bin/env bash

make -j

BIN_FOLDER="./debug/bin"

for i in $(seq -w 0 14);
do
  "${BIN_FOLDER}/ex${i}" || exit 1
done
