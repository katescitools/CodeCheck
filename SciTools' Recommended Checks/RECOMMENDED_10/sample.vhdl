-- This program was written by ChatGPT
-- This program checks if a given number is a prime number

entity prime_check is
  port (
    num : in integer range 2 to 9999; -- input number from user
    is_prime : out boolean         -- output indicating whether the number is prime or not
  );
end entity prime_check;

architecture behavioral of prime_check is
  signal i : integer := 2; -- counter for checking prime condition
  signal is_divisible : boolean := false; -- flag to track if num is divisible by i

begin
  process(num)
  begin
    is_prime <= true; -- initialize is_prime to true, assume num is prime

    while i < num loop -- loop through all numbers from 2 to num-1
      if num mod i = 0 then -- if num is divisible by i, then it is not a prime number
        is_divisible <= true;
        is_prime <= false;
        exit; -- exit the loop
      end if;
      i <= i + 1; -- increment i for next iteration
    end loop;

    if not is_divisible then -- if num is not divisible by any number between 2 and num-1, then it is a prime number
      is_prime <= true;
    end if;
  end process;
end architecture behavioral;
