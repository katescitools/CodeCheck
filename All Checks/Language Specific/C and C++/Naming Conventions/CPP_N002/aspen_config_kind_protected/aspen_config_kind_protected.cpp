// Kind and consecutive capitals
class Kinds {
  public:
    enum publicConsecutivECapitals {};
    enum publicNoConsecutiveCapitals {};
  protected:
    enum protectedConsecutivECapitals {}; // UndCC_Violation
    enum protectedNoConsecutiveCapitals {};
  private:
    enum privateConsecutivECapitals {};
    enum privateNoConsecutiveCapitals {};
};
