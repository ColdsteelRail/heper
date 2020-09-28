tests: \
	logging_test_e \
	numlist_test_e \
	mv_obj \
	mv_bin

logging_test_e: logging_test.o $(lib)
	$(CC) -o $@ $^ $(ext-libs)

numlist_test_e: numlist_test.o $(lib)
	$(CC) -o $@ $^ $(ext-libs)
mv_obj:
	mv $(lib) *.o  $(OBJ_DIR)

mv_bin:
	mv *test_e $(BIN_DIR)
