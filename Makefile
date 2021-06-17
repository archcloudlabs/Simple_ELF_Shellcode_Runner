all:
	mkdir -p ./bin/
	gcc -m32 simple-elf-runner.c -o ./bin/evil-elf.bin 
	gcc -m32 simple-elf-runner.c -o ./bin/evil-elf-strip.bin && strip ./bin/evil-elf-strip.bin
