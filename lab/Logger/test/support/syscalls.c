#include <stddef.h>
#include <stdint.h>
#include <sys/stat.h>

extern void print_uart0(const char);

// Linker script sets heap start and end
extern unsigned int  _HEAP_START;
extern unsigned int  _HEAP_END;

static caddr_t heap = NULL;


/*
 * Custom implementations of Newlib system calls for our emulated, embedded system.
 */


// File writes are limited to console output routed through serial port
int _write(int fd, const void *buf, size_t count) {
  size_t _count;
  for (_count = 0; _count < count; _count++) {
    print_uart0((const char)*(uint8_t*)buf++);
  }
  return count;
}

/*
 * Heap allocation for dynamic memory
 * Based on http://e2e.ti.com/support/archive/stellaris_arm/f/471/t/44452
 * Modifications from above:
 *  - Space and collisions checks updated for our memory layout
 */
caddr_t _sbrk ( unsigned int increment ) {
  caddr_t prevHeap;
  caddr_t nextHeap;
  
  if (heap == NULL) {
    // First allocation
    heap = (caddr_t)&_HEAP_START;
  }

  prevHeap = heap;
          
  // Always return data aligned on a 8 byte boundary 
  nextHeap = (caddr_t)(((unsigned int)(heap + increment) + 7) & ~7);        

  // Get current stack pointer 
  register caddr_t stackPtr asm ("sp");

  // Check enough space
  if (nextHeap >= (caddr_t)&_HEAP_END) {
    return NULL; // Error - no more memory 
  }
    
  // Check stack pointer isn't in heap space -- if it is, other bad things have surely already happened
  if (stackPtr > (caddr_t)&_HEAP_START) {
    return NULL; // Error - no more memory 
  }

  heap = nextHeap;
  return (caddr_t) prevHeap;    
}

void _exit (int status) {
  /*
   * We will never call stdlib exit()
   * But we need to convince the compiler that this function is `noreturn`
   */
  while(1);
}

// Stream processing not used: Effectively unimplemented
int _isatty(int fd) {
  return 1;
}

// File processing not used: Effectively unimplemented
int _lseek(int fd, int ptr, int dir) {
  return 0;
}

// File processing not used: Effectively unimplemented
int _read(int fd, char* ptr, int len) {
  return 0;
}

// File processing not used: Effectively unimplemented
int _fstat(int fd, struct stat* st) {
  st->st_mode = S_IFCHR;
  return 0;
}

// File processing not used: Effectively unimplemented
int _close(int fd) {
  return -1;
}
