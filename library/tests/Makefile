tests: \
	logging_test_e \
	numlist_test_e \
	mkdir_obj_bin \
	mv_obj \
	mv_bin

logging_test_e: logging_test.o $(lib)
	$(CC) -o $@ $^ $(ext-libs)

numlist_test_e: numlist_test.o $(lib)
	$(CC) -o $@ $^ $(ext-libs)

mkdir_obj_bin:
	mkdir -p $(DEBUG_DIR) \
	      $(OBJ_DIR) \
	      $(BIN_DIR)

mv_obj:
	mv $(lib) *.o  $(OBJ_DIR)

mv_bin:
	mv *test_e $(BIN_DIR)
