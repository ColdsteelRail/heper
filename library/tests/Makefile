tests: test_log

test_log: test_log.o $(lib)
	$(CC) -o $@ $^

clean:
	rm -rf *.o ../*.o test_log *.log
