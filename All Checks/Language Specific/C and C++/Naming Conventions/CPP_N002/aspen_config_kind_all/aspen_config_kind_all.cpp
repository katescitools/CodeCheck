// Kind and consecutive capitals
class Kinds {
  public:
    enum publicConsecutivECapitals {};    // UndCC_Violation
    enum publicNoConsecutiveCapitals {};
  protected:
    enum protectedConsecutivECapitals {}; // UndCC_Violation
    enum protectedNoConsecutiveCapitals {};
  private:
    enum privateConsecutivECapitals {};   // UndCC_Violation
    enum privateNoConsecutiveCapitals {};
};
