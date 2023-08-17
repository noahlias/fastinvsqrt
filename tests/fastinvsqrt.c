
float fastInvSqrt(float x) {
  float half = 0.5f * x;
  int i = *(int*)&x;         // evil floating point bit level hacking
  i = 0x5f3759df - (i >> 1);  // what the fuck?
  x = *(float*)&i;
  x = x*(1.5f-(half*x*x));
  return x;
}

int main(){
    for(int i = 0; i <1000000; i++){
        fastInvSqrt(25.0);
    }
    return 0;
}