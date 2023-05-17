// Kind and consecutive capitals
class Kinds {
  public:
    enum publicConsecutivECapitals {};    // UndCC_Violation
    enum publicNoConsecutiveCapitals {};
  protected:
    enum protectedConsecutivECapitals {};
    enum protectedNoConsecutiveCapitals {};
  private:
    enum privateConsecutivECapitals {};
    enum privateNoConsecutiveCapitals {};
};
