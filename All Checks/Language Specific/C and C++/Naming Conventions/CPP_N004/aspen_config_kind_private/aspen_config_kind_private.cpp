// Kind and consecutive capitals
class Kinds {
  public:
    void publicConsecutivECapitals() {}
    void publicNoConsecutiveCapitals() {}
  protected:
    void protectedConsecutivECapitals() {}
    void protectedNoConsecutiveCapitals() {}
  private:
    void privateConsecutivECapitals() {}   // UndCC_Violation
    void privateNoConsecutiveCapitals() {}
};
