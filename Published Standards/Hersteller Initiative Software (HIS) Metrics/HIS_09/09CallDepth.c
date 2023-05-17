void validDepth1(){
}

void validDepth2(){
  validDepth1();
}

void validDepth3(){
  validDepth2();
}

void validDepth4(){
  validDepth3();
}

void invalidDepth1(){
  validDepth4();
}

void invalidDepth2(){
  invalidDepth2();
}