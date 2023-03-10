module LeapYear (isLeapYear) where

isLeapYear :: Integer -> Bool
isLeapYear year = ((mod year 4) == 0) && not ((mod year 100) == 0) || ((mod year 400) == 0)

main = do
    print(isLeapYear 2000)
    print(isLeapYear 2100)
    print(isLeapYear 2200)