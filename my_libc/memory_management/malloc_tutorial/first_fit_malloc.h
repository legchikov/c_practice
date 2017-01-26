#include <unistd.h>

#define ALIGNTO 2U /* power of 2: 2, 4, 8, 16, 32...*/
#define ALIGN(len) ( ((len) + ALIGNTO - 1) & ~(ALIGNTO - 1) )
#define ALIGN4(x) ( ((((x) - 1) >> 2) << 2) + 4 ) /* align to 4: 4, 8, 12, 16, 20.... */
#define BLOCK_SIZE 12

typedef struct s_block *t_block;

struct s_block{
  size_t size;
  t_block next;
  int free;
  char data[1];
};

void *base = NULL;

void *first_fit_malloc(size_t size);
t_block find_block(t_block *last, size_t size);
t_block extend_heap(t_block last, size_t s);
void split_block(t_block b, size_t s);

void *first_fit_malloc(size_t size) {
  t_block b, last;
  size_t s;
  s = ALIGN4(size);

  if(base) {
    /* first find a block */
    last = base;
    b = find_block(&last, s);
    if(b) {
      /* can we split */
      if((b->size - s) >= (BLOCK_SIZE + 4))
        split_block(b, s);
      b->free = 0;
    } else {
      /* no fitting block, extend heap */
      b = extend_heap(last, s);
      if(!b)
        return NULL;
    }
  } else {
    /* first time */
    b = extend_heap(NULL, s);
    if(!b)
      return NULL;
    base = b;
  }
  return b->data;
}

t_block find_block(t_block *last, size_t size) {
  t_block b = base; // base is point to start of heap
  while(b && (b->free && b->size > size)) {
    *last = b;
    b = b->next;
  }
  return b;
}

t_block extend_heap(t_block last, size_t s) {
  t_block b;
  b = sbrk(0);
  if(sbrk(BLOCK_SIZE + s) == (void*)-1)
    /* sbrk() fails */
    return NULL;
  b->size = s;
  b->next = NULL;
  if(last)
    last->next = b;
  b->free = 0;
  return b;
}

void split_block(t_block b, size_t s) {
  t_block new;
  new = (t_block)(b->data + s);
  new->size = b->size - s + BLOCK_SIZE;
  new->next = b->next;
  new->free = 1;
  b->size = s;
  b->next = new;
}
