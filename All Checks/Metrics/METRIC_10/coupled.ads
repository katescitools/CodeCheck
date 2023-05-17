with Day1;
with Day2;
with Day3;
with Day4;
with Day5;
with Day6;
with Day7;

package Coupled is        -- /* UndCC_Violation when limit set to 5, package coupled with 7 others */

   monday    : Day1.Mon;
   tuesday   : Day2.Tue;
   wednesday : Day3.Wed;
   thursday  : Day4.Thu;
   friday    : Day5.Fri;
   saturday  : Day6.Sat;
   sunday    : Day7.Sun;

end Coupled;
