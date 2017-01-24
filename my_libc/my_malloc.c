#include <stdio.h>

typedef long Align; /* for aling to long boundary */

union header{ /* block`s header */
  struct{
    union header *ptr; /* next block */
    unsigned size; /* block`s size */
  } s;
  Align x; /* forced block`s align */
};

typedef union header Header;

static Header base; /* empty list for start */
static Header *freep = NULL;

#define NALLOC 1024 /* min count of blocks */

void *my_malloc(unsigned nbytes);
void free(void *ap);
static Header *morecore(unsigned nu);


int main(){
  printf("My malloc()\n");
  int *arr = (int *)my_malloc(10 * sizeof(int));
  arr[0] = 10;
  printf("%i\n", arr[0]);
  arr[1] = 20;
  printf("%i\n", arr[1]);
  arr[9] = 90;
  printf("%i\n", arr[9]);

  return 0;
}

/* malloc: function for destribution of memory */
void *my_malloc(unsigned nbytes){
  Header *p; /* current block */
  Header *prevp; /* previous block */
  Header *morecore(unsigned);
  unsigned nunits;

  nunits = (nbytes + sizeof(Header) - 1)/sizeof(Header) + 1; /* count of blocks */

  if((prevp = freep) == NULL){ /* list is not exist */
    base.s.ptr = freep = prevp = &base;
    base.s.size = 0;
  }

  for(p = prevp->s.ptr; ; prevp = p, p = p->s.ptr){
    if(p->s.size >= nunits){ /* size is enough*/
      if(p->s.size == nunits) /* if sizes are equally */
        prevp->s.ptr = p->s.ptr;
      else { /* if size is more then delete tail */
        p->s.size -= nunits;
        p += p->s.size;
        p->s.size = nunits;
      }
      freep = prevp;
      return (void *)(p+1);
    }
    if(p == freep)
      if((p = morecore(nunits)) == NULL)
        return NULL; /* not enough memory */
  }
}

/* morecore: memory request from the system */
static Header *morecore(unsigned nu){
  char *cp, *sbrk(int);
  Header *up;

  if(nu < NALLOC)
    nu = NALLOC;
  cp = sbrk(nu * sizeof(Header));
  if(cp == (char *) -1)
    return NULL;
  up = (Header *) cp;
  up->s.size = nu;
  free((void *)(up+1));
  return freep;
}

/* free: add block to list of empty blocks */
void free(void *ap){
  Header *bp, *p;

  bp = (Header *)ap - 1; /* pointer to header */
  for(p = freep; !(bp > p && bp < p->s.ptr); p = p->s.ptr)
    if(p >= p->s.ptr && (bp > p || bp < p->s.ptr))
      break;

  if(bp + bp->s.size == p->s.ptr){
    bp->s.size += p->s.ptr->s.size;
    bp->s.ptr = p->s.ptr->s.ptr;
  } else
    bp->s.ptr = p->s.ptr->s.ptr;

  if(p + p->s.size == bp){
    p->s.size = bp->s.size;
    p->s.ptr = bp->s.ptr;
  } else
    p->s.ptr = bp;
  freep = p;
}
