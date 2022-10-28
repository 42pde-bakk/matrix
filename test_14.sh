make -j || exit 1

DISPLAY_FOLDER=resources/matrix_display_linux

./debug/bin/ex14 > $DISPLAY_FOLDER/proj

cd $DISPLAY_FOLDER || exit 1

./display
