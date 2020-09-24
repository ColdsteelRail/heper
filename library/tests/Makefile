tests: test_log

test_log: test_log.o ../cpuinfo.o ../version.o ../logging.o
	$(CC) -o $@ $^

clean:
	rm -rf *.o ../*.o test_log *.log
