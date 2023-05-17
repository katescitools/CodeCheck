// Kind and consecutive capitals
class Kinds {
  public:
    enum publicConsecutivECapitals {};
    enum publicNoConsecutiveCapitals {};
  protected:
    enum protectedConsecutivECapitals {};
    enum protectedNoConsecutiveCapitals {};
  private:
    enum privateConsecutivECapitals {};   // UndCC_Violation
    enum privateNoConsecutiveCapitals {};
};
