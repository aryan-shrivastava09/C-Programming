#include <stdio.h>
#include <stdlib.h>
//I've provided "min" and "max" functions in
//case they are useful to you
int min (int a, int b) {
  if (a < b) {
    return a;
  }
  return b;
}
int max (int a, int b) {
  if (a > b) {
    return a;
  }
  return b;
}

typedef struct rect
{int x,y,width,height;}//Declare your rectangle structure here!
rectangle;

rectangle canonicalize(rectangle r) {
  //WRITE THIS FUNCTIOn
  if(r.width<0)
    {r.x=r.x+r.width;
      r.width =-r.width;}
  if(r.height<0)
    {r.y=r.y+r.height;
      r.height=-r.height;}
  return r;}

rectangle intersection(rectangle r1, rectangle r2) {
  rectangle r,ra,rb,rp,rq;
  ra=canonicalize(r1);
  rb=canonicalize(r2);
  if(ra.x<rb.x)
    {rp=ra;
    }
  else
    rp=rb;
  if(ra.y<rb.y)
    rq=ra;
  else
    rq=rb;
  if(((ra.x>=rb.x&&ra.x<=(rb.x+rb.width))&&((rb.y>=ra.y&&rb.y<=(ra.y+ra.height))||(ra.y>=rb.y&&ra.y<=(rb.y+rb.height))))||((rb.x>=ra.x&&rb.x<=(ra.x+ra.width))&&((ra.y>=rb.y&&ra.y<=(rb.y+rb.height))||(rb.y>=ra.y&&rb.y<=(ra.y+ra.height)))))
    { r.x=max(ra.x,rb.x);
      r.y=max(ra.y,rb.y);
      if(((ra.x>=rb.x&&(ra.x+ra.width)<=(rb.x+rb.width))||(rb.x>=ra.x&&(rb.x+rb.width)<=(ra.x+ra.width)))&&((ra.y>=rb.y&&(ra.y+ra.height)<=(rb.y+rb.height))||(rb.y>=ra.y&&(rb.y+rb.height)<=(ra.height+ra.y))))
	{r.width=min(ra.width,rb.width);
	  r.height=min(ra.height,rb.height);}
      else
	{r.width=rp.x+rp.width-r.x;
	  r.height=rq.y+rq.height-r.y;}}
  else{r.x=0;
    r.y=0;
    r.width=0;
    r.height=0;
  }
  return r;
}

//You should not need to modify any code below this line
void printRectangle(rectangle r) {
  r = canonicalize(r);
  if (r.width == 0 && r.height == 0) {
    printf("<empty>\n");
  }
  else {
    printf("(%d,%d) to (%d,%d)\n", r.x, r.y, 
	                           r.x + r.width, r.y + r.height);
  }
}

int main (void) {
  rectangle r1;
  rectangle r2;
  rectangle r3;
  rectangle r4;

  r1.x = 2;
  r1.y = 3;
  r1.width = 5;
  r1.height = 6;
  printf("r1 is ");
  printRectangle(r1);

  r2.x = 4;
  r2.y = 5;
  r2.width = -5;
  r2.height = -7;
  printf("r2 is ");
  printRectangle(r2);
  
  r3.x = -2;
  r3.y = 7;
  r3.width = 7;
  r3.height = -10;
  printf("r3 is ");
  printRectangle(r3);

  r4.x = 0;
  r4.y = 7;
  r4.width = -4;
  r4.height = 2;
  printf("r4 is ");
  printRectangle(r4);

  //test everything with r1
  rectangle i = intersection(r1,r1);
  printf("intersection(r1,r1): ");
  printRectangle(i);

  i = intersection(r1,r2);
  printf("intersection(r1,r2): ");
  printRectangle(i);
  
  i = intersection(r1,r3);
  printf("intersection(r1,r3): ");
  printRectangle(i);

  i = intersection(r1,r4);
  printf("intersection(r1,r4): ");
  printRectangle(i);

  //test everything with r2
  i = intersection(r2,r1);
  printf("intersection(r2,r1): ");
  printRectangle(i);

  i = intersection(r2,r2);
  printf("intersection(r2,r2): ");
  printRectangle(i);
  
  i = intersection(r2,r3);
  printf("intersection(r2,r3): ");
  printRectangle(i);

  i = intersection(r2,r4);
  printf("intersection(r2,r4): ");
  printRectangle(i);

  //test everything with r3
  i = intersection(r3,r1);
  printf("intersection(r3,r1): ");
  printRectangle(i);

  i = intersection(r3,r2);
  printf("intersection(r3,r2): ");
  printRectangle(i);
  
  i = intersection(r3,r3);
  printf("intersection(r3,r3): ");
  printRectangle(i);

  i = intersection(r3,r4);
  printf("intersection(r3,r4): ");
  printRectangle(i);

  //test everything with r4
  i = intersection(r4,r1);
  printf("intersection(r4,r1): ");
  printRectangle(i);

  i = intersection(r4,r2);
  printf("intersection(r4,r2): ");
  printRectangle(i);
  
  i = intersection(r4,r3);
  printf("intersection(r4,r3): ");
  printRectangle(i);

  i = intersection(r4,r4);
  printf("intersection(r4,r4): ");
  printRectangle(i);


  return EXIT_SUCCESS;

}
