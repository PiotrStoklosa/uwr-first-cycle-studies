#include <errno.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdnoreturn.h>
#include <string.h>
#include <sys/time.h>

extern uint64_t bitrev(uint64_t);

/* https://en.wikipedia.org/wiki/Xorshift#xorshift* */
static uint64_t random_u64(uint64_t *seed) {
  uint64_t x = *seed;
  x ^= x >> 12;
  x ^= x << 25;
  x ^= x >> 27;
  *seed = x;
  return x * 0x2545F4914F6CDD1DUL;
}

/* Only for testing. Such solution would get 0 points. */
static uint64_t bitrev_iter(uint64_t x) {
  uint64_t b, r = 0;
  for (int i = 0; i < 64; i++) {
    b = (x >> i) & 1;
    r |= b << (63 - i);
  }
  return r;
}

static void run(uint64_t arg) {
  uint64_t fast = bitrev(arg);
  uint64_t slow = bitrev_iter(arg);
  if (fast != slow) {
    printf("0x%016" PRIX64 " -> 0x%016" PRIX64 "\n", slow, fast);
    exit(EXIT_FAILURE);
  }
}

int main(int argc, char *argv[]) {
  if (argc == 2) {
    uint64_t arg = strtoul(argv[1], NULL, 16);
    if (errno)
      goto fail;
    run(arg);
    return EXIT_SUCCESS;
  }

  if (argc == 3) {
    if (strcmp("-r", argv[1]))
      goto fail;

    int times = strtol(argv[2], NULL, 10);
    if (times < 0)
      goto fail;

    struct timeval tv;
    gettimeofday(&tv, NULL);

    uint64_t seed = tv.tv_sec + tv.tv_usec * 1e6;

    for (int i = 0; i < times; i++)
      run(random_u64(&seed));

    return EXIT_SUCCESS;
  }

fail:
  fprintf(stderr, "Usage: %s [-r TIMES] [NUMBER]\n", argv[0]);
  return EXIT_FAILURE;
}
