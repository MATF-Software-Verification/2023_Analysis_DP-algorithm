lcov --capture --directory . -directory ../untitled --output-file pokrivenost.info --no-external
genhtml -o folder pokrivenost.info
