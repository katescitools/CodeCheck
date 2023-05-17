// Kind and consecutive capitals
class Kinds {
  public:
    void publicConsecutivECapitals() {}    // UndCC_Violation
    void publicNoConsecutiveCapitals() {}
  protected:
    void protectedConsecutivECapitals() {} // UndCC_Violation
    void protectedNoConsecutiveCapitals() {}
  private:
    void privateConsecutivECapitals() {}   // UndCC_Violation
    void privateNoConsecutiveCapitals() {}
};
