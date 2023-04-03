file = main

execute:
	clang $(file).c -o $(file)
	$(file)