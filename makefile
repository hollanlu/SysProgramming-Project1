subCipher: subCipher.o
	gcc subCipher.c -o subCipher
subCipher.o: subCipher.c

test: test1 test2 test3 test4 test5
test1:
	./subCipher feather 1 data.txt data.out
test2:
	./subCipher feather 2 data.out data.bak
test3:
	./subCipher keyword 1 data2.txt data2.out
test4:
	./subCipher keyword 2 data2.out data2.bak
test5:
	diff -s data.txt data.bak
	diff -s data2.txt data2.bak
