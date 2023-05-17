class Test {

  public:
    Test( int x, int y, int level);
    virtual ~Test( );

    int getX( ) const;
    int getY( ) const;
    float getLevel( ) const;
    void setPosition( int x, int y );

    int a;    // UndCC_Violation
    float b;  // UndCC_Violation
    bool no;  // UndCC_Violation

  protected:
    int mX;        // UndCC_Valid - allowed by option
    int mY;        // UndCC_Valid - allowed by option
    float mLevel;  // UndCC_Valid - allowed by option
    bool yes;      // UndCC_Valid - allowed by option

  private:
    int x;
    int y;
    float yLevel;
    bool good;
};
