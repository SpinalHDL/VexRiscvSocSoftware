/*
Created by: roman3017
Inspired by: https://jacobmossberg.se/posts/2018/08/11/run-c-program-bare-metal-on-arm-cortex-m3.html
*/

extern unsigned int __global_pointer$;
extern unsigned int _stack_start;
extern unsigned int _bss_start;
extern unsigned int _bss_end;
extern unsigned int _ctors_start;
extern unsigned int _ctors_end;

void crtStart();
void irqCallback();
void main();

static void trapEntry();
static void bssInit();
static void ctorsInit();

unsigned int * initVectors[2] __attribute__ ((section("vectors"))) = {
  (unsigned int *) crtStart,    // code entry
  (unsigned int *) trapEntry,   // trap entry
};

void crtStart()
{
  /* Initialize sp and gp registers */
  asm volatile (
    "la gp, %0\n\t"
    "la sp, %1\n\t"
    :: "i"(&__global_pointer$), "i"(&_stack_start)
  );

  bssInit();
  ctorsInit();
  main();
  asm volatile("j .");
}

static void trapEntry()
{
  irqCallback();
}

static void bssInit()
{
  unsigned int * bss_start_p = &_bss_start; 
  unsigned int * bss_end_p = &_bss_end;
  while(bss_start_p != bss_end_p) {
    *bss_start_p++ = 0;
  }
}

static void ctorsInit()
{
  unsigned int * ctors_start_p = &_ctors_start;
  unsigned int * ctors_end_p = &_ctors_end;
  void(*ctor)(); 
  while(ctors_start_p != ctors_end_p) {
    ctor = (void *)*ctors_start_p++;
    ctor();
  }
}
