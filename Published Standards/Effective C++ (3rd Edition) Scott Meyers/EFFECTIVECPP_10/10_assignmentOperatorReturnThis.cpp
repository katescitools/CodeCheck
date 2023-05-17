class Okay1 {
public:
  Okay1 &operator=(const Okay1 &rhs) {
    return *this;
  }
};

// Parameter is not const.
class Violation1 {
public:
  Violation1 &operator=(Violation1 &rhs) { // UndCC_Violation
    return *this;
  }
};

// Return type is const.
class Violation2 {
public:
  const Violation2 &operator=(const Violation2 &rhs) { // UndCC_Violation
    return *this;
  }
};

// Return type is void.
class Violation3 {
public:
  void operator=(const Violation3 &rhs) { // UndCC_Violation
    return *this;
  }
};

// Returns non-this.
class Violation4 {
public:
  Violation4 &operator=(const Violation4 &rhs) {
    return 0; // UndCC_Violation
    return; // UndCC_Violation
    return rhs; // UndCC_Violation
  }
};
