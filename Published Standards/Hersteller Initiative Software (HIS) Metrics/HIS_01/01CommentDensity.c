

void validCommentDensity1(){
  int a;  //comment 1
  int b;  /* commment 2 */
}

/*Preceeding comment
that spans
multiple lines */
void validCommentDensity2(){
  int a;
  int b;
}


void invalidCommentDensity1(){
  int a;
  int b;
}

void invalidCommentDensity2(){
  int a; //1 comment
  int b;
  int c;
  int d;
  int e;
  int f;
  int g;
}