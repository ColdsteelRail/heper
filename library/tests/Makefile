tests: test_log

test_log: test_log.o $(lib)
	$(CC) -o $@ $^

test_numlist: test_numlist.o $(lib)
	$(CC) -o $@ $^

clean:
	rm -rf *.o ../*.o test_log *.log
