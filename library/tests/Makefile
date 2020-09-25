tests: \
	logging_test_e \
	numlist_test_e

logging_test_e: logging_test.o $(lib)
	$(CC) -o $@ $^ $(ext-libs)

numlist_test_e: numlist_test.o $(lib)
	$(CC) -o $@ $^ $(ext-libs)

clean:
	rm -rf *.o ../*.o test_log *.log
