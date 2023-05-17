// Kind and consecutive capitals
class Kinds {
  public:
    void publicConsecutivECapitals() {}
    void publicNoConsecutiveCapitals() {}
  protected:
    void protectedConsecutivECapitals() {} // UndCC_Violation
    void protectedNoConsecutiveCapitals() {}
  private:
    void privateConsecutivECapitals() {}
    void privateNoConsecutiveCapitals() {}
};
