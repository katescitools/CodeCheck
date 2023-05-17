template <typename T> T myMax(T x, T y) // UNDCC_Valid
{         
  int b;                       // Valid if Delayed template parsing must be turned off 
  void static* a;              // Violation if Delayed template parsing must be turned off
  return (x > y)? x: y;
}

class Z
{
  typedef int hello();          // UNDCC_Valid
};

class Y : public Z
{
public:
  Y() {};                       // UNDCC_Valid
  virtual ~Y() = 0 {};          // UNDCC_Valid
  virtual void CMD() {};        // UNDCC_Valid
  int EX(int register g, int h)   // UNDCC_Violation - parameters are on by default, may be turned off
  {return 0;};
private:
  int mutable* a;               // UNDCC_Violation
};

int main()
{
  static int e = 5;             // UNDCC_Valid
  int thread_local* x = &e;     // UNDCC_Violation
  char static* i, j, z;         // UNDCC_Violation - only flagging i
}

