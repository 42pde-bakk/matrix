#!/usr/bin/env bash
cd ..

for filename in *.cpp; do
  NEW_FILENAME="ex15/${filename}"
  TEMP_FILE="/tmp/peer_matrix_tmp.cpp"
  rm -f "${NEW_FILENAME}"
  sed '0,/^$/ s/^$/\n#include <complex>\nusing namespace std::complex_literals;\n/' "${filename}" > "${NEW_FILENAME}"
#  sed 's/<float>/<std::complex<float> >/g' "${TEMP_FILE}" > "${NEW_FILENAME}"
#  sed -e 's/:\(\d+\)/:\if/g' "${TEMP_FILE}" > "${NEW_FILENAME}"
done
