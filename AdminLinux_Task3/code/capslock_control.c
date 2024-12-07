#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
  // Open capslock device for read-write access, returning a new file descriptor
  int nfd = open("/sys/class/leds/input3::capslock/brightness", O_RDWR);

  // Check if there is a command-line argument (argv[1])
  if (argv[1] != NULL)
    // Write the argument value to the file descriptor (nfd)
    dprintf(nfd,"%s\n", argv[1]);

  while(1);
  return 0;
}

